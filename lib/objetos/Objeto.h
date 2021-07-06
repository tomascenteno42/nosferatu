//
// Created by lucas on 6/5/21.
//

#ifndef NOSFERATUV2_OBJETO_H
#define NOSFERATUV2_OBJETO_H

#include <iostream>
#include "../../Constantes.h"
#include "../excepciones/Excepcion_error.h"

class Objeto
{

protected:
    //atributos
    std::string nombre;
    char caracter;

public:
    /* Pre: -
     * Post: Se crea el objeto con el nombre y caracter pasado por parametro
     */
    explicit Objeto(std::string nombre, char caracter);

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
    std::string obtener_nombre();

    /*
     *
     */
    virtual ~Objeto(){};
};

#endif //NOSFERATUV2_OBJETO_H
