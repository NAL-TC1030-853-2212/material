#include <iostream>
#include <string>
#include <exception>
using namespace std;

class fraccion_exception: public exception {
private:
    int numerador;
    int denominador;
    string mensaje;
public:
    fraccion_exception(int numerador, int denominador): numerador{numerador}, denominador{denominador} {}
    virtual const char* what() {
        mensaje = "No se puede crear la Fraccion " + to_string(numerador) + "/" + to_string(denominador);
        return mensaje.c_str();
    }
};

class Fraccion {
private:
    int numerador;
    int denominador;
public:
    Fraccion(int numerador, int denominador): numerador{numerador}, denominador{denominador} {
        if (denominador == 0)
            throw fraccion_exception{numerador, denominador};
    }

    friend Fraccion operator+(const Fraccion &lhs, const Fraccion &rhs) {
        if (lhs.denominador == rhs.denominador)
            return Fraccion{lhs.numerador + rhs.numerador, lhs.denominador};
        return Fraccion {lhs.numerador * rhs.denominador + rhs.numerador * lhs.denominador, lhs.denominador * rhs.denominador};
    }

    friend Fraccion operator-(const Fraccion &lhs, const Fraccion &rhs) {
        if (lhs.denominador == rhs.denominador)
            return Fraccion{lhs.numerador - rhs.numerador, lhs.denominador};
        return Fraccion {lhs.numerador * rhs.denominador - rhs.numerador * lhs.denominador, lhs.denominador * rhs.denominador};
    }

    friend Fraccion operator*(const Fraccion &lhs, const Fraccion &rhs) {
        return Fraccion{lhs.numerador * rhs.numerador, lhs.denominador * rhs.denominador};
    }

    friend Fraccion operator/(const Fraccion &lhs, const Fraccion &rhs) {
        return Fraccion{lhs.numerador * rhs.denominador, lhs.denominador * rhs.numerador};
    }

    friend ostream& operator<<(ostream &os, const Fraccion &fraccion) {
        os << fraccion.numerador << "/" << fraccion.denominador;
        return os;
    }
};

int main() {
    try {
        Fraccion f1{3,5};
        Fraccion f2{0,3};
        Fraccion f3 = f1 + f2;
        cout << f1 << " + " << f2 << " = " << f3 << endl;
        f3 = f1 - f2;
        cout << f1 << " - " << f2 << " = " << f3 << endl;
        f3 = f1 * f2;
        cout << f1 << " * " << f2 << " = " << f3 << endl;
        f3 = f1 / f2;
        cout << f1 << " / " << f2 << " = " << f3 << endl;
    } catch (fraccion_exception e) {
        cout << e.what() << endl;
    }
}