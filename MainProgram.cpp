// --- Base class -------------------------------------------------
class Shape {
protected:
    std::string name;
public:
    Shape(const std::string& n) : name(n) {}
    // TODO 1: Make this destructor VIRTUAL.
    //         (Add the 'virtual' keyword in front.)
    //         A virtual destructor is required for safe deletion
    //         through a Shape* pointer.

    virtual ~Shape() {}
    // Pure virtual: Shape is abstract and cannot be instantiated.

    // Each derived class MUST override area(). (Leave this line.)

    virtual double area() const = 0;

    // describe() is virtual with a default body — leave as is.

    virtual std::string describe() const {

        return name + " with area " + std::to_string(area());

    }

    std::string getName() const { return name; }

};

// --- Derived class: Circle --------------------------------------
class Circle : public Shape {
private:
    double radius;
public:
    // TODO 2: Write the constructor.
    //   - Call the Shape base constructor with the name "Circle".
    //   - Store the radius.
    Circle(double r) : Shape("Circle"), radius(r) {
    }
    // TODO 3: Override area().  Area of a circle = PI * r * r.
    //         Use override.
    double area() const override {
        return M_PI * radius * radius;
    }
};
// --- Derived class: Rectangle -----------------------------------
class Rectangle : public Shape {
protected:
    double width;

    double height;

public:

    // TODO 4: Write the constructor.

    //   - Call Shape with the name "Rectangle".

    //   - Store width and height.

    Rectangle(double w, double h)

        : Shape("Rectangle"), width(w), height(h) {

    }

    // TODO 5: Override area().  Area of a rectangle = width * height.

    double area() const override {

        return width * height;

    }

};

// --- Derived class: Square (inherits from Rectangle) ------------

class Square : public Rectangle {

public:

    // TODO 6: Write the constructor.

    //   - A square is a rectangle whose width == height == side.

    //   - Call the Rectangle constructor with (side, side).

    //   - Then set name = "Square".

    Square(double side) : Rectangle(side, side) {

        name = "Square";

    }

    // Note: Square reuses Rectangle::area() — no need to rewrite it.

};

// ================================

// FUNCTION IMPLEMENTATIONS

// ================================

// TODO 7: Sum the area() of every shape in the vector.

//         Must work polymorphically (through Shape*).

//         An empty vector returns 0.0.
double totalArea(const std::vector<Shape*>& shapes) {
    double total = 0.0;
    for (const Shape* s : shapes) {

        total += s->area();
    }
    return total;
}
// TODO 8: Return getName() of the shape with the LARGEST area.
//         If the vector is empty, return "".
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
 
