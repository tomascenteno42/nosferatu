#include "Cruz.h"

using namespace std;

int Cruz::contador = 0;

Cruz::Cruz() : Elemento(S_CRUZ, C_CRUZ){
    this->cantidad = 1;
    Cruz::contador++;
}

void Cruz::mostrar_informacion() {
    cout << this->nombre << endl;
}

Cruz::~Cruz() {
    Cruz::contador--;
}

int Cruz::obtener_existentes() {
    return Cruz::contador;
}

