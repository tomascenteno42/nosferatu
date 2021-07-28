#ifndef NOSFERATUV2_VANESA_H
#define NOSFERATUV2_VANESA_H

#include "../../src/main.h"
class Juego;
class Tablero;

class Vanesa : public Humano_cazador
{
private:
    static int contador;

    bool defenderConAgua(Juego* juego);

    bool posicionValida(vector<Posicion> posiciones, int fila, int columna);

public:
    /*
     * Post: se crea el objeto listo para usarse
     *       Aumenta en 1 la cantidad de objetos Vanesa existentes
     */
    Vanesa(int fila, int columna);

    /*
     * Post: obtiene la cantidad de objetos Vanesa existentes
     */
    static int getContador();

    void atacar(Juego *juego);

    void atacarEscopeta(Juego *juego, int idxBalas);

    void atacarAgua(Juego *juego, int idxAgua);

    void atacarEstaca(Juego *juego);

    void actualizar() override;

    bool defender(Juego* juego) override;

    /*
     * Post: decrece en 1 la cantidad de objetos Vanesa existentes
     */
    ~Vanesa() override;
};

#endif //NOSFERATUV2_VANESA_H
