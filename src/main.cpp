#include "main.h"

int main()
{
    Grafo *mapa = new Grafo;

    ifstream archivo;
    archivo.open("archivos/tablero.txt");

    lectorCasilleros(mapa, archivo);

    mapa->mostrarGrafo();

    delete mapa;
    return 0;
}
