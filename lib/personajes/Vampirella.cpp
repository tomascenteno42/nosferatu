#include "../../src/main.h"

int Vampirella::contador = 0;

Vampirella::Vampirella(int fila, int columna) : Vampiro(S_VAMPIRELLA, C_VAMPIRELLA, ID_VAMPIRELLA, fila, columna)
{
    Vampirella::contador++;
}

int Vampirella::obtener_existentes()
{
    return Vampirella::contador;
}

Vampirella::~Vampirella()
{
    Vampirella::contador--;
}
