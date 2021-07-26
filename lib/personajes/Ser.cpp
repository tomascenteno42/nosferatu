#include "../../src/main.h"

Ser::Ser(string nombre, char caracter, int id, int fila, int columna) : Objeto(nombre, caracter, id, fila, columna)
{
    nombre = nombre;
    caracter = caracter;
    energia = rand() % 20;
    vida = rand() % 100 + 20;
    escudo = rand() % 2;
    fuerza = rand() % 30 + 10;
    id = id;
}

/* GETTERS */

int Ser::getEnergia()
{
    return energia;
}

int Ser::getVida()
{
    return vida;
}

int Ser::getEscudo()
{
    return escudo;
}

int Ser::getFuerza()
{
    return fuerza;
}

/* SETTERS */

void Ser::setEnergia(int e)
{
    energia = e;
}

void Ser::setVida(int v)
{
    vida = v;
}

void Ser::setEscudo(int e)
{
    escudo = e;
}

void Ser::setFuerza(int f)
{
    fuerza = f;
}

void Ser::ajustarDanio(int &danio)
{
    switch (getEscudo())
    {
    case 0:
        break;
    case 1:
        danio *= 0.9;
        break;
    case 2:
        danio *= 0.8;
        break;
    default:
        danio *= 0.2;
        break;
    }
}

bool Ser::estaMuerto()
{
    return getVida() == 0;
}

void Ser::mostrarInformacion()
{
    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Escudo: " << escudo << endl;
    cout << "Fuerza: " << fuerza << endl;
    cout << "ID: " << id << endl;
    cout << "Energia: " << energia << endl;
}

void Ser::mostrarCamino(vector<int> *camino)
{
    int tamanio = (int)camino->size();
    cout << "Camino tomado: " << endl;
    for (int i = 0; i < tamanio; i++)
        cout << camino->at(i) << "|";
    cout << endl;
}

void Ser::actualizarMapa(Grafo *mapa, Posicion origen, Posicion destino)
{
    Objeto *aux;
    aux = mapa->getCasillero(origen)->getObjeto();
    mapa->eliminarObjeto(origen);
    mapa->agregarObjeto(aux, destino);
    mapa->getCasillero(origen)->desocupar();
    mapa->getCasillero(destino)->ocupar();
}

void Ser::mover(Grafo *mapa, Posicion destino)
{
    mapa->establecerCaminos(this->getNombre());
    Posicion origen(this->getFila(), this->getColumna());
    vector<int> *camino = mapa->caminoMinimo(origen, destino, this->getEnergia());
    if (camino != nullptr)
    {
        mostrarCamino(camino);
        int costoCamino = mapa->sumarCamino(camino);
        this->energia -= costoCamino;
        actualizarMapa(mapa, origen, destino);
        delete camino;
    }
    else
        cout << "El personaje no tiene energia suficiente para llegar o todos los caminos estan bloqueados" << endl;
}
