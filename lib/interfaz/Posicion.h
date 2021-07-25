#ifndef NOSFERATUV2_POSICION_H
#define NOSFERATUV2_POSICION_H

#include "../../src/main.h"

class Posicion
{
private:
    int fila;
    int columna;

public:
    /*
     * Pre: -
     * Post: se crea una posicion con fila = 0, columna = 0;
     */
    Posicion();

    /*
     * Post: se crea la posicion en pos_x
     */
    Posicion(int fila, int columna);

    /*
     * Post: devuelve la fila
     */
    int getFila();

    /*
    * Post: devuelve la columna
     */
    int getColumna();

    /*
     * Pre: nueva_fila > 0
     * Post: Se cambia la fila por nueva_fila
     */
    void cambiarFila(int nueva_fila);

    /*
     * Pre: nueva_columna > 0
     * Post: Se cambia la columna por nueva_columna
     */
    void cambiarColumna(int nueva_columna);
};

#endif //NOSFERATUV2_POSICION_H
