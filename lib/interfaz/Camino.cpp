#include "../../src/main.h"

Camino::Camino(int fila, int columna) : Casillero(CAMINO, COLOR_CAMINO, fila, columna)
{
}


/* Pre: personaje debe representar algun tipo de Ser, humano, vampiro o zombi
 * Pos: Dado el personaje, modifica el valor de lo que cuesta pasar por el casillero
 */
void Camino::ajustarCosto(string personaje)
{
    costo = 1;
}