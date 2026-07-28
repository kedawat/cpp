#include <iostream>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <fcntl.h>

// Shared data visible to both producer and consumer processes.
struct SharedData {
    int buffer;      // Single-slot buffer
    bool has_data;   // Tracks whether buffer currently contains valid data
};

int main() {
    // Create one shared memory region usable by both parent and child after fork().
    auto shm = static_cast<SharedData*>(
        mmap(nullptr, sizeof(SharedData),
             PROT_READ | PROT_WRITE,
             MAP_SHARED | MAP_ANONYMOUS, -1, 0)
    );

    // Check whether shared memory allocation succeeded.
    if (shm == MAP_FAILED) {
        std::cerr << "mmap failed\n";
        return 1;
    }

    // Initialize shared state.
    shm->buffer = 0;
    shm->has_data = false;

    // Semaphore that means "buffer is empty; producer may write".
    sem_t* empty = sem_open("/pc_empty", O_CREAT, 0666, 1);

    // Semaphore that means "buffer has data; consumer may read".
    sem_t* full  = sem_open("/pc_full",  O_CREAT, 0666, 0);

    // Check whether semaphores were created successfully.
    if (empty == SEM_FAILED || full == SEM_FAILED) {
        std::cerr << "sem_open failed\n";
        return 1;
    }

    // Create a child process. After this, we have two processes.
    pid_t pid = fork();

    if (pid < 0) {
        std::cerr << "fork failed\n";
        return 1;
    }

    if (pid == 0) {
        // Child process acts as producer.
        for (int i = 1; i <= 5; ++i) {
            sem_wait(empty);              // Wait until buffer becomes empty
            shm->buffer = i;              // Write item into shared memory
            shm->has_data = true;         // Mark that data is ready
            std::cout << "Produced: " << i << '\n';
            sem_post(full);               // Signal consumer that data is available
            sleep(1);                     // Slow down for easier observation
        }
        return 0;
    } else {
        // Parent process acts as consumer.
        for (int i = 1; i <= 5; ++i) {
            sem_wait(full);               // Wait until producer fills buffer
            if (shm->has_data) {
                std::cout << "Consumed: " << shm->buffer << '\n';
                shm->has_data = false;    // Mark buffer as empty again
            }
            sem_post(empty);              // Signal producer that buffer is free
        }

        // Wait for child process to finish.
        wait(nullptr);

        // Clean up semaphore objects.
        sem_close(empty);
        sem_close(full);
        sem_unlink("/pc_empty");
        sem_unlink("/pc_full");

        // Release shared memory.
        munmap(shm, sizeof(SharedData));
    }

    return 0;
}