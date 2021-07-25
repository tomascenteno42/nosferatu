#include "../../src/main.h"

Lago::Lago(int fila, int columna) : Casillero(LAGO, COLOR_LAGO, fila, columna)
{
}

/* Pre: personaje debe representar algun tipo de Ser, humano, vampiro o zombi
 * Pos: Dado el personaje, modifica el valor de lo que cuesta pasar por el casillero
 */
void Lago::ajustarCosto(string personaje)
{
    if (personaje == S_ZOMBI)
        costo = 2;
    else if (personaje == S_VAMPIRO || personaje == S_NOSFERATU || personaje == S_VAMPIRELLA)
        costo = 1;
    else if(personaje == S_HUMANO || personaje == S_VANESA || personaje == S_HUMANO_CV)
        costo = 0;
}