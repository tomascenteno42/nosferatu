#include "../../src/main.h"

Juego::Juego()
{
    tablero = new Tablero(PATH_ARCHIVO_ESTADO);
    menu = new MenuJuego(this);
}

Juego::~Juego()
{
    delete tablero;
    delete menu;
}