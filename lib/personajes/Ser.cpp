#include "Ser.h"
using namespace std;


Ser::Ser(std::string nombre, char caracter) : Objeto(nombre, caracter) {

}

void Ser::mostrar_informacion() {
    cout << this->nombre << endl;
}
