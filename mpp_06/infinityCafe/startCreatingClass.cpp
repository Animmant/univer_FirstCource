#include <iostream>

using namespace std;

void displayMenu() {
    cout << "1. Move\n"
         << "2. Rotate\n"
         << "3. Resize\n"
         << "4. Exit\n"
         << "Enter choice: ";
}

void handleMenuOption() {
    int option;
    cin >> option;

    switch (option) {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        cout << "Exiting program." << endl;
        exit(0);
    default:
        cout << "Unknown option." << endl;
        break;
    }
}

int main() {

    while (true) {
        displayMenu();
        handleMenuOption();
    }

    return 0;
}
