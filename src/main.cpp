#include "main.h"

int main()
{
    srand(time(NULL));
    Juego *juego = new Juego();

    while (!juego->gameOver() && !juego->cerrarMenu())
    {
        juego->mostrar();
    }

    if (juego->gameOver())
    {
        clearTerminal();
        juego->tablero->getMapa()->mostrarMapa();

        cout << endl
             << endl;
        cout << "GAME OVER!" << endl;

        if (juego->tablero->getJugador(0)->perdio())
            cout << "Gano el bando de los Monstruos!!!!!!!" << endl;
        else
            cout << "Gano el bando de los Humanos!!!!!!!" << endl;
    }

    delete juego;

    return 0;
}
//[¬º-°]¬ ح(-̀ж-́)ง † (ノಠ ∩ಠ)ノ彡( \o°o)\N
//(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ “ヽ(´▽｀)ノ” ᕕ(⌐■_■)ᕗ ♪♬