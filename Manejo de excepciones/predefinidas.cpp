#include <iostream>
#include <string>
#include <exception>
using namespace std;

int main() {
    try {
        throw bad_cast{};
    } catch (bad_cast e) {
        cout << e.what() << endl;
    }
}