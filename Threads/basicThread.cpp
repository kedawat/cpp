#include <iostream>
#include <thread>

void chef_task() {
    std::cout << "Chef 2 is preparing the ingredients...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate time taken to prepare ingredients
    std::cout << "Chef 2 has finished preparing the ingredients.\n";
}

int main() {
    std::cout << "Main thread(Chef 1) starting...\n";

    // Create a thread for Chef 2 to prepare the ingredients
    std::thread chef2(chef_task);

    std::cout << "Chef 1 is cooking the main dish...\n";

    // Wait for Chef 2 to finish before exiting the main thread
    chef2.join();

    std::cout << "Main thread(Chef 1) is exiting...\n";
    return 0;
}