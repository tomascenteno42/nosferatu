#include "main.h"

int main()
{
    ABB<int, Objeto *> *diccionario = new ABB<int, Objeto *>();

    Juego *juego = new Juego();

    bool seguirJugando = true;

    while (!juego->menu->cerrarMenu())
    {
        juego->menu->mostrarMenu();
        juego->menu->renderizarOpcion(diccionario);
    }

    delete juego;
    delete diccionario;

    return 0;
}
