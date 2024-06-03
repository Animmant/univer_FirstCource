#include <iostream>
#include <vector>

using namespace std;

class Material{
protected:
    string name;
    double volume;
    double density;
public:
    Material(string name, double density, double volume) {
        this->name = name;
        this->volume = volume;
        this->density = density;
    }

    virtual void print() const {
        cout << "Name: " << name << endl;
        cout << "Volume: " << volume << endl;
        cout << "Density: " << density << endl;
        cout << "Mass: " << volume * density << endl;
    
    }
    double getMass() const {
        return volume * density;
    }
    string getName() const {
        return name;
    }
    double getVolume() const {
        return volume;
    }

};

class MaterialTank{
    double totalVolume;
   vector<Material> materials;
public:
    MaterialTank(double volume, vector<Material> materials) {
        this->volume = volume;
        this->materials = materials;
    }

    void addMaterial(Material ingredient) {
        materials.push_back(ingredient);
    }

    void pourInto(
    }

    void print() const {
        cout << "Volume: " << volume << endl;
        cout << "Materials: " << endl;
        for (const Material& material : materials) {
            material.print();
        }}

};

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
