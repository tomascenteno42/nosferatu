//
// Created by lucas on 6/5/21.
//

#ifndef NOSFERATUV2
#define NOSFERATUV2

#include "Objeto.h"
#include "../excepciones/Excepcion_error.h"

class Elemento : public Objeto
{

protected:
    int cantidad;

public:
    /* Pre:
     * Post: Crea el item listo para usarse con la posicion pos
     */
    explicit Elemento(std::string nombre, char caracter);

    /*
     * Post: obtiene la cantidad del elemento (Para cruces,
     *       estacas y escopetas la cantidad es 1, para balas y agua bendita varia)
     *
     */
    int obtener_cantidad();
};

#endif //NOSFERATUV2
