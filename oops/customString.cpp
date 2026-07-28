// A move constructor transfers ownership of the resource from a temporary object to a new object, while a move assignment operator transfers ownership to an already existing object after releasing its old resource. In both cases, the source object is left in a safe empty state, usually by setting its pointer to nullptr

// Why noexcept is used
// Move operations are usually marked noexcept because many standard library containers prefer move operations only when they are guaranteed not to throw exceptions.

#include <iostream>
#include <cstring>
using namespace std;

class CustomString{
    private:
        char *str;

    public:
        CustomString(const char *s){
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }

        // copy constructor
        CustomString(const CustomString& s){
            str = new char [strlen(s.str)+1];
            strcpy(str, s.str);
        }

        // copy assginment operator
        CustomString& operator=(const CustomString& s){
            if (this != &s){
                delete []str;
                str = new char [strlen(s.str)+1];
                strcpy(str, s.str);
            }
            return *this;
        }

        // move construcor
        CustomString(CustomString&& s) noexcept{
            str = s.str;
            s.str = nullptr; 
        }

        // move assignment operator
        CustomString& operator=(CustomString&& s) noexcept {
            if (this != &s){
                delete []str;
                str = s.str;
                s.str = nullptr;
            }
            return *this;
        }



        void customSize(){
            std::cout<<"Size:"<<strlen(this->str)<<endl;
        }

        ~CustomString() {
            delete[] str;
        }

        void display(){
            if (str)
                cout << "String: " << str << endl;
            else
                cout << "String: null" << endl;
        }

};


int main(){
    CustomString s1("Nilesh");
    CustomString s2 = s1;
    CustomString s3("Atharv");

    s1.display();
    s2.display();
    s3.display();
    s3 = s1;

    s1.display();
    s2.display();
    s3.display();

    s1.customSize();

    CustomString s4 = std::move(s1);   // move constructor
    s3 = std::move(s2);                // move assignment

    s3.display();
    s4.display();
    s1.display();
    s2.display();
}