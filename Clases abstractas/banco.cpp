#include <iostream>
#include <string>
using namespace std;

class Servicio {
protected:
    double balance;
public:
    Servicio(double balance): balance{balance} {}
    void depositar(double cantidad) {
        balance += cantidad;
    };
    bool retirar(double cantidad) {
        if (cantidad > balance) {
            cout << "Error, saldo insuficiente." << endl;
            return false;
        } else {
            balance -= cantidad;
            return true;
        }
    }
    void imprimir_balance() {
        cout << "El balance actual es: " << balance << endl;
    }
    virtual void dummy() = 0;
};

class Cuenta: public Servicio {
public:
    Cuenta(double balance): Servicio{balance} {}
    void transferir(Cuenta &destino, double cantidad) {
        if (retirar(cantidad)) {
            destino.depositar(cantidad);
        }
    }
};

class CuentaCorriente: public Cuenta {
private:
    double topePrestamo;
public:
    CuentaCorriente(double balance, double topePrestamo): Cuenta{balance}, topePrestamo{topePrestamo} {}
    void prestamo(double cantidad) {
        if (cantidad > topePrestamo) {
            cout << "Error, su credito no fue autorizado." << endl;
        } else {
            cout << "Felicidades, se la otorgado su credito." << endl;
        }
    }
    void dummy() {}
};

class CuentaDeAhorros: public Cuenta {
private:
    float tasaInteres;
public:
    CuentaDeAhorros(double balance, float tasaInteres): Cuenta{balance}, tasaInteres{tasaInteres} {}
    void generarInteresMensual() {
        balance *= 1 + tasaInteres / 100;
    }
    void dummy() {}
};

class Inversion: public Servicio {
private:
    int plazo;
    float interes;
public:
    Inversion(double balance, int plazo, float interes): Servicio{balance}, plazo{plazo}, interes{interes} {}
    void generarInteres() {
        balance *= 1 + interes / 100;
    }
    void dummy() {}
};

int main() {
    CuentaCorriente cc{10000, 4000};
    CuentaDeAhorros ca{20000, 1.5};
    Inversion inv{30000, 90, 2};

    cc.imprimir_balance();
    cc.depositar(2000);
    cc.imprimir_balance();
    cc.retirar(15000);
    cc.imprimir_balance();
    cc.retirar(4000);
    cc.imprimir_balance();
    cc.prestamo(5000);
    cc.prestamo(2000);

    cc.transferir(ca, 50000);
    cc.transferir(ca, 1000);

    cc.imprimir_balance();
    ca.imprimir_balance();

}