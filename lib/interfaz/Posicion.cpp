#include "../../src/main.h"

Posicion::Posicion(int fila, int columna)
{
    this->fila = fila;
    this->columna = columna;
}

int Posicion::getFila()
{
    return this->fila;
}

int Posicion::getColumna()
{
    return this->columna;
}

void Posicion::cambiarFila(int nueva_fila)
{
    this->fila = nueva_fila;
}

void Posicion::cambiarColumna(int nueva_columna)
{
    this->columna = nueva_columna;
}

Posicion::Posicion()
{
    this->columna = 0;
    this->fila = 0;
}
