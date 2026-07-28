#include <iostream>
#include <thread>
#include <mutex>


// Shared mutex used to protect the shared counter
std::mutex m;

// Shared data accessed by multiple threads
int counter = 0;

// This function is executed by each thread
void worker() {
    for (int i = 0; i < 100000; ++i) {
        // lock_guard acquires the mutex here
        // and releases it automatically when it goes out of scope
        std::lock_guard<std::mutex> lock(m);

        // Critical section:
        // only one thread at a time can update counter
        ++counter;
    }
}

int main() {
    // Create two threads running the same worker function
    std::thread t1(worker);
    std::thread t2(worker);

    // Wait for both threads to complete
    t1.join();
    t2.join();

    // Print the final value of counter
    std::cout << "Final counter = " << counter << '\n';
    return 0;
}