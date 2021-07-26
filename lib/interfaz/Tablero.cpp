#include "../../src/main.h"

class Contador;
class Parser;

Tablero::Tablero(const string &dir)
{
    fstream archivoObjetos(dir, ios::in);
    ifstream archivoMapa("archivos/tablero.txt");

    diccionario = new ABB<int, Objeto *>();
    mapa = new Grafo();

    cargarCasillerosGrafo(mapa, archivoMapa);

    jugadores[0] = new Jugador(HUMANOS);
    jugadores[1] = new Jugador(MONSTRUOS);

    if (!archivoObjetos)
    {
        throw invalid_argument("Error: no se puede abrir el archivoObjetos");
    }
    else
    {
        this->contador = new Contador();

        string linea, filas, columnas;

        /* Lee la cantidad de filas */
        getline(archivoObjetos, filas, ' ');

        /* Lee la cantidad de columnas */
        getline(archivoObjetos, columnas);

        /* Establece la cantidad de filas y columnas del tablero */
        this->mapa->setFilas(stoi(filas));
        this->mapa->setColumnas(stoi(columnas));

        while (getline(archivoObjetos, linea))
        {
            // El parser agarra la linea y mapea la data a sus atributos.
            Parser parser(linea);

            Objeto *objeto = parser.getObjeto();
            string nombreEntidad = parser.getNombre();
            int id = parser.getId();

            // Posicion donde se ubicara el objeto
            int fila = parser.getPosicion()->getFila();
            int columna = parser.getPosicion()->getColumna();

            // Establecemos el objeto en la posicion indicada
            this->darDeAlta(Posicion(fila, columna), objeto);

            // Insertamos el objeto con su respectiva clave en el diccionario
            diccionario->insertar(id, objeto);

            // Almacenamos el objeto en el jugador de acuerdo a su bando.
            if (parsearTextoABando(nombreEntidad) == HUMANOS)
                jugadores[0]->agregarPersonaje(dynamic_cast<Ser *>(objeto));

            if (parsearTextoABando(nombreEntidad) == MONSTRUOS)
                jugadores[1]->agregarPersonaje(dynamic_cast<Ser *>(objeto));
        }
    }
}

void Tablero::darDeBaja(Posicion pos)
{
    if (this->mapa->coordenadaValida(pos))
    {
        this->mapa->getCasillero(pos)->vaciarObjeto();
    }
}

Objeto *Tablero::getElementoEnPosicion(Posicion pos)
{
    return this->mapa->getCasillero(pos)->getObjeto();
}

void Tablero::darDeAlta(Posicion pos, Objeto *nuevoObjeto)
{
    if (this->mapa->coordenadaValida(pos))
    {
        this->mapa->agregarObjeto(nuevoObjeto, pos);
    }
}

int Tablero::getExistentes(const string &nombre)
{
    return contador->obtener_cantidad_existentes(nombre);
}

float Tablero::getPorcentaje(const string &nombre)
{
    return this->contador->obtener_porcentaje(nombre);
}

bool Tablero::existeObjetoEnCuadrante(const string &buscado, Posicion minPos, Posicion maxPos)
{
    bool objetoEncontrado = false;

    int i = minPos.getFila();
    int j = minPos.getColumna();

    while (!objetoEncontrado && i <= maxPos.getFila())
    {
        while (!objetoEncontrado && j <= maxPos.getColumna())
        {

            Objeto *obj = this->mapa->getCasillero(Posicion(i, j))->getObjeto();
            if (obj != NULL)
                objetoEncontrado = buscado == obj->getNombre();

            j++;
        }
        j = minPos.getColumna();
        i++;
    }

    return objetoEncontrado;
}

bool Tablero::compararObjetos(const string &buscado, const string &hallado)
{
    bool objetoEncontrado = buscado == hallado;

    if (!objetoEncontrado && buscado == S_VAMPIRO)
        objetoEncontrado = hallado == S_VAMPIRO || hallado == S_NOSFERATU;
    else if (!objetoEncontrado && buscado == S_HUMANO)
        objetoEncontrado = hallado == S_HUMANO_CV || hallado == S_VANESA;

    return objetoEncontrado;
}

Jugador *Tablero::getJugador(int idx)
{
    if (idx < 0 || idx > 1)
        return nullptr;

    return jugadores[idx];
}

Jugador *Tablero::getJugadorActual()
{
    return jugadores[idxJugadorActual];
}

ABB<int, Objeto *> *Tablero::getDiccionario()
{
    return this->diccionario;
}

Grafo *Tablero::getMapa()
{
    return this->mapa;
}

Tablero::~Tablero()
{
    delete mapa;
    delete contador;
    delete diccionario;
    delete jugadores[0];
    delete jugadores[1];
}
