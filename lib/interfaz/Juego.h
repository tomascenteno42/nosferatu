#ifndef JUEGO_H_
#define JUEGO_H_

#include "../../src/main.h"

class MenuJuego;
class Tablero;

class Juego
{
public:
    Tablero *tablero;
    MenuJuego *menu;

    Juego();

    ~Juego();
};

#endif