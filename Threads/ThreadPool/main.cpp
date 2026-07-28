#include <iostream>
#include "threadPool.hpp"

int main() {
    // Create a small pool of worker threads.
    ThreadPool pool(4);

    // Submit several tasks and let the pool distribute them.
    for (int i = 0; i < 8; ++i) {
        pool.enqueue([i]() {
            std::cout << "Task " << i << " running on thread "
                      << std::this_thread::get_id() << "\n";
        });
    }

    // The pool destructor waits for all worker threads to finish.
    return 0;
}