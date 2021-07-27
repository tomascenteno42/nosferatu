#ifndef NOSFERATUV2_ZOMBI_H
#define NOSFERATUV2_ZOMBI_H

#include "../../src/main.h"
class Juego;

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
    Zombi(int id, int fila, int columna);

    /**
     * @brief Aumenta la cantidad de agua benditas del inventario.
     */
    void agarrarObjeto();

    void atacar(Juego *juego);

    /*
     * Post: obtiene la cantidad de objetos Zombi existentes
     */
    static int obtener_existentes();

    void actualizar() override;

    /*
     * Post: decrece en 1 la cantidad de objetos Zombi existentes
     */
    ~Zombi() override;
};

#endif
