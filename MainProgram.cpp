#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Shape {
protected:
    std::string name;
public:
    Shape(const std::string& n) : name(n) {}
    virtual ~Shape() {} 
    
    virtual double area() const = 0;
    
    virtual std::string describe() const {
        return name + " with area " + std::to_string(area());
    }
    
    std::string getName() const { return name; }
};


class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : Shape("Circle"), radius(r) {}
    
    double area() const override {
        return M_PI * radius * radius;
    }
};


class Rectangle : public Shape {
protected:
    double width;
    double height;
public:
    Rectangle(double w, double h)
        : Shape("Rectangle"), width(w), height(h) {}
        
    double area() const override {
        return width * height;
    }
};


class Square : public Rectangle {
public:
    Square(double side)
        : Rectangle(side, side) {
        name = "Square"; 
    }
};



double totalArea(const std::vector<Shape*>& shapes) {
    double total = 0.0;
    for (const Shape* s : shapes) {
        total += s->area();
    }
    return total;
}

std::string largestShapeName(const std::vector<Shape*>& shapes) {
    if (shapes.empty()) {
        return "";
    }
    const Shape* largest = shapes[0];
    for (const Shape* s : shapes) {
        if (s->area() > largest->area()) {
            largest = s;
        }
    }
    return largest->getName();
}

// ================================
// MAIN
// ================================

int main() {
    std::vector<Shape*> shapes;
    
    shapes.push_back(new Circle(2.0));
    shapes.push_back(new Rectangle(3.0, 4.0));
    shapes.push_back(new Square(5.0));
    
    for (const Shape* s : shapes) {
        std::cout << s->describe() << std::endl;
    }
    
    std::cout << "Total area: " << totalArea(shapes) << std::endl;
    std::cout << "Largest:    " << largestShapeName(shapes) << std::endl;

    for (Shape* s : shapes) {
        delete s;
    }
    shapes.clear(); 
    
    return 0; 
}
