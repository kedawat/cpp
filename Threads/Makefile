cxx = g++

CFLAGS = 
LDFLAGS = 

basicThread: basicThread.cpp
	$(cxx) $(CFLAGS) -o basicThread basicThread.cpp $(LDFLAGS)

mutexAndLockThread: mutexAndLockThread.cpp
	$(cxx) $(CFLAGS) -o mutexAndLockThread mutexAndLockThread.cpp $(LDFLAGS)


all: basicThread mutexAndLockThread

clean:
	del /f basicThread.exe 2>nul || true
	del /f mutexAndLockThread.exe 2>nul || true