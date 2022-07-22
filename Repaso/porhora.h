#ifndef PORHORA_H_
#define PORHORA_H_

#include <iostream>
#include <string>
#include "empleado.h"
using namespace std;

class PorHora: public Empleado {
private:
    double horas_trabajadas;
    double pago_por_hora;
public:
    PorHora(string nombre, double horas_trabajadas, double pago_por_hora):
        Empleado{nombre, "Por hora"}, horas_trabajadas{horas_trabajadas}, pago_por_hora{pago_por_hora} {}
    virtual double pago_mensual() {
        return horas_trabajadas * pago_por_hora;
    }
    virtual void imprime() const {
        cout << "Nombre: " << nombre << " - Tipo: " << tipo_empleado << " - Horas trabajadas: " << horas_trabajadas << " - Pago por hora: " << pago_por_hora;
    }
};

#endif