#include "../../src/main.h"

int Nosferatu::contador = 0;

Nosferatu::Nosferatu() : Vampiro(S_NOSFERATU, C_NOSFERATU)
{
    Nosferatu::contador++;
}

int Nosferatu::obtener_existentes()
{
    return Nosferatu::contador;
}

Nosferatu::~Nosferatu()
{
    Nosferatu::contador--;
}
