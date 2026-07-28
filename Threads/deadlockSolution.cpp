#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex m1, m2;


void thread1(){
    std::lock(m1, m2);

    std::lock_guard<std::mutex> lock1(m1, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(m2, std::adopt_lock);

    
    std::cout<<"thred1 done"<<std::endl;
}

void thread2() {
    // Lock both mutexes at the same time without deadlock
    std::lock(m1, m2);

    // Take ownership of the already-locked mutexes
    std::lock_guard<std::mutex> lock1(m1, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(m2, std::adopt_lock);

    std::cout << "thread2 done\n";
}

int main() {
    std::thread t1(thread1);
    std::thread t2(thread2);

    // Wait for both threads to finish
    t1.join();
    t2.join();

    return 0;
}