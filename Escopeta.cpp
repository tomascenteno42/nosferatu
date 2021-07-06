#include "Escopeta.h"

using namespace std;

int Escopeta::contador = 0;

Escopeta::Escopeta() : Elemento(S_ESCOPETA, C_ESCOPETA) {
    Escopeta::contador++;
}

void Escopeta::mostrar_informacion() {
    cout << this->nombre << endl;
}

int Escopeta::obtener_existentes() {
    return Escopeta::contador;
}

Escopeta::~Escopeta() {
    Escopeta::contador--;
}
