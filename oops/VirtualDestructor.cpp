// A virtual destructor is needed in a base class when objects are deleted through base-class pointers. It ensures proper polymorphic destruction: the derived destructor runs first, then the base destructor. Without it, deleting a derived object via a base pointer causes undefined behavior and may leak resources.

// Practical rule
// If a class has any virtual function and is intended to be used as a base class, make its destructor virtual too. That is the standard safe practice

#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() {
        cout << "Base destructor\n";
    }
};

class Derived : public Base {
public:
    ~Derived() {
        cout << "Derived destructor\n";
    }
};

int main() {
    Base* p = new Derived();
    delete p;
}