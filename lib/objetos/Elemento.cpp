#include "../../src/main.h"

Elemento::Elemento(string nombre, char caracter, int id, int fila, int columna) : Objeto(nombre, caracter, id, fila, columna)
{
}

void Elemento::setCantidad(int cant)
{
    this->cantidad = cant;
}

int Elemento::getCantidad()
{
    return this->cantidad;
}
