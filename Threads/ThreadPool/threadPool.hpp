#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

class ThreadPool {
public:
    // Create a pool with the requested number of worker threads.
    explicit ThreadPool(std::size_t threadCount);
    ~ThreadPool();

    // Submit a task to be executed by one of the worker threads.
    void enqueue(std::function<void()> task);

private:
    std::vector<std::thread> workers;          // Worker threads owned by the pool.
    std::queue<std::function<void()>> tasks;   // Pending work items.

    std::mutex queueMutex;                     // Guards access to the task queue.
    std::condition_variable condition;         // Allows workers to wait for new tasks.
    bool stop;                                  // Signals shutdown to the workers.
};