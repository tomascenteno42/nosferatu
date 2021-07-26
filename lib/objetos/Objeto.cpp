
#include "../../src/main.h"

Objeto::Objeto(string nombre, char caracter, int id, int fila, int columna)
{
    this->nombre = nombre;
    this->caracter = caracter;
    this->id = id;
    this->fila = fila;
    this->columna = columna;
}

char Objeto::getCaracter()
{
    return this->caracter;
}

string Objeto::getNombre()
{
    return this->nombre;
}

int Objeto::getId()
{
    return this->id;
}

int Objeto::getFila()
{
    return this->fila;
}

int Objeto::getColumna()
{
    return this->columna;
}

void Objeto::setFila(int n)
{
    this->fila = n;
}

void Objeto::setColumna(int n)
{
    this->columna = n;
}