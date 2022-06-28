#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Automovil {
private:
    string marca;
    string modelo;
    string color;
    int anio;
public:
    // Automovil(string marca, string modelo, string color, int anio) {
    //     this->marca = marca;
    //     this->modelo = modelo;
    //     this->color = color;
    //     this->anio = anio;
    // }
    // Lista de inicialización: atributo{parametro}
    Automovil(string marca, string modelo, string color, int anio): 
        marca{marca}, modelo{modelo}, color{color}, anio{anio} {}

    void encender() {
        cout << "Encendiendo " << marca << " - " << modelo << endl;
    }

    void apagar() {
        cout << "Apagando " << marca << " - " << modelo << endl;
    }
};

int main() {
    Automovil a1{"Toyota", "Corolla", "Blanco", 1986};
    a1.encender();

    // Los arreglos son conjuntos de cosas de un tamanio definido
    Automovil autos[3] = {
        Automovil{"Chevrolet", "Camaro", "Amarillo", 1993},
        Automovil{"Ford", "Mustang", "Rojo", 1994},
        Automovil{"Dodge", "Charger", "Negro", 1996}
    };

    // autos[1].encender();

    // Recorrido for por medio de índices
    // i inicia en 0, repite mientras sea menor a 3, incrementa de 1 en 1
    for (int i = 0; i < 3; i++) {
        autos[i].apagar();
    }

    // Recorrido for each - parecido al for de Python
    for (Automovil a : autos) {
        a.encender();
    }

    vector <Automovil> autosv;

    // Mete un objeto al final del vector -> Parecido al lista.append() de Python
    autosv.push_back(Automovil{"VW", "Jetta", "Azul", 2004});
    autosv.push_back(Automovil{"VW", "Golf", "Rojo", 2006});

    autosv.at(1).encender();
    autosv[1].encender();

    // Elimina todos los elementos del vector
    // autosv.clear();

    // Elimina el ultimo elemento
    // autosv.pop_back()

    for (int i = 0; i < autosv.size(); i++) {
        // autosv.at(i).apagar();
        autosv[i].apagar();
    }

    for (Automovil a : autosv) {
        a.encender();
    }

}