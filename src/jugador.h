#ifndef JUGADOR_H
#define JUGADOR_H

#include "main.h"

class Jugador
{
private:
    vector<Ser *> personajes;
    BANDO bando;

public:
    Jugador(BANDO bando);

    vector<Ser *> getPersonajes();
    int getCantidadPersonajes();

    BANDO getBando();

    void agregarPersonaje(Ser *personaje);

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

    /**
     * @brief Devuelve cuantos personajes vivos tiene el jugador.
     *  
     */
    int personajesVivos();

    ~Jugador();
};

#endif