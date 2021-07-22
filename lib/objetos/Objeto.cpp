
#include "../../src/main.h"

Objeto::Objeto(std::string nombre, char caracter)
{
    this->nombre = nombre;
    this->caracter = caracter;
}

char Objeto::obtener_caracter()
{
    return this->caracter;
}

std::string Objeto::obtener_nombre()
{
    return this->nombre;
}
