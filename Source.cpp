#include <iostream>
using namespace std;

class Point {
public:
    int x, y, z;

    Point(int X = 0, int Y = 0, int Z = 0) : x(X), y(Y), z(Z) {}

    friend ostream& operator<<(ostream& out, const Point& point) {
        out << "Point(" << point.x << ", " << point.y << ", " << point.z << ")";
        return out;
    }
};

class Shape {
public:
    virtual void print(ostream& out) const = 0;

    virtual double getSquare() const = 0;
};

class Circle final : public Shape {
    Point center;
    int radius;

public:
    Circle(Point c, int r) : center(c), radius(r) {}

    void print(ostream& out) const override {
        out << "Circle(" << center << ", radius " << radius << ")";
    }

    double getSquare() const override {
        return 3.14 * radius * radius;
    }
};

class Square : public Shape {
    Point topLeft;
    int side;

public:
    Square(Point tl, int s) : topLeft(tl), side(s) {}

    void print(ostream& out) const override {
        out << "Square(" << topLeft << ", length: " << side << ")";
    }

    double getSquare() const override {
        return side * side;
    }
};

class Rectangle final : public Shape {
    Point topLeft;
    int length, width;

public:
    Rectangle(Point tl, int l, int w) : topLeft(tl), length(l), width(w) {}

    void print(ostream& out) const override {
        out << "Rectangle(" << topLeft << ", length: " << length << ", width: " << width << ")";
    }

    double getSquare() const override {
        return length * width;
    }
};

class Triangle final : public Shape {
    Point points[3];
    int side, height;
public:
    Triangle(Point p[3], int s, int h) : side(s), height(h) {
        for (int i = 0; i < 3; i++) {
            points[i] = p[i];
        }
    }

    void print(ostream& out) const override {
        char c = 'A';
        out << "Triangle(";
        for (int i = 0; i < 3; i++) {
            out << c << ": " << points[i] << "; ";
            c++;
        }
        out << "side: " << side << ", height: " << height << ")";
    }

    double getSquare() const override {
        return side * height / 2.0;
    }
};

ostream& operator<<(ostream& out, const Shape& shape) {
    shape.print(out);
    return out;
}

int main() {
    Circle c(Point(1, 2, 3), 7);
    cout << c << endl;
    cout << "Area of the circle: " << c.getSquare() << endl;

    Square s(Point(1, 2, 3), 8);
    cout << s << endl;
    cout << "Area of the square: " << s.getSquare() << endl;

    Rectangle r(Point(1, 2, 3), 5, 4);
    cout << r << endl;
    cout << "Area of the rectangle: " << r.getSquare() << endl;

    Point p[3] = { Point(0, 1), Point(1, 1), Point(2, 0) };
    Triangle t(p, 8, 6);
    cout << t << endl;
    cout << "Area of the triangle: " << t.getSquare() << endl;

    return 0;
}
