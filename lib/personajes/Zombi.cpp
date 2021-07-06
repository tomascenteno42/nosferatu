#include "Zombi.h"

int Zombi::contador = 0;

Zombi::Zombi() : Monstruo(S_ZOMBI, C_ZOMBI){
    Zombi::contador++;
}

int Zombi::obtener_existentes() {
    return Zombi::contador;
}

Zombi::~Zombi() {
    Zombi::contador--;
}
