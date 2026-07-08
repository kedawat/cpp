#include <iostream>
#include <vector>
using namespace std;


class Shape{
    public:
        virtual void draw() = 0;
        virtual ~Shape() = default;
};

class Circle: public Shape{
    public:
        void draw() override{
            std::cout << "Drawing Circle\n";
        }
};

class Rectangle: public Shape{
    public:
        void draw() override{
            std::cout << "Drawing Rectangle\n";
        }
};

int main(){
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle());
    shapes.push_back(new Rectangle());

    for (Shape* s : shapes) {
        s->draw();  // dynamic dispatch: calls Circle::draw or Rectangle::draw
    }

    for (Shape* s : shapes) {
        delete s;   // clean up
    }
    return 0;
}






