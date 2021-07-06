#include "Elemento.h"

Elemento::Elemento(std::string nombre, char caracter) : Objeto(nombre, caracter){

}

int Elemento::obtener_cantidad() {
    return this->cantidad;
}
