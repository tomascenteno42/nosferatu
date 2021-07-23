#include "Vacio.h"

using namespace std;


Vacio::Vacio() : Casillero("Vacio", COLOR_VACIO){
}

int Vacio::costo(char personaje) {
    int energia = -15;
    return energia;
}