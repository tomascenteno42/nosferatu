#include "../../src/main.h"

int Vanesa::contador = 0;

Vanesa::Vanesa(int fila, int columna) : Humano_cazador(S_VANESA, C_VANESA, ID_VANESA, fila, columna)
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
