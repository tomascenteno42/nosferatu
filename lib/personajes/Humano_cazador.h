#ifndef NOSFERATUV2_HUMANO_CAZADOR_H
#define NOSFERATUV2_HUMANO_CAZADOR_H

#include "../../src/main.h"
class Juego;
class Tablero;

class Humano_cazador : public Humano
{
public:
    /*
     * Post: Se crea el objeto listo para usarse
     *       Aumenta en 1 la cantidad de humanos cazadores existentes
     */
    Humano_cazador(int id, int fila, int columna);

    /* Humano Cazador Especial *
     * Post: Se crea el objeto, con el nombre y caracter pasado por parametros
     *       Aumenta en 1 la cantidad de humanos cazadores existentes
     */
    Humano_cazador(string nombre, char caracter, int id, int fila, int columna);

    void atacar(Juego *juego) override;

    void atacarEscopeta(Juego *juego, int idxBalas);

    void atacarAgua(Juego *juego, int idxAgua);

    void atacarEstaca(Juego *juego);

    void defender(Juego *juego) override;

    void actualizar() override;

    bool puedeAtacar();

    bool puedeDefenderse();

    /*
     * Post: decrece en 1 la cantidad de humanos cazadores existentes
     */
    ~Humano_cazador() override;
};

#endif //NOSFERATUV2_HUMANO_CAZADOR_H
