#include "Bala.h"
using namespace std;

int Bala::contador = 0;

Bala::Bala(int cantidad) : Elemento(S_BALA, C_BALAS){
    if(cantidad <= 0){
        throw Excepcion_error("no se puede asignar una cantidad menor o igual a 0");
    } else {
        this->cantidad = cantidad;
        Bala::contador+= cantidad;
    }
}

void Bala::mostrar_informacion() {
    cout << this->nombre << ", " << this->cantidad << endl;
}

int Bala::obtener_existentes() {
    return Bala::contador;
}

Bala::~Bala() {
    Bala::contador-= this->cantidad;
}

