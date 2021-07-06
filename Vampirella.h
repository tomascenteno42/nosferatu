//
// Created by lucas on 6/5/21.
//

#ifndef NOSFERATUV2_VAMPIRELLA_H
#define NOSFERATUV2_VAMPIRELLA_H

#include "Vampiro.h"

class Vampirella : public Vampiro{
private:
    static int contador;
public:

    /*
     * Post: se crea el objeto listo para usarse
     *       Aumenta en 1 la cantidad de objetos vampirella existentes
     */
    Vampirella();

    /*
     * Post: obtiene la cantidad de objetos vampirella existentes
     */
    static int obtener_existentes();

    /*
     * Post: decrece en 1 la cantidad de objetos vampirella existentes
     */
    ~Vampirella() override;
};


#endif //NOSFERATUV2_VAMPIRELLA_H
