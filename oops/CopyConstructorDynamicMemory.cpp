#include <iostream>
#include <cstring>
using namespace std;

class Student {
    char* name;
    int* marks;

public:
    Student(const char* n, int m) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        marks = new int;
        *marks = m;
    }

    Student(const Student& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        marks = new int;
        *marks = *(other.marks);
    }

    Student& operator=(const Student& other) {
        if (this != &other) {
            delete[] name;
            delete marks;

            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);

            marks = new int;
            *marks = *(other.marks);
        }
        return *this;
    }

    void display() const {
        cout << "Name: " << name << ", Marks: " << *marks << endl;
    }

    ~Student() {
        delete[] name;
        delete marks;
    }
};

int main() {
    Student s1("Nilesh", 95);

    Student s2 = s1;   // copy constructor
    Student s3("Test", 50);
    s3 = s1;           // assignment operator

    s1.display();
    s2.display();
    s3.display();
}