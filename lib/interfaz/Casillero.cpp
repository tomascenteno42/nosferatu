#include "../../src/main.h"

Casillero::Casillero(std::string tipo, std::string color)
{
    this->tipo = tipo;
    this->color = color;
}

string Casillero::obtener_color()
{
    return (this->color);
}

string Casillero::obtener_tipo()
{
    return (this->tipo);
}
