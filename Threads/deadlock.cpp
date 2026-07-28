#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex m1;
std::mutex m2;

void thread1() {
    // Lock m1 first
    std::lock_guard<std::mutex> lock1(m1);

    // Simulate some work so the other thread can lock m2
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // Now try to lock m2
    // If thread2 already locked m2 and is waiting for m1,
    // both threads will wait forever -> deadlock
    std::lock_guard<std::mutex> lock2(m2);

    std::cout << "thread1 done\n";
}

void thread2() {
    // Lock m2 first
    std::lock_guard<std::mutex> lock2(m2);

    // Simulate some work so the other thread can lock m1
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // Now try to lock m1
    // If thread1 already locked m1 and is waiting for m2,
    // both threads will wait forever -> deadlock
    std::lock_guard<std::mutex> lock1(m1);

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