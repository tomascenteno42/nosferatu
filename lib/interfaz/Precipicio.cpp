#include "../../src/main.h"

Precipicio::Precipicio(int fila, int columna) : Casillero(PRECIPICIO, COLOR_PRECIPICIO, fila, columna)
{
}

/* Pre: personaje debe representar algun tipo de Ser, humano, vampiro o zombi
 * Pos: Dado el personaje, modifica el valor de lo que cuesta pasar por el casillero
 */
void Precipicio::ajustarCosto(string personaje)
{
    if (personaje == S_HUMANO || personaje == S_VANESA || personaje == S_HUMANO_CV)
        costo = 2;
    else if (personaje == S_ZOMBI)
        costo = 1;
    else if(personaje == S_VAMPIRO || personaje == S_VAMPIRELLA || personaje == S_NOSFERATU)
        costo = 0;
}