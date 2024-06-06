#ifndef MATERIAL_H
#define MATERIAL_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>

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
        if (transferVolume > getUsedVolume()) {
            cout << "Not enough material in the source tank to pour." << endl;
            return;
        }
        if (transferVolume > targetTank.getAvailableVolume()) {
            cout << "Not enough space in the target tank to pour the material." << endl;
            return;
        }

        double remainingTransferVolume = transferVolume;

        for (Material &material : materials) {
            if (remainingTransferVolume <= 0) {
                break;
            }

            double materialVolume = material.getCurrentVolumeMaterial();
            double volumeToTransfer = min(materialVolume, remainingTransferVolume);

            // Reduce volume in source tank
            material.setCurrentVolumeMaterial(materialVolume - volumeToTransfer);

            // Check if the material already exists in the target tank
            bool found = false;
            for (Material &targetMaterial : targetTank.materials) {
                if (targetMaterial.getName() == material.getName()) {
                    targetMaterial.setCurrentVolumeMaterial(targetMaterial.getCurrentVolumeMaterial() + volumeToTransfer);
                    found = true;
                    break;
                }
            }

            // If material doesn't exist in the target tank, add it
            if (!found) {
                targetTank.addMaterial(Material(material.getName(), volumeToTransfer));
            }

            remainingTransferVolume -= volumeToTransfer;
        }
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

    void mixInContainer() {
        if (materials.size() > 1) {
            string substance1 = materials[0].getName();
            string substance2 = materials[1].getName();
            string cmd = "python3 mix.py " + substance1 + " " + substance2;

            FILE* pipe = popen(cmd.c_str(), "r");
            if (!pipe) {
                cout << "Error: could not open pipe." << endl;
                return;
            }

            string result;
            char buffer[128];
            while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
                result += buffer;
            }

            int returnCode = pclose(pipe);
            if (returnCode != 0) {
                cout << "Error: command execution failed with return code " << returnCode << endl;
                return;
            }

            result.erase(result.find_last_not_of(" \n\r\t") + 1);  // Remove trailing newlines and spaces

            if (!result.empty()) {
                double currentVolumeMaterial = materials[0].getCurrentVolumeMaterial() + materials[1].getCurrentVolumeMaterial() ;
                materials.clear();
                materials.push_back(Material(result, currentVolumeMaterial));
            }
        }
    }
};

#endif
