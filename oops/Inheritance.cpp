#include <iostream>
using namespace std;

class Base{
    public:
        void show(){
            cout<<"Base\n";
        }
};

class Derived: public Base{
    public:
        void show(){
            cout<<"Derived\n";
        }
};

int main(){
    Base b1;
    Derived d1;
    b1.show();
    d1.show();
}