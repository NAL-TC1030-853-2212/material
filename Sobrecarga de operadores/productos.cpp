#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Producto {
protected:
    int cantidad;
    float precio;
public:
    Producto(int cantidad, float precio): cantidad{cantidad}, precio{precio} {}
    virtual void imprimir() const = 0;
    friend ostream& operator<<(ostream &os, const Producto &producto) {
        producto.imprimir();
        return os;
    }
    // lhs -> left hand side
    // rhs -> right hand side
    friend float operator+(float lhs, const Producto &rhs) {
        return lhs + rhs.cantidad * rhs.precio;
    }
    friend void operator+=(float &lhs, const Producto &rhs) {
        lhs = lhs + rhs.cantidad * rhs.precio;
    }
};

class Libro: public Producto {
private:
    string titulo;
    string autor;
public:
    Libro(string titulo, string autor, int cantidad, float precio):
        Producto{cantidad, precio}, titulo{titulo}, autor{autor} {}
    virtual void imprimir() const {
        cout << titulo << " - " << autor << " - " << cantidad << " - " << precio;
    }
};

class Pelicula: public Producto {
private:
    string titulo;
    int duracion;
public:
    Pelicula(string titulo, int duracion, int cantidad, float precio):
        Producto{cantidad, precio}, titulo{titulo}, duracion{duracion} {}
    virtual void imprimir() const {
        cout << titulo << " - " << duracion << " - " << cantidad << " - " << precio;
    }
};

class Carrito {
private:
    vector <Producto *> miCarrito;
public:
    void agregar_producto(Producto *producto) {
        miCarrito.push_back(producto);
    }
    void mostrar_carrito() {
        for (Producto *ptr : miCarrito) {
            cout << *ptr << endl;
        }
    }
    float calcular_total() {
        float total = 0;
        for (Producto *ptr : miCarrito) {
            // total = total + *ptr;
            total += *ptr;
        }
        return total;
    }
};

int main() {
    Carrito carrito;
    carrito.agregar_producto(new Libro{"Astrophysics for People in a Hurry", "Neil Degrasse Tyson", 1, 500});
    carrito.agregar_producto(new Pelicula{"Top Gun", 90, 3, 200});
    carrito.agregar_producto(new Pelicula{"Back to the Future", 95, 2, 150});
    carrito.mostrar_carrito();
    float total = carrito.calcular_total();
    cout << "El total a pagar es: " << total << endl; 
}