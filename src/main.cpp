#include "main.h"

int main()
{
//
//    Humano *h = new Humano(1, 1, 1);
//    h->setEnergia(20);
//    Juego *juego = new Juego();
//    ABB<int, Objeto *> *diccionario = juego->tablero->getDiccionario();
//
//    juego->tablero->darDeAlta(Posicion(1, 1), h);
//
//    diccionario->insertar(h->getId(), h);
//
//    h->atacar(juego->tablero);
//
//    juego->tablero->getMapa()->mostrarMapa();
//
//    while (!juego->menu->cerrarMenu())
//    {
//        juego->menu->mostrarMenu();
//        juego->menu->renderizarOpcion(diccionario);
//    }
//
//    delete juego;
    Grafo* mapa = new Grafo;
    ifstream datos;
    datos.open("archivos/tablero.txt");
    if(!datos){
        cout << "No se encontro el archivo" << endl;
        return -1;
    }
    cargarCasillerosGrafo(mapa, datos);

    Objeto* humano = new Humano(1, 1,3);
    Posicion origen(1,3);
    Posicion destino(3, 1);
    mapa->agregarObjeto(humano, origen);

    Objeto* personaje = mapa->getCasillero(origen)->getObjeto();
    Ser* nuevo = dynamic_cast<Ser *>(personaje);
    nuevo->setEnergia(80);
    nuevo->mostrarInformacion();
    mapa->mostrarMapa();
    nuevo->mover(mapa, destino);
//    mapa->establecerCaminos(S_ZOMBI);
//    vector<int>* camino = mapa->caminoMinimo(Posicion(nuevo->getFila(), nuevo->getColumna()), destino, nuevo->getEnergia());

//    if(camino != nullptr){
//        for(int i = 0; i < (int)camino->size(); i++)
//            cout << camino->at(i) << "|";
//    }
//    cout << endl;

//    mapa->mostrarGrafo();
    nuevo->mostrarInformacion();
    mapa->mostrarMapa();


    delete mapa;

    return 0;
}
