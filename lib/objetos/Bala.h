#ifndef NOSFERATUV2_BALA_H
#define NOSFERATUV2_BALA_H

#include "../../src/main.h"

class Bala : public Elemento
{
private:
    static int contador;

public:
    /* Pre: cantidad > 0
     * Post: Se crea el objeto listo para usarse
     */
    explicit Bala(int cantidad, int id);

    /*
     * Post: Muestra por pantalla la informacion del objeto instanciado
     *       En este caso "bala 20" , "bala 25"
     */
    void mostrarInformacion() override;

    /*
     * Post: Obtiene la cantidad de objetos Balas existentes
     */
    static int obtener_existentes();

    /*
     * Post: decrece en 1 la cantidad de objetos balas existentes
     */
    ~Bala() override;
};

#endif //NOSFERATUV2_BALA_H
