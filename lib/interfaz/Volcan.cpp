
#include "../../src/main.h"

Volcan::Volcan(int fila, int columna) : Casillero(VOLCAN, COLOR_VOLCAN, fila, columna)
{
}

void Volcan::ajustarCosto(string personaje)
{
    if (personaje == S_HUMANO || personaje == S_HUMANO_CV || personaje == S_VANESA)
        costo = 1;
    else if (personaje == S_VAMPIRO || personaje == S_NOSFERATU || personaje == S_VAMPIRELLA)
        costo = 2;
    else if(personaje == S_ZOMBI)
        costo = 0;
}