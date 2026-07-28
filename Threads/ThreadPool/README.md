# Thread Pool Example

This directory contains a small C++ thread-pool implementation that demonstrates how worker threads can be managed with a task queue.

## Files

- threadPool.hpp - class declaration for the thread pool.
- threadPool.cpp - implementation of worker-thread management and task dispatch.
- main.cpp - example usage that submits several tasks to the pool.

## Build and Run

Compile the example with:

```bash
g++ main.cpp threadPool.cpp -o threadPoolDemo -pthread
```

Run it:

```bash
./threadPoolDemo
```

## Notes

The example uses standard C++ threading primitives such as std::thread, std::mutex, and std::condition_variable.
