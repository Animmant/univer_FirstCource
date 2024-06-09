#ifndef MATERIAL_H
#define MATERIAL_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <algorithm>  // Include this header for remove_if

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
protected:
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

    Material* findMaterialFromName(const string &name) {
        for (Material &material : materials) {
            if (material.getName() == name) {
                return &material;
            }
        }
        return nullptr;
    }

     // Remove material from source tank if its volume is zero
    void validateAndRemoveZeroVolumeMaterials() {
        materials.erase(
            remove_if(materials.begin(), materials.end(), [](const Material &m) { return m.getCurrentVolumeMaterial() == 0; }),
            materials.end()
        );
    }

    void materialPourInto(MaterialTank &targetTank, const string &nameMaterial, double transferVolume) {
        Material* myMaterial = findMaterialFromName(nameMaterial);
        if (!myMaterial) {
            cout << "Material not found in the source tank." << endl;
            return;
        }
        if (transferVolume > myMaterial->getCurrentVolumeMaterial()) {
            cout << "Not enough material in the source tank to pour." << endl;
            return;
        }
        if (transferVolume > targetTank.getAvailableVolume()) {
            cout << "Not enough space in the target tank to pour the material." << endl;
            return;
        }

        Material* targetMaterial = targetTank.findMaterialFromName(nameMaterial);
        if (!targetMaterial) {
            targetTank.addMaterial(Material(nameMaterial, transferVolume));
        } else {
            targetMaterial->setCurrentVolumeMaterial(targetMaterial->getCurrentVolumeMaterial() + transferVolume);
        }

        myMaterial->setCurrentVolumeMaterial(myMaterial->getCurrentVolumeMaterial() - transferVolume);

       
        validateAndRemoveZeroVolumeMaterials();
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
            string cmd = "python3 mix.py";
            for (const auto &material : materials) {
                cmd += " " + material.getName();
            }

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
                double currentVolumeMaterial = 0;
                for (const auto &material : materials) {
                    currentVolumeMaterial += material.getCurrentVolumeMaterial();
                }
                materials.clear();
                materials.push_back(Material(result, currentVolumeMaterial));
            }
        }
    }
};

#endif
