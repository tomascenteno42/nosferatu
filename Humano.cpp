#include "Humano.h"
using namespace std;

int Humano::contador = 0;

Humano::Humano() : Ser(S_HUMANO, C_HUMANO) {
    Humano::contador++;
}

Humano::Humano(std::string nombre, char caracter) : Ser(nombre, caracter){
    Humano::contador++;
}

int Humano::obtener_existentes() {
    return Humano::contador;
}

Humano::~Humano() {
    Humano::contador--;
}


