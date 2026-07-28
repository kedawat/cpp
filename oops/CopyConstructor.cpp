#include <iostream>

using namespace std;


class Student{
    private:
        int id;

    public:
    // Student(int id): id(id){}

    // Student(const Student& s){
    //     id = s.id;
    // }

    void getId(){
        cout<<"Id"<<id<<endl;
    }
};

int main(){
    Student s1(101);
    s1.getId();
    Student s2 = s1;   // copy constructor
    s2.getId();
}
