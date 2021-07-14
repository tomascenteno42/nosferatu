#include <iostream>
#include "../lib/interfaz/Menu.h"
#include "../lib/estructuras/Lista.h"

using namespace std;

int main()
{
    Menu *juego = new Menu(PATH_ARCHIVO_ESTADO); // PATH EN CONSTANTES
    bool seguir_jugando = true;
    while (seguir_jugando)
    {
        juego->mostrar_opciones();
        juego->pedir_opcion();
        juego->procesar_opcion();
        seguir_jugando = juego->obtener_opcion_elegida() != 0;
    }
    delete juego;
    return 0;
}
