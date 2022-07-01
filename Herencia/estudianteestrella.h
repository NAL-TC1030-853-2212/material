// #pragma once
#ifndef ESTUDIANTEESTRELLA_H_
#define ESTUDIANTEESTRELLA_H_

#include <iostream>
#include <string>
#include "estudiante.h"
using namespace std;

class EstudianteEstrella: public Estudiante {
private:
    string premio;
public:
    EstudianteEstrella(string nombre, int edad, int matricula, string premio): 
        Estudiante{nombre, edad, matricula}, premio{premio} {
            cout << "Llamando al constructor de EstudianteEstrella..." << endl;
        }
};

#endif