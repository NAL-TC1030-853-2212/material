#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <time.h>
using namespace std;

class Cancion {
private:
    string track;
    string artist;
    string genre;
    float rating;
public:
    Cancion(string track, string artist, string genre, float rating): 
        track{track}, artist{artist}, genre{genre}, rating{rating} {}
    friend ostream& operator<<(ostream &os, const Cancion &cancion) {
        os << cancion.track << " - " << cancion.artist << " - " << cancion.genre << " - " << cancion.rating;
        return os;
    }
    // float getRating() {
    //     return rating;
    // }
    friend class ListaReproduccion;
};

class ListaReproduccion {
private:
    string nombre;
    vector <Cancion> canciones;
public:
    ListaReproduccion(string nombre): nombre{nombre} {}
    void cargar_archivo(string nombre_archivo, bool encabezado) {
        canciones.clear(); // Si quiero eliminar las canciones que ya tenía
        ifstream archivo; // input file stream
        archivo.open(nombre_archivo);
        if (archivo.is_open()) { // Revisa si se pudo abrir el archivo
            string aux;
            string track;
            string artist;
            string genre;
            float rating;

            if (encabezado)
                getline(archivo, aux);
            
            while (archivo.good()) {
                // id, track, artist, genre, rating (orden en el archivo)
                getline(archivo, aux, ','); // Lo guardamos en aux para ignorar el id
                getline(archivo, track, ',');
                getline(archivo, artist, ',');
                getline(archivo, genre, ',');
                getline(archivo, aux);
                rating = stof(aux); // stof -> string to float

                canciones.push_back(Cancion{track, artist, genre, rating});

            }

        }
    }
    void mostrar_canciones() {
        for (Cancion cancion : canciones)
            cout << cancion << endl;
    }
    void mayor_calificacion() {
        Cancion mayor = canciones.at(0);
        for (Cancion cancion : canciones) {
            if (cancion.rating > mayor.rating)
                mayor = cancion;
        }
        cout << "La cancion con mayor rating es: " << mayor << endl;
    }
    void cancion_aleatoria() {
        srand(time(NULL));
        int posicion = rand() % canciones.size();
        cout << "Cancion al azar: " << canciones.at(posicion) << endl;
    }
    void filtro_genero(string genero) {
        cout << "Filtro por genero: " << genero << endl;
        for (Cancion cancion : canciones) {
            // if (cancion.genre == genero) // genero es exactamente igual a cancion.genre
            if (cancion.genre.find(genero) != string::npos) // genero está contenido dentro de cancion.genre
                cout << cancion << endl;
        }
    }
    void filtro_calificacion(float rating, int tipo) {
        // 0 -> menor o igual que
        // 1 -> mayor o igual que
        // 2 -> igual
        cout << "Filtro por calificacion" << endl;
        for (Cancion cancion : canciones) {
            switch(tipo) {
                case 0:
                    if (cancion.rating <= rating)
                        cout << cancion << endl;
                    break;
                case 1:
                    if (cancion.rating >= rating)
                        cout << cancion << endl;
                    break;
                case 2:
                    if (cancion.rating == rating)
                        cout << cancion << endl;
                    break;
            }
        }
    }
};

int main() {
    ListaReproduccion mi_lista{"Mi primera lista"};
    mi_lista.cargar_archivo("top50.csv", true);
    mi_lista.mostrar_canciones();
    mi_lista.mayor_calificacion();
    mi_lista.cancion_aleatoria();
    mi_lista.filtro_genero("pop");
    mi_lista.filtro_calificacion(2.92, 2);
}