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

    void atacar(Juego *juego);

    void atacarEscopeta(Tablero *tablero);

    void atacarAgua(Tablero *tablero);

    void atacarEstaca(Tablero *tablero);

    void actualizar() override;

    /*
     * Post: decrece en 1 la cantidad de humanos cazadores existentes
     */
    ~Humano_cazador() override;
};

#endif //NOSFERATUV2_HUMANO_CAZADOR_H
