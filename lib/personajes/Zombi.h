//
// Created by lucas on 6/5/21.
//

#ifndef NOSFERATUV2_ZOMBI_H
#define NOSFERATUV2_ZOMBI_H

#include "Monstruo.h"

class Zombi : public Monstruo{
private:
    static int contador;
public:
    /*
     * Post: Se crea el objeto listo para usarse
     *       Aumenta en 1 la cantidad de objetos Zombi existentes
     */
    Zombi();

    /*
     * Post: obtiene la cantidad de objetos Zombi existentes
     */
    static int obtener_existentes();

    /*
     * Post: decrece en 1 la cantidad de objetos Zombi existentes
     */
    ~Zombi() override;

};


#endif //NOSFERATUV2_ZOMBI_H
