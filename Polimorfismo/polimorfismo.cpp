#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal {
public:
    virtual void sound() {
        cout << "Animal noises..." << endl;
    }
};

class Dog: public Animal {
public:
    virtual void sound() {
        cout << "Woof, woof..." << endl;
    }
};

class Cat: public Animal {
public:
    virtual void sound() {
        cout << "Meow, meow..." << endl;
    }
};

void metodo_referencia(Animal &animal) {
    animal.sound();
};

void metodo_apuntador(Animal *animal) {
    animal->sound();
};

int main() {
    Animal a1{};
    Dog d1{};
    Cat c1{};

    a1.sound();
    d1.sound();
    c1.sound();

    Animal *ptr;

    ptr = &d1;
    ptr->sound();

    ptr = &c1;
    ptr->sound();

    Animal *animalArray[3];
    animalArray[0] = new Dog{};
    animalArray[1] = new Cat{};
    animalArray[2] = new Cat{};

    for (int i = 0; i < 3; i++) {
        animalArray[i]->sound();
    }

    for (Animal *ptr : animalArray) {
        ptr->sound();
    }

    vector <Animal *> animalVector;
    animalVector.push_back(new Cat{});
    animalVector.push_back(new Dog{});
    animalVector.push_back(new Cat{});
    animalVector.push_back(new Dog{});

    for (int i = 0; i < animalVector.size(); i++) {
        animalVector.at(i)->sound();
    }

    for (Animal *ptr : animalVector) {
        ptr->sound();
    }

    metodo_referencia(a1);
    metodo_referencia(d1);
    metodo_referencia(c1);

    metodo_apuntador(&a1);
    metodo_apuntador(&d1);
    metodo_apuntador(&c1);

}