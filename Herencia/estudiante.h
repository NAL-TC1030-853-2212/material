// #pragma once
#ifndef ESTUDIANTE_H_
#define ESTUDIANTE_H_

#include <iostream>
#include <string>
#include "persona.h"
using namespace std;

class Estudiante: public Persona {
protected:
    int matricula;
public:
    Estudiante(string nombre, int edad, int matricula): Persona{nombre, edad}, matricula{matricula} {
        cout << "Llamando al constructor de Estudiante..." << endl;
    }
    void tomarClase() {
        cout << nombre << " esta tomando clase..." << endl;
    }
    void presentarse() {
        cout << "Soy " << nombre << " y soy un estudiante" << endl;
    }
};

#endif