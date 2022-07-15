#include <iostream>
#include <string>
#include <exception>
using namespace std;

class MiExcepcion: public exception {
private:
    string mensaje;
public:
    MiExcepcion(string mensaje): mensaje{mensaje} {}
    virtual const char* what() {
        return mensaje.c_str();
    }
};

int main() {
    try {
        throw MiExcepcion{"Algo salio mal..."};
    } catch (MiExcepcion e) {
        cout << e.what() << endl;
    }
}