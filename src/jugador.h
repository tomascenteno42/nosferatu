#ifndef JUGADOR_H
#define JUGADOR_H

#include "main.h"

class Jugador
{
private:
    vector<Objeto *> personajes;
    BANDO bando;

public:
    Jugador(BANDO bando);

    vector<Objeto *> getPersonajes();

    void agregarPersonaje(Objeto *personaje);

    /**
     * @brief Aplica las modificaciones correspondientes a cada personaje vivo
     * del jugador tras terminar un turno.
     * 
     */
    void aplicarTurno();

    /**
     * @brief Perdio si la vida de sus personajes es 0. 
     */
    bool perdio();

    ~Jugador();
};

#endif