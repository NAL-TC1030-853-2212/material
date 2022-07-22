#ifndef ASALARIADO_H_
#define ASALARIADO_H_

#include <iostream>
#include <string>
#include "empleado.h"
using namespace std;

class Asalariado: public Empleado {
private:
    double salario_mensual;
public:
    Asalariado(string nombre, double salario_mensual): 
        Empleado{nombre, "Asalariado"}, salario_mensual{salario_mensual} {}
    virtual double pago_mensual() {
        return salario_mensual;
    }
    virtual void imprime() const {
        cout << "Nombre: " << nombre << " - Tipo: " << tipo_empleado << " - Salario mensual: " << salario_mensual;
    }
};

#endif