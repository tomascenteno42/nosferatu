#include "Humano_cazador.h"

using namespace std;

int Humano_cazador::contador = 0;

Humano_cazador::Humano_cazador() : Humano(S_HUMANO_CV, C_HUMANO_CV) {
    Humano_cazador::contador++;
}

Humano_cazador::Humano_cazador(std::string nombre, char caracter) : Humano(nombre, caracter) {
    Humano_cazador::contador++;
}

int Humano_cazador::obtener_existentes() {
    return Humano_cazador::contador;
}

Humano_cazador::~Humano_cazador() {
    Humano_cazador::contador--;
}
