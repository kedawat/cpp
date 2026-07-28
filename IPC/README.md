# IPC Examples

This folder contains simple inter-process communication examples in C++.

## Included Example

- producerConsumerIPC.cpp - demonstrates shared memory and semaphores between a parent and child process.

## Build and Run

From this directory, compile the example with:

```bash
g++ producerConsumerIPC.cpp -o producerConsumerIPC
```

Then run it:

```bash
./producerConsumerIPC
```

## Notes

The example uses POSIX shared memory and semaphores, so it is best suited for Linux-like environments.
