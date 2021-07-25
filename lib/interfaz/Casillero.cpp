#include "../../src/main.h"

Casillero::Casillero(std::string tipo, std::string color, int fila, int columna)
{
    this->tipo = tipo;
    this->color = color;
    this->costo = 0;
    this->ocupado = false;
    this->coordenadas.cambiarFila(fila);
    this->coordenadas.cambiarColumna(columna);
    this->objeto = NULL;
}

string Casillero::obtenerColor()
{
    return (this->color);
}

string Casillero::obtenerTipo()
{
    return (this->tipo);
}

int Casillero::obtenerCosto()
{
    return (this->costo);
}

int Casillero::obtenerFila()
{
    return (this->coordenadas.getFila());
}

int Casillero::obtenerColumna()
{
    return (this->coordenadas.getColumna());
}

bool Casillero::estaOcupado()
{
    return ocupado;
}

void Casillero::ocupar()
{
    this->ocupado = true;
}

void Casillero::desocupar()
{
    this->ocupado = false;
}