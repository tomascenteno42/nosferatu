#include "Estaca.h"

using namespace std;

int Estaca::contador = 0;

Estaca::Estaca() : Elemento(S_ESTACA, C_ESTACA){
    Estaca::contador++;
}

void Estaca::mostrar_informacion() {
    cout << this->nombre << endl;
}

int Estaca::obtener_existentes() {
    return Estaca::contador;
}

Estaca::~Estaca() {
    Estaca::contador--;
}
