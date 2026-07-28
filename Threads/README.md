# Threads

Examples of multithreading in C++ using `<thread>`, `<mutex>`, and related synchronization primitives.

## Files

| File or Folder | Description |
|------|-------------|
| `basicThread.cpp` | Basic thread creation and joining using `std::thread` |
| `mutexAndLockThread.cpp` | Thread synchronization using `std::mutex` and `std::lock_guard` |
| `mutexAndLockThread1.cpp` | Another mutex-based example with a slightly different pattern |
| `conditionalVariable.cpp` | Demonstrates thread coordination with `std::condition_variable` |
| `producerConsumer.cpp` | Producer-consumer example using threads and synchronization |
| `deadlock.cpp` | Example showing a classic deadlock scenario |
| `deadlockSolution.cpp` | Demonstrates how to avoid deadlock with ordering or locking strategy |
| `example.cpp` | Small thread example for learning purposes |
| `ThreadPool/` | Contains a simple thread-pool implementation with task queueing |

## Compilation

```bash
# Individual files
g++ -o basicThread basicThread.cpp
g++ -o mutexAndLockThread mutexAndLockThread.cpp

g++ -o conditionalVariable conditionalVariable.cpp -pthread

g++ -o producerConsumer producerConsumer.cpp -pthread

# Using Makefile
make all
```

## Cleanup

```bash
make clean
```

## Notes

Some examples are intended for learning and debugging thread behavior, while the `ThreadPool` folder shows a more structured approach to managing worker threads.
