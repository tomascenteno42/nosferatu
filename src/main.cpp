#include "main.h"

int main()
{
    srand(time(NULL));
    Juego *juego = new Juego();
    ABB<int, Objeto *> *diccionario = juego->tablero->getDiccionario();

    juego->tablero->getMapa()->mostrarMapa();

    while (!juego->gameOver() && !juego->cerrarMenu())
    {

        juego->mostrar();
    }

    delete juego;

    // for (size_t i = 0; i < 5; i++)
    // {
    //     cout << "HOLA PERRI" << endl;
    //     Sleep(1000);
    // }

    return 0;
}
