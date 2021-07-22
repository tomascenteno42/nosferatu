#include "main.h"

Jugador::Jugador(BANDO bando)
{
    this->bando = bando;
}

vector<Objeto *> Jugador::getPersonajes()
{
    return personajes;
}

void Jugador::agregarPersonaje(Objeto *personaje)
{
    personajes.push_back(personaje);
}

Jugador::~Jugador()
{
    // for (size_t i = 0; i < personajes.size(); i++)
    // {
    //     delete personajes.at(i);
    // }
}