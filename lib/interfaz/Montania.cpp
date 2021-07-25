#include "../../src/main.h"

Montania::Montania(int fila, int columna) : Casillero(MONTANIA, COLOR_MONTANIA, fila, columna)
{
}

/* Pre: personaje debe representar algun tipo de Ser, humano, vampiro o zombi
 * Pos: Dado el personaje, modifica el valor de lo que cuesta pasar por el casillero
 */
void Montania::ajustarCosto(string personaje)
{
    if (personaje == S_HUMANO)
        costo = 2;
    else if (personaje == S_ZOMBI || personaje == S_VAMPIRO || personaje == S_VAMPIRELLA || personaje == S_NOSFERATU)
        costo = 1;
    else if (personaje == S_HUMANO_CV || personaje == S_VANESA)
        costo = 0;
}
