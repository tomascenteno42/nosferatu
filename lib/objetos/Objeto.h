#ifndef NOSFERATUV2_OBJETO_H
#define NOSFERATUV2_OBJETO_H

#include "../../src/main.h"

class Objeto
{

protected:
    string nombre;
    char caracter;
    int id;

public:
    /* Pre: -
     * Post: Se crea el objeto con el nombre y caracter pasado por parametro
     */
    explicit Objeto(string nombre, char caracter, int id);

    /* Pre: -
     * Post: Muestra por pantalla la posicion
     */
    virtual void mostrarInformacion() = 0;

    /*
     * Post: obtiene el caracter asignado al objeto
     */
    char getCaracter();

    /*
     * Post: obtiene el nombre asignado al objeto
     */
    string getNombre();

    /**
     * @brief Obtiene el id del objeto.
     * 
     * @return int 
     */
    int getId();
    /*
     *
     */
    virtual ~Objeto(){};
};

#endif //NOSFERATUV2_OBJETO_H
