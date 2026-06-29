# Threads

Examples of multithreading in C++ using `<thread>` and `<mutex>`.

## Files

| File | Description |
|------|-------------|
| `basicThread.cpp` | Basic thread creation and joining using `std::thread` |
| `mutexAndLockThread.cpp` | Thread synchronization using `std::mutex` and `std::lock_guard` |

## Compilation

```bash
# Individual files
g++ -o basicThread basicThread.cpp
g++ -o mutexAndLockThread mutexAndLockThread.cpp

# Using Makefile
make all
```

## Cleanup

```bash
make clean
```
