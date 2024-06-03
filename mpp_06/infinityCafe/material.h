#ifndef MATERIAL_H
#define MATERIAL_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Material {
protected:
    string name;
    double currentVolumeMaterial;
public:
    Material(string name, double currentVolumeMaterial) {
        this->name = name;
        this->currentVolumeMaterial = currentVolumeMaterial;
    }

    virtual void print() const {
        cout << "Name: " << name << endl;
        cout << "Volume: " << currentVolumeMaterial << endl;
    }

    string getName() const {
        return name;
    }

    double getCurrentVolumeMaterial() const {
        return currentVolumeMaterial;
    }

    void setCurrentVolumeMaterial(double currentVolumeMaterial) {
        this->currentVolumeMaterial = currentVolumeMaterial;
    }
};

class MaterialTank {
    double totalVolumeTank;
    vector<Material> materials;

public:
    MaterialTank(double totalVolumeTank, vector<Material> materials = {}) {
        this->totalVolumeTank = totalVolumeTank;
        this->materials = materials;
    }

    void addMaterial(Material ingredient) {
        materials.push_back(ingredient);
    }

    void pourInto(MaterialTank &targetTank, double transferVolume) {
        if (transferVolume > getAvailableVolume()) {
            cout << "Not enough material in the source tank to pour." << endl;
            return;
        }
        if (transferVolume > targetTank.getAvailableVolume()) {
            cout << "Not enough space in the target tank to pour the material." << endl;
            return;
        }

        for (Material &material : materials) {
            if (transferVolume <= 0) break;

            double availableVolumeMaterial = material.getCurrentVolumeMaterial();
            double actualTransferVolume = min(availableVolumeMaterial, transferVolume);
            transferVolume -= actualTransferVolume;
            material.setCurrentVolumeMaterial(availableVolumeMaterial - actualTransferVolume);

            bool found = false;
            for (Material &targetMaterial : targetTank.materials) {
                if (targetMaterial.getName() == material.getName()) {
                    targetMaterial.setCurrentVolumeMaterial(targetMaterial.getCurrentVolumeMaterial() + actualTransferVolume);
                    found = true;
                    break;
                }
            }
            if (!found) {
                targetTank.addMaterial(Material(material.getName(), actualTransferVolume));
            }
        }
        totalVolumeTank -= transferVolume;
        targetTank.totalVolumeTank += transferVolume;
    }

    double getAvailableVolume() const {
        return totalVolumeTank - getUsedVolume();
    }

    double getUsedVolume() const {
        double usedVolume = 0;
        for (const Material &material : materials) {
            usedVolume += material.getCurrentVolumeMaterial();
        }
        return usedVolume;
    }

    void print() const {
        cout << "Total Volume: " << totalVolumeTank << endl;
        cout << "Materials: " << endl;
        for (const Material &material : materials) {
            material.print();
        }
    }
};

#endif
