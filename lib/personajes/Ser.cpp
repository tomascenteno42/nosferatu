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

void Ser::actualizarMapa(Grafo *mapa, Posicion origen, Posicion destino)
{
    Objeto *aux;
    aux = mapa->getCasillero(origen)->getObjeto();
    mapa->eliminarObjeto(origen);
    mapa->agregarObjeto(aux, destino);
    mapa->getCasillero(origen)->desocupar();
    mapa->getCasillero(destino)->ocupar();
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

bool Ser::mover(Grafo *mapa, Posicion destino) {
    bool seMovio = false;
    mapa->establecerCaminos(this->getNombre());
    Posicion origen(this->getFila(), this->getColumna());
    vector<int> *camino = mapa->caminoMinimo(origen, destino, this->getEnergia());
    if (camino != nullptr) {
        int costoCamino = mapa->sumarCamino(camino);
        this->energia -= costoCamino;
        actualizarMapa(mapa, origen, destino);
//        chequearCamino(mapa, camino, this->nombre);
        vector <Posicion> *posiciones = new vector<Posicion>;
        posiciones = obtenerPosiciones(mapa, camino);
        reverse(posiciones->begin(), posiciones->end());
        mostrarPosiciones(posiciones);
        delete posiciones;
        delete camino;
        seMovio = true;
        return seMovio;
    }
    return seMovio;
}
