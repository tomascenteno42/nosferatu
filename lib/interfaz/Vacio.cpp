#include "../../src/main.h"

Vacio::Vacio(int fila, int columna) : Casillero(VACIO, COLOR_VACIO, fila, columna)
{
}

/* Pre: personaje debe representar algun tipo de Ser, humano, vampiro o zombi
 * Pos: Dado el personaje, modifica el valor de lo que cuesta pasar por el casillero
 */
void Vacio::ajustarCosto(string personaje)
{
    costo = 15;
}