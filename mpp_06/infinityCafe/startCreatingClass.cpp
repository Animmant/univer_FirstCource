#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Material {
protected:
    string name;
    double volume;
public:
    Material(string name, double volume) {
        this->name = name;
        this->volume = volume;
    }

    virtual void print() const {
        cout << "Name: " << name << endl;
        cout << "Volume: " << volume << endl;
    }

    string getName() const {
        return name;
    }

    double getVolume() const {
        return volume;
    }

    void setVolume(double volume) {
        this->volume = volume;
    }
};

class MaterialTank {
    double totalVolume;
    vector<Material> materials;

public:
    MaterialTank(double volume, vector<Material> materials = {}) {
        this->totalVolume = volume;
        this->materials = materials;
    }

    void addMaterial(Material ingredient) {
        materials.push_back(ingredient);
    }

    void pourInto(MaterialTank &targetTank, double volume) {
        if (volume > getAvailableVolume()) {
            cout << "Not enough material in the source tank to pour." << endl;
            return;
        }
        if (volume > targetTank.getAvailableVolume()) {
            cout << "Not enough space in the target tank to pour the material." << endl;
            return;
        }

        for (Material &material : materials) {
            if (volume <= 0) break;

            double availableVolume = material.getVolume();
            double transferVolume = min(availableVolume, volume);
            volume -= transferVolume;
            material.setVolume(availableVolume - transferVolume);

            bool found = false;
            for (Material &targetMaterial : targetTank.materials) {
                if (targetMaterial.getName() == material.getName()) {
                    targetMaterial.setVolume(targetMaterial.getVolume() + transferVolume);
                    found = true;
                    break;
                }
            }
            if (!found) {
                targetTank.addMaterial(Material(material.getName(), transferVolume));
            }
        }
        totalVolume -= volume;
        targetTank.totalVolume += volume;
    }

    double getAvailableVolume() const {
        return totalVolume - getUsedVolume();
    }

    double getUsedVolume() const {
        double usedVolume = 0;
        for (const Material &material : materials) {
            usedVolume += material.getVolume();
        }
        return usedVolume;
    }

    void print() const {
        cout << "Total Volume: " << totalVolume << endl;
        cout << "Materials: " << endl;
        for (const Material &material : materials) {
            material.print();
        }
    }
};

void displayMenu() {
    cout << "1. Add Material to Tank\n"
         << "2. Pour Material Between Tanks\n"
         << "3. Display Tank Contents\n"
         << "4. Exit\n"
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
        case 4:
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
