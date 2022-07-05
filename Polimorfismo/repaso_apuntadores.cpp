#include <iostream>
#include <string>
using namespace std;

void intercambiar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
};

void intercambiar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
};

int main() {
    int a = 10;
    int &b = a;
    int *ptr_a = &a;
    int **ptr_ptr_a = &ptr_a; 

    cout << "a: " << a << endl; // variable a
    cout << "&a: " << &a << endl; // direccion en memoria en donde se encuentra a

    cout << "ptr_a: " << ptr_a << endl; // direccion en memoria en donde se encuentra a
    cout << "&ptr_a: " << &ptr_a << endl; // direccion en memoria en donde se encuentra ptr_a
    cout << "*ptr_a: " << *ptr_a << endl; // contenido de la direccion en memoria hacia la que apunta ptr_a

    *ptr_a = 20;

    cout << "a: " << a << endl;
    cout << "&a: " << &a << endl;
    cout << "ptr_a: " << ptr_a << endl;
    cout << "*ptr_a: " << *ptr_a << endl;

    int x = 30;
    int y = 50;

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;

    intercambiar(x ,y);

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;


}