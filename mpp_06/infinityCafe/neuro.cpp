#include "material.h"
#include <iostream>

using namespace std;

void displayMenu() {
    cout << "1. Add Material to Tank\n"
         << "2. Pour Material Between Tanks\n"
         << "3. Display Tank Contents\n"
         << "4. Mix Two Materials\n"
         << "5. Exit\n"
         << "Enter choice: ";
}

void handleMenuOption(MaterialTank &tank1, MaterialTank &tank2) {
    int option;
    cin >> option;

    switch (option) {
        case 1: {
            string name;
            double volume;
            cout << "Enter material name and volume: ";
            cin >> name >> volume;
            tank1.addMaterial(Material(name, volume));
            break;
        }
        case 2: {
            double volume;
            cout << "Enter volume to pour from Tank 1 to Tank 2: ";
            cin >> volume;
            tank1.pourInto(tank2, volume);
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
            string name1, name2;
            double volume1, volume2;
            cout << "Enter first material name and volume: ";
            cin >> name1 >> volume1;
            cout << "Enter second material name and volume: ";
            cin >> name2 >> volume2;

            Material mat1(name1, volume1);
            Material mat2(name2, volume2);

            Material newMat = tank1.mix(mat1, mat2);

            cout << "New Material: " << newMat.getName() << endl;
            cout << "Volume: " << newMat.getVolume() << endl;

            tank1.addMaterial(newMat);
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
