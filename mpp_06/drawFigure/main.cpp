#include "graphics.h"
#include <iostream>

using namespace std;

void displayMenu() {
    cout << "1. Move\n"
         << "2. Rotate\n"
         << "3. Resize\n"
         << "4. Draw\n"
         << "5. Change Color\n"
         << "6. Exit\n"
         << "Enter choice: ";
}

// Function to handle the menu option
void handleMenuOption(Hexagon &hexagon) {
    int choice;
    cin >> choice;

    double dx, dy, angle, factor;
    string color;

    switch (choice) {
        case 1:
            cout << "Enter dx, dy: ";
            cin >> dx >> dy;
            hexagon.move(dx, dy);
            break;
        case 2:
            cout << "Enter angle: ";
            cin >> angle;
            hexagon.rotate(angle);
            break;
        case 3:
            cout << "Enter resize factor: ";
            cin >> factor;
            hexagon.resize(factor);
            break;
        case 4:
            hexagon.draw();
            break;
        case 5:
            cout << "Enter new color: ";
            cin >> color;
            hexagon.change_color(color);
            break;
        case 6:
            cout << "Exiting program." << endl;
            exit(0);
        default:
            cout << "Unknown option." << endl;
            break;
    }
}

int main() {
    Hexagon h(10, 10, 5, "red");

    while (true) {
        displayMenu();
        handleMenuOption(h);
    }

    return 0;
}