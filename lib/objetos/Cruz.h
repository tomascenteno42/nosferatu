//
// Created by lucas on 6/5/21.
//

#ifndef NOSFERATUV2_CRUZ_H
#define NOSFERATUV2_CRUZ_H

#include "Elemento.h"
#include <iostream>

class Cruz : public Elemento {
private:
    static int contador;
public:

    /*
     * Post: Se crea el objeto Cruz con nombre "Cruz" y caracter "c" y cantidad 1
     *       Aumenta la cantidad de cruces existentes en 1
     */
    Cruz();

    /*
     * Post: Muestra por pantalla la informacion del objeto : nombre
     */
    void mostrar_informacion() override;

    /*
     * Post: Obtiene la cantidad de cruces existentes
     */
    static int obtener_existentes();

    /*
     * Post: Decrece la cantidad de cruces existentes en 1
     */
    ~Cruz() override;
};


#endif //NOSFERATUV2_CRUZ_H
