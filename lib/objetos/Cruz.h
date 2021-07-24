#ifndef NOSFERATUV2_CRUZ_H
#define NOSFERATUV2_CRUZ_H

#include "../../src/main.h"

class Cruz : public Elemento
{
private:
    static int contador;

public:
    /*
     * Post: Se crea el objeto Cruz con nombre "Cruz" y caracter "c" y cantidad 1
     *       Aumenta la cantidad de cruces existentes en 1
     */
    Cruz(int id);

    /*
     * Post: Muestra por pantalla la informacion del objeto : nombre
     */
    void mostrarInformacion() override;

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
