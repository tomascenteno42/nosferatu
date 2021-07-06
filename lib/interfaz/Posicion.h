//
// Created by Lucas Williams on 13/06/2021.
//

#ifndef NOSFERATUV2_POSICION_H
#define NOSFERATUV2_POSICION_H


class Posicion {
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
    int obtener_fila();

    /*
    * Post: devuelve la columna
     */
    int obtener_columna();

    /*
     * Pre: nueva_fila > 0
     * Post: Se cambia la fila por nueva_fila
     */
    void cambiar_fila(int nueva_fila);

    /*
     * Pre: nueva_columna > 0
     * Post: Se cambia la columna por nueva_columna
     */
    void cambiar_columna(int nueva_columna);
};


#endif //NOSFERATUV2_POSICION_H
