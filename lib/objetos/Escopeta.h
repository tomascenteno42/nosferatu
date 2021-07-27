#ifndef NOSFERATUV2_ESCOPETA_H
#define NOSFERATUV2_ESCOPETA_H

#include "../../src/main.h"

class Escopeta : public Elemento
{
public:
    /*
     * Post: Se crea el objeto listo para usarse
     */
    Escopeta(int id, int fila, int columna);

    /*
     * Post: Muestra por pantalla la informacion del objeto: solo el nombre en este caso
     */
    void mostrarInformacion() override;

      /*
     * Post: Decrece la cantidad de escopetas existentes en 1
     */
    ~Escopeta() override;
};

#endif //NOSFERATUV2_ESCOPETA_H
