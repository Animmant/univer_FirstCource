#include<iostream>
#include<string>

using namespace std;

class Animal{
public:
    Animal(const string& name) : name(name) {}
    virtual void sound() const {
        cout << "I am an" << name << endl;
    }
protected:
string name;
};
class Dog : public Animal {
public:
Dog(const string& name) : Animal(name) {}
    void voice() {
        cout << "Woof woof" << endl;
    }
    void walk() {
        cout << "The dog is going for a walk" << endl;
    }
    void walk() {
        cout << "The dog is going for a walk" << endl;
    }
};

class Cat : public Animal {
public:
Cat(const string& name) : Animal(name) {}
    void voice() {
        cout << "mauy" << endl;
    }
    void hunt() {
        cout << "A cat hunts a mouse" << endl;
    }
};

int main(){
Dog myDog("Buddy");myDog.voice(); myDog.walk();
    Cat myCat("Whiskers");myCat.voice();  myCat.hunt(); myCat.sound();
}