#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FoodProduct {
public:
    string name;  // Назва продукту
    double price;      // Ціна продукту
    double portionWeight; // Вага порції в грамах
    string category;    // Категорія продукту
    double proteins;    // Кількість білків на 100 грам
    double fats;       // Кількість жир__ів
    double carbohydrates; // Кількість вуглеводів
    double energyValue; //  Калоріїї 

    void printInfo() {
            cout << "Name: " << name << std::endl
                  << "Portion Weight: " << portionWeight << "g" << std::endl
                  << "Energy Value: " << energyValue << " kcal" << std::endl
                  << "Proteins: " << proteins << "g" << std::endl
                  << "Fats: " << fats << "g" << std::endl
                  << "Carbohydrates: " << carbohydrates << "g" << std::endl;
    }

    double setEnergyValue() { // Порахувати калоріїї
        return energyValue = (proteins * 4 + fats * 9 + carbohydrates * 4) / 100 * portionWeight;
    }
};

int main(){

    vector<FoodProduct> lunchProducts = {
        {"Rice", 25, 500, "Cereals", 7.5, 1.5, 73, 323},
        {"Bread", 10, 300, "Bakery products", 8.7, 1.2, 48.9, 242},
        {"Apple", 10, 100, "Fruits", 0.4, 0.4, 9.8, 47}
    };

    printf("sum_energyInLaunch \n");
    
    // Всього обіду калоріїї
    double sum_energyInLaunch = 0;
    for (int i = 0; i < lunchProducts.size(); i++) {
        sum_energyInLaunch += lunchProducts[i].setEnergyValue();
    }
    cout << "Sum energy in lunch: " << sum_energyInLaunch << " kcal \n" << std::endl;

    printf("Lunch: \n");
    for (int i = 0; i < lunchProducts.size(); i++) {
        lunchProducts[i].printInfo();
    }
    
    return 0;
}