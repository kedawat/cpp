#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <cstddef>
#include "threadPool.hpp"


ThredPool::ThreadPool(): stop(false) {
    for (std::size_t i = 0; i < threadCount; ++i) {
            workers.emplace_back(
                [this]() {
                    for (;;) {
                        std::function<void()> task;

                        // 1. Acquire lock
                        {
                            std::unique_lock<std::mutex> lock(queueMutex);

                            // 2. Wait until there is work or we are stopping
                            condition.wait(lock, [this]() {
                                return stop || !tasks.empty();
                            });

                            // 3. If stopping and no tasks, exit
                            if (stop && tasks.empty()) {
                                return;
                            }

                            // 4. Pop one task
                            task = std::move(tasks.front());
                            tasks.pop();
                        }

                        // 5. Execute task outside lock
                        task();
                    }
                }
            );
        }

}

ThreadPool::~ThreadPool(){
     {
            std::unique_lock<std::mutex> lock(queueMutex);
            stop = true;
        }

        // Wake up all workers
        condition.notify_all();

        // Join all threads
        for (std::thread &t : workers) {
            if (t.joinable()) {
                t.join();
            }
        }

}

void enqueue(std::function<void()> task) {
    {
            std::unique_lock<std::mutex> lock(queueMutex);
            if (stop) {
                // In a production version, you’d throw or assert here
                return;
            }
            tasks.push(std::move(task));
        }
        // Notify one sleeping worker that new work is available
        condition.notify_one();
    }

}
