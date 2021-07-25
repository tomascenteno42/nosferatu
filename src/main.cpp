#include "main.h"

int main()
{
    Juego *juego = new Juego();
    ABB<int, Objeto *> *diccionario = juego->tablero->getDiccionario();

    while (!juego->menu->cerrarMenu())
    {
        juego->menu->mostrarMenu();
        juego->menu->renderizarOpcion(diccionario);
    }

    delete juego;
    return 0;
}
