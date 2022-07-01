#include <iostream>
#include <string>
using namespace std;

class Persona {
protected:
    string nombre;
    int edad;
public:
    Persona(string nombre, int edad): nombre{nombre}, edad{edad} {
        cout << "Llamando al constructor de Persona..." << endl;
    }
    void presentarse() {
        cout << "Soy " << nombre << " y tengo " << edad << " anios" << endl;
    }
    // string getNombre() {
    //     return nombre;
    // }
};

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

class EstudianteEstrella: public Estudiante {
private:
    string premio;
public:
    EstudianteEstrella(string nombre, int edad, int matricula, string premio): 
        Estudiante{nombre, edad, matricula}, premio{premio} {
            cout << "Llamando al constructor de EstudianteEstrella..." << endl;
        }
};

int main() {
    Persona p1{"Rodrigo", 21};
    Estudiante e1{"Marcela", 18, 795822};
    EstudianteEstrella ee1{"Diego", 20, 852452, "Premio de Excelencia"};

    p1.presentarse();

    e1.presentarse();
    e1.tomarClase();

    ee1.presentarse();

}