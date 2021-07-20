#ifndef NOSFERATUV2_ZOMBI_H
#define NOSFERATUV2_ZOMBI_H

#include "Monstruo.h"
#include "vector"

class Zombi : public Monstruo
{
private:
    static int contador;

    int cantidadDeAguaBenditas;

public:
    /*
     * Post: Se crea el objeto listo para usarse
     *       Aumenta en 1 la cantidad de objetos Zombi existentes
     */
    Zombi();

    /**
     * @brief Aumenta la cantidad de agua benditas del inventario.
     */
    void agarrarObjeto();

    /*
     * Post: obtiene la cantidad de objetos Zombi existentes
     */
    static int obtener_existentes();

    /*
     * Post: decrece en 1 la cantidad de objetos Zombi existentes
     */
    ~Zombi() override;
};

#endif
