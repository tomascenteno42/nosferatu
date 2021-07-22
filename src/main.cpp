#include "main.h"

int main()
{

    Menu *juego = new Menu(PATH_ARCHIVO_ESTADO); // PATH EN CONSTANTES
    Jugador *humanos = juego->getTablero()->getJugador(0);
    Jugador *monstruos = juego->getTablero()->getJugador(1);
    cout << "HUMANOS" << endl;

    for (size_t i = 0; i < humanos->getPersonajes().size(); i++)
    {
        cout << humanos->getPersonajes().at(i)->obtener_nombre() << endl;
    }

    cout << "MONSTRUOS" << endl;

    for (size_t i = 0; i < monstruos->getPersonajes().size(); i++)
    {
        cout << monstruos->getPersonajes().at(i)->obtener_nombre() << endl;
    }

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
