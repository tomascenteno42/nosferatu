#include "../../src/main.h"

int Vanesa::contador = 0;

Vanesa::Vanesa() : Humano_cazador(S_VANESA, C_VANESA, ID_VANESA)
{
    Vanesa::contador++;
}

int Vanesa::getContador()
{
    return Vanesa::contador;
}

Vanesa::~Vanesa()
{
    Vanesa::contador--;
}
