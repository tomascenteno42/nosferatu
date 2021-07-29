#include "main.h"

int main()
{
    srand(time(NULL));
    Juego *juego = new Juego();

    while (!juego->gameOver() && !juego->cerrarMenu())
    {
        juego->mostrar();
    }

    delete juego;
    return 0;
}
