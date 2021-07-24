
#include "../../src/main.h"

Objeto::Objeto(std::string nombre, char caracter, int id)
{
    this->nombre = nombre;
    this->caracter = caracter;
    this->id = id;
}

char Objeto::getCaracter()
{
    return this->caracter;
}

std::string Objeto::getNombre()
{
    return this->nombre;
}

int Objeto::getId()
{
    return this->id;
}