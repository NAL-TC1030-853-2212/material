#include <iostream>
#include <string>
#include "empresa.h"
#include "asalariado.h"
#include "porhora.h"
#include "practicante.h"
using namespace std;

int main() {
    Empresa miEmpresa{};
    miEmpresa.agrega_asalariado("Juan", 20000);
    miEmpresa.agrega_asalariado("Pedro", 25000);

    miEmpresa.agrega_por_hora("Rosa", 48, 300);
    miEmpresa.agrega_por_hora("Rodrigo", 25, 200);

    miEmpresa.agrega_practicante("Rodolfo", 40, 250, 35);
    miEmpresa.agrega_practicante("Mar", 35, 400, 55);

    miEmpresa.agrega_empleado(new Asalariado{"Alejandro", 13000});
    miEmpresa.agrega_empleado(new PorHora{"Fernanda", 36, 1000});
    miEmpresa.agrega_empleado(new Practicante{"Jessica", 42, 700, 30});

    double pago;
    pago = miEmpresa.pago_empleados();
    cout << "La empresa debe pagar en total: " << pago << " al mes." << endl;

    pago = miEmpresa.pago_empleados("Asalariado");
    cout << "La empresa debe pagar en total: " << pago << " a los asalariados al mes." << endl;

    pago = miEmpresa.pago_empleados("Por hora");
    cout << "La empresa debe pagar en total: " << pago << " a los empleados por hora al mes." << endl;

    pago = miEmpresa.pago_empleados("Practicante");
    cout << "La empresa debe pagar en total: " << pago << " a los practicantes al mes." << endl;

    cout << "Listado de empleados:" << endl;    
    miEmpresa.imprime_empleados();

}