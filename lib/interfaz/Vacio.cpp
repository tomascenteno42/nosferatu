#include "../../src/main.h"

Vacio::Vacio(int fila, int columna) : Casillero(VACIO, COLOR_VACIO, fila, columna)
{
}

void Vacio::ajustarCosto(string personaje)
{
    costo = 15;
}