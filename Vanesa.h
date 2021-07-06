//
// Created by lucas on 6/5/21.
//

#ifndef NOSFERATUV2_VANESA_H
#define NOSFERATUV2_VANESA_H

#include "Humano_cazador.h"

class Vanesa : public Humano_cazador {
private:
    static int contador;
public:
    /*
     * Post: se crea el objeto listo para usarse
     *       Aumenta en 1 la cantidad de objetos Vanesa existentes
     */
    Vanesa();

    /*
     * Post: obtiene la cantidad de objetos Vanesa existentes
     */
    static int getContador();

    /*
     * Post: decrece en 1 la cantidad de objetos Vanesa existentes
     */
    ~Vanesa() override;
};


#endif //NOSFERATUV2_VANESA_H
