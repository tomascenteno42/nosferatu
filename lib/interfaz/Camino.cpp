#include "../../src/main.h"

Camino::Camino(int fila, int columna) : Casillero(CAMINO, COLOR_CAMINO, fila, columna)
{
}

void Camino::ajustarCosto(string personaje)
{
    costo = 1;
}