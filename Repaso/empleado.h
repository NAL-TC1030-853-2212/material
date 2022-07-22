#ifndef EMPLEADO_H_
#define EMPLEADO_H_

#include <iostream>
#include <string>
using namespace std;

class Empleado {
protected:
    string nombre;
    string tipo_empleado;
public:
    Empleado(string nombre, string tipo_empleado): nombre{nombre}, tipo_empleado{tipo_empleado} {}
    virtual double pago_mensual() = 0;
    virtual void imprime() const = 0;
    friend ostream& operator<<(ostream &os, const Empleado &empleado) {
        empleado.imprime();
    }
    string get_tipo_empleado() {
        return tipo_empleado;
    }
};

#endif