#include <iostream>
using namespace std;


class Student{
    private:
        int id;
    
    public:
        Student(int i): id(i) {}

        Student& operator=(const Student& s){
            id = s.id;
            return *this;
        }

        void getId(){
            std::cout<<"Id:"<<id<<endl;
        }
};

int main(){
    Student s1(101);
    s1.getId();
    Student s2(202);
    s2.getId();
    s2 = s1;   // assignment operator

    s2.getId();
}