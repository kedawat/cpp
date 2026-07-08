#include <iostream>
using namespace std;

class Complex{
    private:
        int real;
        int imag;
    public:
        Complex(int r, int i): real(r), imag(i){};

        Complex operator+(Complex& obj) {
            return Complex(real + obj.real, imag + obj.imag);
        }

        void display(){
            std::cout << real << " + " << imag << "i\n";
        }
};


int main() {
    Complex c1(2, 3), c2(4, 5);
    Complex c3 = c1 + c2;
    c3.display();
}