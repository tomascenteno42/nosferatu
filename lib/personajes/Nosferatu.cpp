#include "../../src/main.h"

int Nosferatu::contador = 0;

Nosferatu::Nosferatu(int fila, int columna) : Vampiro(S_NOSFERATU, C_NOSFERATU, ID_NOSFERATU, fila ,columna)
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
