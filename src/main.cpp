#include "main.h"

int main()
{
    srand(time(NULL));
    Juego *juego = new Juego();
    //ABB<int, Objeto *> *diccionario = juego->tablero->getDiccionario();

    //juego->tablero->getMapa()->mostrarMapa();

    while (!juego->gameOver() && !juego->cerrarMenu())
    {

        juego->mostrar();
    }

    cout << endl;

    delete juego;

    return 0;
}
