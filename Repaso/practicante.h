#ifndef PRACTICANTE_H_
#define PRACTICANTE_H_

#include <iostream>
#include <string>
#include "empleado.h"
using namespace std;

class Practicante: public Empleado {
private:
    double horas_trabajadas;
    double pago_por_hora;
    int maximo_de_horas;
public:
    Practicante(string nombre, double horas_trabajadas, double pago_por_hora, int maximo_de_horas):
        Empleado{nombre, "Practicante"}, horas_trabajadas{horas_trabajadas}, pago_por_hora{pago_por_hora}, 
        maximo_de_horas{maximo_de_horas} {}
    virtual double pago_mensual() {
        if (horas_trabajadas > maximo_de_horas)
            return maximo_de_horas * pago_por_hora;
        return horas_trabajadas * pago_por_hora;
    }
    virtual void imprime() const {
        cout << "Nombre: " << nombre << " - Tipo: " << tipo_empleado << " - Horas trabajadas: " << horas_trabajadas << " - Pago por hora: " << pago_por_hora << " - Maximo de horas:" << maximo_de_horas;
    }
};

#endif