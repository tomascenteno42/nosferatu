#ifndef NOSFERATUV2_EXCEPCION_ERROR_H
#define NOSFERATUV2_EXCEPCION_ERROR_H

#include "../../src/main.h"

class Excepcion_error : public exception
{

private:
    unsigned int posicion;
    string descripcion;

public:
    Excepcion_error(unsigned int posicion);

    Excepcion_error(string error);

    unsigned int obtenerPosicionInvalida();

    string obtenerDescripcion();
};

#endif //NOSFERATUV2_EXCEPCION_ERROR_H
