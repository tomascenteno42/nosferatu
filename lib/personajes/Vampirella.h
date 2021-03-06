#ifndef NOSFERATUV2_VAMPIRELLA_H
#define NOSFERATUV2_VAMPIRELLA_H

#include "../../src/main.h"
class Juego;

class Vampirella : public Vampiro
{
public:
    /*
     * Post: se crea el objeto listo para usarse
     *       Aumenta en 1 la cantidad de objetos vampirella existentes
     */
    Vampirella(int fila, int columna);

    void atacar(Juego *juego);

    void actualizar() override;

    void defender(Juego *juego) override;

    bool puedeAtacar();
    bool puedeDefenderse();

    bool buscarAlrededor(Juego *juego, Posicion posicion, bool puedeAtacar);

    /*
     * Post: decrece en 1 la cantidad de objetos vampirella existentes
     */
    ~Vampirella() override;
};

#endif
