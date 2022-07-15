#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    // (-b +- sqrt(b^2 - 4ac)) / 2a
    // si la raiz es negativa
    // si a = 0
    float a = 6;
    float b = 20;
    float c = 6;

    float x1, x2;

    try {

        if (a == 0) {
            throw 10; 
        }

        if (pow(b,2) - 4*a*c < 0 ) {
            throw string{"La raiz es negativa."};
        }

        x1 = (-b + sqrt(pow(b,2) - 4*a*c )) / (2*a);
        x2 = (-b - sqrt(pow(b,2) - 4*a*c )) / (2*a);

        cout << "x1: " << x1 << endl;
        cout << "x2: " << x2 << endl;
    } catch (int e) {
        cout << "Division entre 0" << endl;
        cout << "Codigo del error es: " << e << endl;
    } catch (string e) {
        cout << e << endl;
    } catch (...) {
        cout << "Catch por default" << endl;
    }


}