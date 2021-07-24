#include "../../src/main.h"

Vacio::Vacio() : Casillero("Vacio", COLOR_VACIO)
{
}

int Vacio::costo(char personaje)
{
    int energia = -15;
    return energia;
}