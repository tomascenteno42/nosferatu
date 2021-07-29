#ifndef NOSFERATUV2_NOSFERATU_H
#define NOSFERATUV2_NOSFERATU_H

#include "../../src/main.h"
class Juego;

class Nosferatu : public Vampiro
{
private:
    bool posicionValida(vector<Posicion> posiciones, int filaVampiro, int columnaVampiro);

public:
    /*
    * Post: Se crea nosferatu listo para usarse
     *      Aumenta en 1 la cantidad de Nosferatu existentes
    */
    explicit Nosferatu(int fila, int columna);

    void atacar(Juego *juego) override;

    void defender(Juego *juego) override;

    void actualizar() override;

    bool puedeAtacar();
    bool puedeDefenderse();

    /*
     * Post: decrece en 1 la cantidad de Nosferatu existentes
     */
    ~Nosferatu() override;
};

#endif //NOSFERATUV2_NOSFERATU_H
