#include <iostream>
#include <string>

using namespace std;

class car{
    public:
    
    car(){

    }
    private:
    string brand, model;
    int year;
    double price;
};

class client{
    public:
    client(){

    }
private:
    string name,  adress, phone;
};

int main(){
    car c1;
    return 0;
}