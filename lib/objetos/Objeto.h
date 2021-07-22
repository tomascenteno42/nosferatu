#ifndef NOSFERATUV2_OBJETO_H
#define NOSFERATUV2_OBJETO_H

#include "../../src/main.h"

class Objeto
{

protected:
    string nombre;
    char caracter;

public:
    /* Pre: -
     * Post: Se crea el objeto con el nombre y caracter pasado por parametro
     */
    explicit Objeto(string nombre, char caracter);

    /* Pre: -
     * Post: Muestra por pantalla la posicion
     */
    virtual void mostrar_informacion() = 0;

    /*
     * Post: obtiene el caracter asignado al objeto
     */
    char obtener_caracter();

    /*
     * Post: obtiene el nombre asignado al objeto
     */
    string obtener_nombre();

    /*
     *
     */
    virtual ~Objeto(){};
};

#endif //NOSFERATUV2_OBJETO_H
