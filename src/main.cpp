#include "main.h"

int main()
{
    srand(time(NULL));

    /*Humano *h = new Humano(1, 5, 6);
    Zombi *zombi = new Zombi(105, 4, 5);
    Zombi *zombi1 = new Zombi(106, 4, 6);
    Zombi *zombi2 = new Zombi(107, 4, 7);
    Zombi *zombi3 = new Zombi(108, 5, 7);
    Zombi *zombi4 = new Zombi(109, 6, 5);
    Vampiro *vampiro = new Vampiro(208, 5, 5);
    h->setEnergia(20);
    Humano_cazador *tuVieja = new Humano_cazador(54, 5,6);
    Elemento *escopeta = new Escopeta(345,0, 5);
    Elemento *balas = new Bala(5, 360, 0, 5);
    Elemento *aguas = new Agua_bendita(2, 304, 0,5);
    Elemento *estaca = new Estaca(400, 0, 5);
    tuVieja->agarrarObjeto(escopeta);
    tuVieja->agarrarObjeto(balas);
    tuVieja->agarrarObjeto(aguas);
    tuVieja->agarrarObjeto(estaca);*/
    Nosferatu *nosferatu = new Nosferatu(9,9);
    Juego *juego = new Juego();
    //ABB<int, Objeto *> *diccionario = juego->tablero->getDiccionario();

    /*juego->tablero->darDeAlta(Posicion(5, 6), h);
    juego->tablero->darDeAlta(Posicion(4, 5), zombi);
    juego->tablero->darDeAlta(Posicion(4, 6), zombi1);
    juego->tablero->darDeAlta(Posicion(4, 7), zombi2);
    juego->tablero->darDeAlta(Posicion(5, 7), zombi3);
    juego->tablero->darDeAlta(Posicion(6, 5), zombi4);
    juego->tablero->darDeAlta(Posicion(5,6), tuVieja);
    juego->tablero->darDeAlta(Posicion(5,5), vampiro);*/

    //diccionario->insertar(tuVieja->getId(), tuVieja);
    //tuVieja->atacar(juego->tablero);
    nosferatu->atacar(juego->tablero);
    while (!juego->gameOver() && !juego->cerrarMenu())
    {
    juego->tablero->getMapa()->mostrarMapa();

    while (!juego->menu->cerrarMenu())
    {
        juego->menu->mostrarMenu();
        juego->menu->renderizarOpcion(diccionario);
    }
        juego->mostrar();
    }

    cout << endl;

    delete juego;
    /*delete escopeta;
    delete balas;
    delete estaca;
    delete aguas;*/
    return 0;
    /*Juego *juego = new Juego();
    ABB<int, Objeto *> *diccionario = juego->tablero->getDiccionario();

    diccionario->imprimirEnOrden();
    diccionario->eliminar(201);
    diccionario->imprimirEnOrden();

    // juego->tablero->getMapa()->mostrarMapa();

    // while (!juego->menu->cerrarMenu())
    // {
    //     juego->menu->mostrarMenu();
    //     juego->menu->renderizarOpcion(diccionario);
    // }

    delete juego;
    return 0;*/
}
