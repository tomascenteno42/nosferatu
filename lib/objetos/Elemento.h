#ifndef NOSFERATUV2
#define NOSFERATUV2

#include "../../src/main.h"

class Elemento : public Objeto
{

protected:
    int cantidad;

public:
    /* Pre:
     * Post: Crea el item listo para usarse con la posicion pos
     */
    explicit Elemento(std::string nombre, char caracter, int id);

    /*
     * Post: obtiene la cantidad del elemento (Para cruces,
     *       estacas y escopetas la cantidad es 1, para balas y agua bendita varia)
     *
     */
    int obtener_cantidad();
};

#endif //NOSFERATUV2
