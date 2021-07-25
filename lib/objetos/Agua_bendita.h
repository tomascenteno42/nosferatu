#ifndef NOSFERATUV2_AGUA_BENDITA_H
#define NOSFERATUV2_AGUA_BENDITA_H

#include "../../src/main.h"

class Agua_bendita : public Elemento
{

private:
    int cantidad;
    static int contador;

public:
    /* Pre: cantidad > 0
     * Post: item agua_bendita listo para usarse con la cantidad pasada por parametro
     *       Aumenta la cantidad de aguas existentes en 1
     */
    explicit Agua_bendita(int cantidad, int id, int fila, int columna);

    /*
     * Post: Se muestra por pantalla la informacion del objeto: Nombre y cantidad
     */
    void mostrarInformacion() override;

    /*
     * Post: Obtiene la cantidad de agua benditas existentes
     */
    static int obtener_existentes();

    /*
     * Post: Decrece la cantidad de existentes en 1
     */
    ~Agua_bendita() override;
};

#endif //NOSFERATUV2_AGUA_BENDITA_H
