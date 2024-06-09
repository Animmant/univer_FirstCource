// main.cpp
#include "material.h"
#include <iostream>

using namespace std;

void displayMenu() {
    cout << "1. Add Material to Tank\n"
         << "2. Pour Material to Tanks\n"
         << "3. Display Tank Contents\n"
         << "4. Mix contents in tank\n"
         << "5. Find Material by Name\n"
         << "6. Exit\n"
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
            string name;
            double transferVolume;
            cout << "Enter material name and volume to pour from tank1 to tank2: ";
            cin >> name >> transferVolume;
            tank1.materialPourInto(tank2, name, transferVolume);
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
            tank1.mixInContainer(); // Mixing contents in tank1
            break;
        }
        case 5: {
            string name;
            cout << "Enter material name to search: ";
            cin >> name;
            Material* material = tank1.findMaterialFromName(name);
            if (material) {
                material->print();
            } else {
                cout << "Material not found in Tank 1." << endl;
            }
            break;
        }
        case 6:
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