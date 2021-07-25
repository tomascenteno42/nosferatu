#include "main.h"

int main()
{

    Humano *h = new Humano(1, 1, 1);
    h->setEnergia(20);
    Juego *juego = new Juego();
    ABB<int, Objeto *> *diccionario = juego->tablero->getDiccionario();

    juego->tablero->darDeAlta(Posicion(1, 1), h);

    diccionario->insertar(h->getId(), h);

    h->atacar(juego->tablero);

    juego->tablero->getMapa()->mostrarMapa();

    while (!juego->menu->cerrarMenu())
    {
        juego->menu->mostrarMenu();
        juego->menu->renderizarOpcion(diccionario);
    }

    delete juego;
    return 0;
}
