#ifndef NOSFERATUV2
#define NOSFERATUV2

#include "../../src/main.h"

class Elemento : public Objeto
{

protected:
    int cantidad = 0;

public:
    /* Pre:
     * Post: Crea el item listo para usarse con la posicion pos
     */
    explicit Elemento(string nombre, char caracter, int id, int fila, int columna);

    /*
     * Post: obtiene la cantidad del elemento (Para cruces,
     *       estacas y escopetas la cantidad es 1, para balas y agua bendita varia)
     *
     */
    int getCantidad();

    void setCantidad(int cant);
};

#endif //NOSFERATUV2
