#include <iostream>
#include <string>
#include <cmath>

struct BoundingBoxDimensions {
    double width;
    double height;
};

class Shape {
public:
    virtual double square() = 0;
    virtual BoundingBoxDimensions dimensions() = 0;
    virtual std::string type() = 0;
    static void printParams(Shape *shape) {
        std::cout << "Type: " << shape->type() << std::endl;
        std::cout << "Square: " << shape->square() << std::endl;
        std::cout << "Width: " << shape->dimensions().width << std::endl;
        std::cout << "Height: " << shape->dimensions().height << std::endl;
    }
};

class Circle : virtual public Shape {
private:
    double r;
public:
    Circle(double in_r) : r(in_r) {};
    double square() override {
        return 3.14*r*r;
    }
    std::string type() override {
        return "Circle";
    }
    BoundingBoxDimensions dimensions() override {
        BoundingBoxDimensions box;
        box.width = r*2;
        box.height = r*2;
        return box;
    }
};

class Rectangle : virtual public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double in_length, double in_width) : length(in_length), width(in_width) {};
    double square() override {
        return length*width;
    }
    std::string type() override {
        return "Rectangle";
    }
    BoundingBoxDimensions dimensions() override {
        BoundingBoxDimensions box;
        box.height = width;
        box.width = length;
        return box;
    }
};

class Triangle : virtual public Shape {
private:
    double a;
    double b;
    double c;
public:
    Triangle(double in_a, double in_b, double in_c) : a(in_a), b(in_b), c(in_c) {};
    double square() override {
        double p = (a+b+c) / 2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
    std::string type() override {
        return "Triangle";
    }
    BoundingBoxDimensions dimensions() override {
        double p = (a+b+c) / 2;
        BoundingBoxDimensions box;
        box.height = (a*b*c/(4*sqrt(p*(p-a)*(p-b)*(p-c))))*2;
        box.width = (a*b*c/(4*sqrt(p*(p-a)*(p-b)*(p-c))))*2;
        return box;
    }
};

int main() {
    Triangle t(3,4,5);
    Shape::printParams(&t);
    std::cout << std::endl;

    Circle c(5);
    Shape::printParams(&c);
    std::cout << std::endl;

    Rectangle r(5, 6);
    Shape::printParams(&r);
    std::cout << std::endl;

    return 0;
}