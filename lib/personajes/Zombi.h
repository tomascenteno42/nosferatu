#ifndef NOSFERATUV2_ZOMBI_H
#define NOSFERATUV2_ZOMBI_H

#include "../../src/main.h"
class Juego;

class Zombi : public Monstruo
{
private:
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

    void atacar(Juego *juego) override;

    bool buscarAlrededor(Juego *juego, Posicion posicion, bool esCorrecto);

    void actualizar() override;

    void defender(Juego *juego) override;

    bool puedeDefenderse();
    bool puedeAtacar();

    int getCantidadDeAguaBenditas();

    /*
     * Post: decrece en 1 la cantidad de objetos Zombi existentes
     */
    ~Zombi() override;
};

#endif
