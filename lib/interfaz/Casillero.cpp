#include "Casillero.h"
#include <iostream>
using namespace std;

Casillero::Casillero(std::string tipo, std::string color) {
    this->tipo = tipo;
    this->color = color;
}

string Casillero::obtener_color() {
    return (this -> color);
}

string Casillero::obtener_tipo() {
    return (this -> tipo);
}



