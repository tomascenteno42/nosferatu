//
// Created by lucas on 6/5/21.
//

#ifndef NOSFERATUV2_EXCEPCION_ERROR_H
#define NOSFERATUV2_EXCEPCION_ERROR_H

#include <string>
#include <iostream>
#include <exception>

class Excepcion_error : public std::exception {

private:
    unsigned int posicion;
    std::string descripcion;

public:
    Excepcion_error(unsigned int posicion);

    Excepcion_error(std::string error);

    unsigned int obtenerPosicionInvalida();

    std::string obtenerDescripcion();


};


#endif //NOSFERATUV2_EXCEPCION_ERROR_H
