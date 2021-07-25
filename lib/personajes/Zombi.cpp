#include "../../src/main.h"

int Zombi::contador = 0;

Zombi::Zombi(int id, int fila, int columna) : Monstruo(S_ZOMBI, C_ZOMBI, id, fila, columna)
{
    Zombi::contador++;
    cantidadDeAguaBenditas = 0;
}

void Zombi::agarrarObjeto()
{
    cantidadDeAguaBenditas++;
}

int Zombi::obtener_existentes()
{
    return Zombi::contador;
}

Zombi::~Zombi()
{
    Zombi::contador--;
}
