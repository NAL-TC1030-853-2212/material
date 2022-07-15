#include <iostream>
#include <string>
#include <vector>
#include <exception>
using namespace std;

int main() {
    vector <int> v;
    v.push_back(1);
    v.push_back(5);
    v.push_back(98);

    try {
        v.at(4);
    } catch (out_of_range e) {
        cout << "Se genero una exepcion" << endl;
        cout << e.what() << endl;
    }

}