#include "../../src/main.h"

Precipicio::Precipicio(int fila, int columna) : Casillero(PRECIPICIO, COLOR_PRECIPICIO, fila, columna)
{
}

void Precipicio::ajustarCosto(string personaje)
{
    if (personaje == S_HUMANO || personaje == S_VANESA || personaje == S_HUMANO_CV)
        costo = 2;
    else if (personaje == S_ZOMBI)
        costo = 1;
    else if(personaje == S_VAMPIRO || personaje == S_VAMPIRELLA || personaje == S_NOSFERATU)
        costo = 0;
}