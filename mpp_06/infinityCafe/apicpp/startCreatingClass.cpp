#include "material.h"
#include <iostream>

using namespace std;

void displayMenu() {
    cout << "1. Add Material to Tank\n"
         << "2. Pour Material Between Tanks\n"
         << "3. Display Tank Contents\n"
         << "4. mix contents\n"
         << "5. Exit\n"
         << "Enter choice: ";
}

void handleMenuOption(MaterialTank &tank1, MaterialTank &tank2) {
    int option;
    cin >> option;

    switch (option) {
        case 1: {
            string name;
            double currentVolumeMaterial;
            cout << "Enter material name and volume: ";
            cin >> name >> currentVolumeMaterial;
            tank1.addMaterial(Material(name, currentVolumeMaterial));
            break;
        }
        case 2: {
            double transferVolume;
            cout << "Enter volume to pour from Tank 1 to Tank 2: ";
            cin >> transferVolume;
            tank1.pourInto(tank2, transferVolume);
            break;
        }
        case 3: {
            cout << "Contents of Tank 1:" << endl;
            tank1.print();
            cout << "Contents of Tank 2:" << endl;
            tank2.print();
            break;
        }
        case 4: {
            tank1.mixInContainer();
            break;
        }
        case 5:
            cout << "Exiting program." << endl;
            exit(0);
        default:
            cout << "Unknown option." << endl;
            break;
    }
}

int main() {
    MaterialTank tank1(100);
    MaterialTank tank2(50);

    while (true) {
        displayMenu();
        handleMenuOption(tank1, tank2);
    }

    return 0;
}
