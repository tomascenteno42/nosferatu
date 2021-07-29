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
//[¬º-°]¬ ح(-̀ж-́)ง † (ノಠ ∩ಠ)ノ彡( \o°o)\N
//(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ “ヽ(´▽｀)ノ” ᕕ(⌐■_■)ᕗ ♪♬