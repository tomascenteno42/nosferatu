#include "Precipicio.h"

using namespace std;


Precipicio::Precipicio() : Casillero("Precipicio", COLOR_PRECIPICIO) {
}

int Precipicio::costo(char personaje) {
    int energia = 0;
    if (personaje == C_HUMANO)
        energia = 2;
    else if (personaje == C_ZOMBI)
        energia = 1;
    return energia;
}