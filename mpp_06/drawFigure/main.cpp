#include "graphics.h"
#include <iostream>

int main() {
    Hexagon h(10, 10, 5, "red");

    int choice;
    double dx, dy, angle, factor;
    std::string color;

    while (true) {
        std::cout << "1. Move\n2. Rotate\n3. Resize\n4. Draw\n5. Change Color\n6. Exit\nEnter choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Enter dx, dy: ";
                std::cin >> dx >> dy;
                h.move(dx, dy);
                break;
            case 2:
                std::cout << "Enter angle: ";
                std::cin >> angle;
                h.rotate(angle);
                break;
            case 3:
                std::cout << "Enter resize factor: ";
                std::cin >> factor;
                h.resize(factor);
                break;
            case 4:
                h.draw();
                break;
            case 5:
                std::cout << "Enter new color: ";
                std::cin >> color;
                h.change_color(color);
                break;
            case 6:
                return 0;
            default:
                std::cout << "Invalid choice!\n";
        }
    }

    return 0;
}
