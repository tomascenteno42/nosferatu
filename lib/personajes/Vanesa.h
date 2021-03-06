#ifndef NOSFERATUV2_VANESA_H
#define NOSFERATUV2_VANESA_H

#include "../../src/main.h"
class Juego;
class Tablero;

class Vanesa : public Humano_cazador
{
private:
    bool defenderConAgua(Juego *juego);

    bool posicionValida(vector<Posicion> posiciones, int fila, int columna);

public:
    /*
     * Post: se crea el objeto listo para usarse
     *       Aumenta en 1 la cantidad de objetos Vanesa existentes
     */
    Vanesa(int fila, int columna);

    void atacar(Juego *juego);

    void atacarEscopeta(Juego *juego, int idxBalas);

    void atacarAgua(Juego *juego, int idxAgua);

    void atacarEstaca(Juego *juego);

    bool buscarAlrededor(Juego *juego, Posicion posicion, bool puedeAtacar);

    void actualizar() override;

    void defender(Juego *juego) override;

    bool puedeAtacar();
    bool puedeDefenderse();

    /*
     * Post: decrece en 1 la cantidad de objetos Vanesa existentes
     */
    ~Vanesa() override;
};

#endif //NOSFERATUV2_VANESA_H
