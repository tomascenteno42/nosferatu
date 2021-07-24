#include "../../src/main.h"

Lago::Lago() : Casillero("Lago", COLOR_LAGO)
{
}

int Lago::costo(char personaje)
{
    int energia = 0;
    if (personaje == C_ZOMBI)
        energia = 2;
    else if (personaje == C_VAMPIRO)
        energia = 1;
    return energia;
}

/*string Lago::devolver_color(){
    return (this -> color);
};*/