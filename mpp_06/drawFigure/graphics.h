#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
#include <cmath>

// Base class Point
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

// Derived class Hexagon from Point
class Hexagon : public Point {
private:
    double side_length;
    std::string color;
public:
    Hexagon(double x, double y, double side_length, std::string color)
        : Point(x, y), side_length(side_length), color(color) {}

    void resize(double factor) override {
        side_length *= factor;
    }

    void draw() const override {
        std::cout << "Drawing hexagon at (" << x << ", " << y << ") with side length " 
                  << side_length << " and color " << color << std::endl;
    }

    void change_color(const std::string& new_color) {
        color = new_color;
    }
};

#endif
