#include "Vampirella.h"

int Vampirella::contador = 0;

Vampirella::Vampirella() : Vampiro(S_VAMPIRELLA, C_VAMPIRELLA){
    Vampirella::contador++;
}

int Vampirella::obtener_existentes() {
    return Vampirella::contador;
}

Vampirella::~Vampirella() {
    Vampirella::contador--;
}
