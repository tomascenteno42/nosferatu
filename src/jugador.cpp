#include "main.h"

Jugador::Jugador(BANDO bando)
{
    this->bando = bando;
}

vector<Ser *> Jugador::getPersonajes()
{
    return personajes;
}

int Jugador::getCantidadPersonajes()
{
    return personajes.size();
}

BANDO Jugador::getBando()
{
    return bando;
}

void Jugador::agregarPersonaje(Ser *personaje)
{
    personajes.push_back(personaje);
}

void Jugador::eliminarPersonaje(int id)
{
    for (size_t i = 0; i < personajes.size(); i++)
        if (personajes.at(i)->getId() == id)
            personajes.erase(personajes.begin() + i);
}

int Jugador::personajesVivos()
{
    int personajesVivos = 0;

    for (int i = 0; i < personajes.size(); i++)
        if (!personajes.at(i)->estaMuerto())
            personajesVivos++;

    return personajesVivos;
}

bool Jugador::perdio()
{
    return personajesVivos() == 0;
}

Jugador::~Jugador()
{
    // for (size_t i = 0; i < personajes.size(); i++)
    // {
    //     delete personajes.at(i);
    // }
}