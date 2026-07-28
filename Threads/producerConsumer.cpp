#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::queue<int> q;                 // Shared buffer
std::mutex m;                      // Protects the queue
std::condition_variable cv;        // Used to wake up consumer
bool done = false;                 // Marks that producer has finished

void producer() {
    for (int i = 1; i <= 5; ++i) {
        {
            // Lock the queue while modifying it
            std::lock_guard<std::mutex> lock(m);
            q.push(i);
            std::cout << "Produced: " << i << '\n';
        }

        // Wake one waiting consumer
        cv.notify_one();
    }

    {
        // Mark production complete
        std::lock_guard<std::mutex> lock(m);
        done = true;
    }

    // Wake consumer so it can exit if queue is empty
    cv.notify_one();
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(m);

        // Wait until queue is not empty or producer is done
        cv.wait(lock, [] {
            return !q.empty() || done;
        });

        // If producer is finished and queue is empty, stop
        if (q.empty() && done) {
            break;
        }

        // Take one item from the queue
        int value = q.front();
        q.pop();

        // Unlock before doing non-critical work
        lock.unlock();

        std::cout << "Consumed: " << value << '\n';
    }
}

int main() {
    std::thread p(producer);
    std::thread c(consumer);

    p.join();
    c.join();
    return 0;
}