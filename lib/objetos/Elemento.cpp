#include "../../src/main.h"

Elemento::Elemento(std::string nombre, char caracter, int id, int fila, int columna) : Objeto(nombre, caracter, id, fila, columna)
{
}

int Elemento::getCantidad()
{
    return this->cantidad;
}
