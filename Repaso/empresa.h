#ifndef EMPRESA_H_
#define EMPRESA_H_

#include <iostream>
#include <string>
#include <vector>
#include "empleado.h"
#include "asalariado.h"
#include "porhora.h"
#include "practicante.h"
using namespace std;

class Empresa {
private:
    vector <Empleado *> empleados;
public:
    // Empresa() {}
    void agrega_asalariado(string nombre, double salario_mensual) {
        empleados.push_back(new Asalariado{nombre, salario_mensual});
    }
    void agrega_por_hora(string nombre, double horas_trabajadas, double pago_por_hora) {
        empleados.push_back(new PorHora{nombre, horas_trabajadas, pago_por_hora});
    }
    void agrega_practicante(string nombre, double horas_trabajadas, double pago_por_hora, int maximo_de_horas) {
        empleados.push_back(new Practicante{nombre, horas_trabajadas, pago_por_hora, maximo_de_horas});
    }
    void agrega_empleado(Empleado *empleado) {
        empleados.push_back(empleado);
    }
    void imprime_empleados() {
        for (Empleado *ptr : empleados)
            cout << *ptr << endl;
    }
    double pago_empleados() {
        double total = 0;
        for (Empleado *ptr : empleados)
            total += ptr->pago_mensual();
        return total;
    }
    double pago_empleados(string tipo_empleado) {
        double total = 0;
        for (Empleado *ptr : empleados) {
            if (ptr->get_tipo_empleado() == tipo_empleado)
                total += ptr->pago_mensual();
        }
        return total;
    }
};

#endif