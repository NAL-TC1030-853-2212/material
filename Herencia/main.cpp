#include <iostream>
#include <string>
#include "persona.h"
#include "estudiante.h"
#include "estudianteestrella.h"
using namespace std;

int main() {
    Persona p1{"Rodrigo", 21};
    Estudiante e1{"Marcela", 18, 795822};
    EstudianteEstrella ee1{"Diego", 20, 852452, "Premio de Excelencia"};

    p1.presentarse();

    e1.presentarse();
    e1.tomarClase();

    ee1.presentarse();

}