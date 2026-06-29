#include <iostream>
#include <thread>
#include <mutex> // Required for locks

int total_tasks_done = 0; 
std::mutex kitchen_lock; // The physical key

void do_work() {
    for (int i = 0; i < 1000; ++i) {
        // 'lock_guard' grabs the key right here. 
        // If the other thread already has it, this thread pauses and waits.
        std::lock_guard<std::mutex> lock(kitchen_lock); 
        
        total_tasks_done++; // Safely inside the "critical section"
        
        // When 'lock' goes out of scope at the end of the loop iteration, 
        // it automatically returns the key!
    }
}

int main() {
    std::thread t1(do_work);
    std::thread t2(do_work);

    t1.join();
    t2.join();

    // Now it will ALWAYS perfectly print 2000!
    std::cout << "Total tasks done: " << total_tasks_done << std::endl;
    return 0;
}