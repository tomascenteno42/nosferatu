
#include "Volcan.h"

using namespace std;


Volcan::Volcan() : Casillero("Volcan", COLOR_VOLCAN) {
}

int Volcan::costo(char personaje) {
    int energia = 0;
    if (personaje == C_HUMANO)
        energia = 1;
    else if (personaje == C_VAMPIRO)
        energia = 1;
    return energia;
}