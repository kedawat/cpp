// The diamond problem occurs in multiple inheritance when two parent classes inherit from the same base class, causing the derived class to contain two copies of that base and creating ambiguity. The standard solution in C++ is virtual inheritance, where the common base is inherited as virtual so the final class gets only one shared copy


#include <iostream>
using namespace std;

class A {
public:
    void show() {
        cout << "A\n";
    }
};

class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};

int main() {
    D obj;
    obj.show();   // works
}