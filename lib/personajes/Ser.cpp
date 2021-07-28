#include "../../src/main.h"

Ser::Ser(string nombre, char caracter, int id, int fila, int columna) : Objeto(nombre, caracter, id, fila, columna)
{
    nombre = nombre;
    caracter = caracter;
    energia = rand() % (MAX_ENERGIA + 1);
    vida = rand() % (MAX_VIDA + 1) + 20;
    escudo = rand() % (MAX_ESCUDO + 1);
    fuerza = rand() % (MAX_FUERZA - 10 + 1) + 10;
    id = id;
    seDefendio = false;
    contadorTurnos = 0;
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

void Ser::ajustarDanio(int &danio, int escudo)
{
    switch (escudo)
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
    return getVida() <= 0;
}

bool Ser::seEstaDefendiendo()
{
    return seDefendio;
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

void Ser::actualizarMapa(Grafo *mapa, Posicion origen, Posicion destino)
{
    Objeto *aux;
    aux = mapa->getCasillero(origen)->getObjeto();
    mapa->agregarObjeto(aux, destino);
    mapa->eliminarObjeto(origen);
    mapa->getCasillero(origen)->desocupar();
    mapa->getCasillero(destino)->ocupar();
    this->setFila(destino.getFila());
    this->setColumna(destino.getColumna());
}

void Ser::chequearCamino(Grafo *mapa, vector<int> *camino, string nombre)
{
    int tamanio = (int)camino->size();
    Objeto *objetoLeido;
    string tipoLeido;
    Ser *ser = this;
    if (nombre == S_HUMANO || nombre == S_HUMANO_CV || nombre == S_VANESA)
    {
        Humano *humano = dynamic_cast<Humano *>(ser);

        Casillero *casillero;
        for (int i = 0; i < tamanio; i++)
        {
            casillero = mapa->getCasillero(camino->at(i));
            objetoLeido = casillero->getObjeto();
            if (objetoLeido != nullptr)
            {
                tipoLeido = objetoLeido->getNombre();
                if (tipoLeido == S_AGUA_BENDITA || tipoLeido == S_BALA || tipoLeido == S_CRUZ || tipoLeido == S_ESCOPETA || tipoLeido == S_ESTACA)
                {
                    Elemento *elemento = dynamic_cast<Elemento *>(objetoLeido);
                    humano->agarrarObjeto(elemento);
                    casillero->eliminarObjeto();
                }
            }
        }
    }
    else if (nombre == S_ZOMBI)
    {
        Casillero *casillero;
        for (int i = 0; i < tamanio; i++)
        {
            casillero = mapa->getCasillero(camino->at(i));
            objetoLeido = casillero->getObjeto();
            if (objetoLeido != nullptr)
            {
                tipoLeido = objetoLeido->getNombre();
                if (tipoLeido == S_AGUA_BENDITA)
                {
                    Agua_bendita *agua = dynamic_cast<Agua_bendita *>(objetoLeido);
                    Zombi *zombi = dynamic_cast<Zombi *>(ser);
                    int cantidadAguas = agua->getCantidad();
                    for (int j = 0; j < cantidadAguas; j++)
                        zombi->agarrarObjeto();
                }
            }
        }
    }
    else if (nombre == S_VAMPIRELLA || nombre == S_NOSFERATU || nombre == S_VAMPIRO){
        Casillero* casillero;
        for (int i = 0; i < tamanio; i++){
            casillero = mapa->getCasillero(camino->at(i));
            objetoLeido = casillero->getObjeto();
            if(objetoLeido != nullptr){
                tipoLeido = objetoLeido->getNombre();
                if(tipoLeido == S_ESTACA)
                    casillero->eliminarObjeto();
            }

        }
    }
}

void Ser::imprimirCamino(Grafo* mapa, vector<Posicion>* posiciones, Ser* ser)
{
    int tamanio = (int)posiciones->size();
    Casillero* casillero;
    Objeto* personaje;
    Objeto* anterior;                       // objeto que estaba antes en el casillero
    personaje = dynamic_cast<Objeto*>(ser);
    for(int i = 0; i < tamanio - 1; i++){
        clearTerminal();
        casillero = mapa->getCasillero(posiciones->at(i));
        anterior = casillero->getObjeto();
        casillero->setObjeto(personaje);
        mapa->mostrarMapa();
        Sleep(600)
        casillero->eliminarObjeto();
        casillero->desocupar();

        if(anterior != nullptr){
            casillero->setObjeto(anterior);
        }
    }


}

bool Ser::mover(Grafo *mapa, Posicion destino) {
    bool seMovio = false;
    Posicion origen(this->getFila(), this->getColumna());

    mapa->establecerCaminos(this->getNombre());
    vector<int> *camino = mapa->caminoMinimo(origen, destino, this->getEnergia());

    if (camino != nullptr) {
        int costoCamino = mapa->sumarCamino(camino);
        this->energia -= costoCamino;

        chequearCamino(mapa, camino, this->nombre);
        actualizarMapa(mapa, origen, destino);
        vector <Posicion> *posiciones;

        posiciones = obtenerPosiciones(mapa, camino);
        reverse(posiciones->begin(), posiciones->end());
        imprimirCamino(mapa, posiciones, this);
        clearTerminal();
        mapa->mostrarMapa();
        mostrarPosiciones(posiciones);

        delete posiciones;
        delete camino;

        seMovio = true;
        return seMovio;
    }
    return seMovio;
}
