#ifndef NOSFERATUV2_ESCOPETA_H
#define NOSFERATUV2_ESCOPETA_H

#include "../../src/main.h"

class Escopeta : public Elemento
{
private:
    static int contador;

public:
    /*
     * Post: Se crea el objeto listo para usarse
     */
    Escopeta();

    /*
     * Post: Muestra por pantalla la informacion del objeto: solo el nombre en este caso
     */
    void mostrar_informacion() override;

    /*
    * Post: Aumenta la cantidad de escopetas existentes en 1
    */
    static int obtener_existentes();

    /*
     * Post: Decrece la cantidad de escopetas existentes en 1
     */
    ~Escopeta() override;
};

#endif //NOSFERATUV2_ESCOPETA_H
