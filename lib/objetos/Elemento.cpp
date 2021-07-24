#include "../../src/main.h"

Elemento::Elemento(std::string nombre, char caracter, int id) : Objeto(nombre, caracter, id)
{
}

int Elemento::obtener_cantidad()
{
    return this->cantidad;
}
