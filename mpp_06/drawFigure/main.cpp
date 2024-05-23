#include "Graphics.h"

int main() {
    Circle c(10, 10, 5);

    int choice;
    double dx, dy, angle, factor;

    while (true) {
        std::cout << "1. Move\n2. Rotate\n3. Resize\n4. Draw\n5. Exit\nEnter choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Enter dx, dy: ";
                std::cin >> dx >> dy;
                c.move(dx, dy);
                break;
            case 2:
                std::cout << "Enter angle: ";
                std::cin >> angle;
                c.rotate(angle);
                break;
            case 3:
                std::cout << "Enter resize factor: ";
                std::cin >> factor;
                c.resize(factor);
                break;
            case 4:
                c.draw();
                break;
            case 5:
                return 0;
            default:
                std::cout << "Invalid choice!\n";
        }
    }

    return 0;
}
