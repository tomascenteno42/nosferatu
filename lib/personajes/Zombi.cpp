#include "../../src/main.h"

int Zombi::contador = 0;

Zombi::Zombi(int id) : Monstruo(S_ZOMBI, C_ZOMBI, id)
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
