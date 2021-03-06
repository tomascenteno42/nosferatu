#include "../../src/main.h"

Excepcion_error::Excepcion_error(unsigned int posicion)
{
    this->posicion = posicion;
    this->descripcion = "Se intento acceder a una posicion no valida dentro de una lista (unsigned int)";
}

Excepcion_error::Excepcion_error(string error)
{
    this->posicion = 0;
    this->descripcion = error;
}

unsigned int Excepcion_error::obtenerPosicionInvalida()
{
    return this->posicion;
}

string Excepcion_error::obtenerDescripcion()
{
    return this->descripcion;
}
