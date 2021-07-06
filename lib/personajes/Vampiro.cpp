#include "Vampiro.h"

int Vampiro::contador = 0;

Vampiro::Vampiro() : Monstruo(S_VAMPIRO, C_VAMPIRO){
    Vampiro::contador++;
}

Vampiro::Vampiro(std::string nombre, char caracter) : Monstruo(nombre, caracter) {
    Vampiro::contador++;
}

int Vampiro::obtener_existentes() {
    return Vampiro::contador;
}

Vampiro::~Vampiro() {
    Vampiro::contador--;
}
