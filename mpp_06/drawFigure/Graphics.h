#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
#include <cmath>

// Базовий клас Point
class Point {
protected:
    double x, y;
public:
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    void move(double dx, double dy) {
        x += dx;
        y += dy;
    }

    void rotate(double angle) {
        double rad = angle * M_PI / 180.0;
        double newX = x * cos(rad) - y * sin(rad);
        double newY = x * sin(rad) + y * cos(rad);
        x = newX;
        y = newY;
    }

    virtual void resize(double factor) = 0;
    virtual void draw() const = 0;
};

// Клас Circle, похідний від Point
class Circle : public Point {
private:
    double radius;
public:
    Circle(double x, double y, double radius) : Point(x, y), radius(radius) {}

    void resize(double factor) override {
        radius *= factor;
    }

    void draw() const override {
        std::cout << "Drawing circle at (" << x << ", " << y << ") with radius " << radius << std::endl;
    }
};

// Додаткові класи можуть бути додані аналогічно

#endif
