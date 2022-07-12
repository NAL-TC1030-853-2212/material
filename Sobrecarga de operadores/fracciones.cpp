#include <iostream>
#include <string>
using namespace std;

class Fraccion {
private:
    int numerador;
    int denominador;
public:
    Fraccion(int numerador, int denominador): numerador{numerador}, denominador{denominador} {}
    // int getNumerador() const {
    //     return numerador;
    // }
    // int getDenominador() const {
    //     return denominador;
    // }
    // void imprimir() {
    //     cout << numerador << " / " << denominador << endl;
    // }
    Fraccion operator+(const Fraccion &fraccion) {
        if (denominador == fraccion.denominador) {
            return Fraccion{numerador + fraccion.numerador, denominador};
        } else {
            int n = numerador * fraccion.denominador + fraccion.numerador * denominador;
            int d = denominador * fraccion.denominador;
            return Fraccion{n, d};
        }
    }
    Fraccion operator+(int entero) {
        return Fraccion{numerador + entero * denominador, denominador};
    }
    // friend da permiso de acceso a todos los elementos de la clase, pero sigue manteniendose como metodo independiente (no miembro)
    friend Fraccion operator+(int entero, const Fraccion &fraccion) {
        return Fraccion{fraccion.numerador + entero, fraccion.denominador};
    }
    // ostream = output stream -> cout es en realidad un ostream
    friend ostream& operator<<(ostream &os, const Fraccion &fraccion) {
        os << fraccion.numerador << " / " << fraccion.denominador;
        return os;
    };
    // Declarando una clase amiga, da acceso a todos mis elementos en OtraClase
    // friend class OtraClase;
};

// Fraccion operator+(int entero, const Fraccion &fraccion) {
//     return Fraccion{fraccion.numerador + entero, fraccion.denominador};
// };

// Tipo_de_retorno nombre(parametros) { cuerpo };
// Fraccion suma(const Fraccion &f1, const Fraccion &f2) {
//     if (f1.getDenominador() == f2.getDenominador()) {
//         return Fraccion{f1.getNumerador() + f2.getNumerador(), f1.getDenominador()};
//     } else {
//         int n = f1.getNumerador() * f2.getDenominador() + f2.getNumerador() * f1.getDenominador();
//         int d = f1.getDenominador() * f2.getDenominador();
//         return Fraccion{n, d};
//     }
// };

int main() {
    Fraccion f1{5,3};
    Fraccion f2{7,3};
    // f1 + f2 + f3 + f4 ... + fn
    // Fraccion f3 = suma(suma(suma(f1, f2), f3), f4);
    Fraccion f3 = 5 + f1 + f2;
    // f1.imprimir();
    // f2.imprimir();
    // f3.imprimir();
    cout << f1 << " + " << f2 << " = " << f3 << endl;
}