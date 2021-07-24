#include "../../src/main.h"

Montania::Montania() : Casillero("Montania", COLOR_MONTANIA)
{
}

int Montania::costo(char personaje)
{
    int energia = 0;
    if (personaje == C_HUMANO)
        energia = 2;
    else if (personaje == C_ZOMBI || personaje == C_VAMPIRO)
        energia = 1;
    return energia;
}
