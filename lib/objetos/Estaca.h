#ifndef NOSFERATUV2_ESTACA_H
#define NOSFERATUV2_ESTACA_H

#include "../../src/main.h"

class Estaca : public Elemento
{

public:
    /*
     * Post: Se crea el objeto listo para usarse
     *       Aumenta en 1 la cantidad de estacas existentes
     */
    Estaca(int id, int fila, int columna);

    /*
     *  Post: Muestra por pantalla la informacion. En este caso el nombre.
     */
    void mostrarInformacion() override;

    /*
     * Post: decrece en 1 la cantidad existentes de estacas
     */
    ~Estaca() override;
};

#endif //NOSFERATUV2_ESTACA_H
