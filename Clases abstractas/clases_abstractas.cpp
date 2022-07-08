#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal {
protected:
    string nombre;
public:
    Animal(string nombre): nombre{nombre} {}
    virtual void sound() = 0; // funcion virtual pura hace que Animal sea una clase abstracta
    virtual void otra_virtual() = 0;
    void algo() {
        cout << "Algo..." << endl;
    }
};

class Dog: public Animal {
public:
    Dog(string nombre): Animal{nombre} {}
    virtual void sound() {
        cout << "Woof, woof..." << endl;
    }
    virtual void otra_virtual() {
        cout << "Otra virtual..." << endl;
    }
    void otrafuncion() {
        cout << "Otra funcion..." << endl;
    }
};

class Cat: public Animal {
public:
    Cat(string nombre): Animal{nombre} {}
    virtual void sound() {
        cout << "Meow, meow..." << endl;
    }
    virtual void otra_virtual() {
        cout << "Otra virtual..." << endl;
    }
};

int main() {
    // Error, no se puede generar un objeto de una clase abstracta
    // Animal a1{"Animal"};

    Dog d1{"Fido"};
    d1.sound();
    d1.algo();
    d1.otrafuncion();
    d1.otra_virtual();

    Animal *ptr_animal = &d1;
    ptr_animal->sound();
    // ptr_animal->otrafuncion(); // no esta declarada en Animal, asi que marca error

    vector <Animal *> animales;
    animales.push_back(new Dog{"Rufus"});
    animales.push_back(new Cat{"Michi"});
    animales.push_back(new Dog{"Firulais"});

    animales.at(0)->sound();
    animales[0]->sound();

    for (Animal *p : animales) {
        p->sound();
    }

}