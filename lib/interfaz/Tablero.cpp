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
                jugadores[0]->agregarPersonaje((Ser *)(objeto));

            if (parsearTextoABando(nombreEntidad) == MONSTRUOS)
                jugadores[1]->agregarPersonaje((Ser *)(objeto));
        }
    }
}

void Tablero::darDeBaja(Posicion pos)
{

    if (this->mapa->coordenadaValida(pos))
        this->mapa->getCasillero(pos)->eliminarObjeto();
}

void Tablero::matarPersonaje(Posicion pos)
{
    int id = getElementoEnPosicion(pos)->getId();

    getMapa()->desocupar(pos);
    getMapa()->eliminarObjeto(pos);
    getJugadorActual()->eliminarPersonaje(id);
}

Objeto *Tablero::getElementoEnPosicion(Posicion pos)
{
    if (!this->mapa->coordenadaValida(pos))
        return nullptr;

    return this->mapa->getCasillero(pos)->getObjeto();
}

void Tablero::darDeAlta(Posicion pos, Objeto *nuevoObjeto)
{
    if (this->mapa->coordenadaValida(pos))
    {
        this->mapa->agregarObjeto(nuevoObjeto, pos);
    }
}

void Tablero::aplicarTransformacion(int idTransformado, Monstruo *nuevoMonstruo, Posicion pos, bool esZombi)
{
    // Eliminamos el personaje del bando de los humanos
    this->getJugador(0)->eliminarPersonaje(idTransformado);

    /* Comprobamos si la transformacion a aplicar es para zombies,
     y realizamos el ajuste correspondiente */
    if (esZombi)
        this->getJugador(1)->agregarPersonaje((Zombi *)nuevoMonstruo);
    else
        this->getJugador(1)->agregarPersonaje((Vampiro *)nuevoMonstruo);

    // Eliminamos del diccionario el nodo y liberamos esa posicion en el tablero
    this->getDiccionario()->eliminar(idTransformado);
    this->darDeBaja(pos);

    /* Insertamos en el diccionario el nuevo puntero
     y damos de alta esa posicion en el tablero */
    this->getDiccionario()->insertar(idTransformado, (Objeto *)nuevoMonstruo);
    this->darDeAlta(pos, (Objeto *)nuevoMonstruo);

    cout << "Se transformo el personaje en la posicion: ";
    cout << pos.getFila() << "," << pos.getColumna() << endl;
}
void Tablero::aplicarTransformacionAZombi()
{
    vector<Ser *> personajes;
    int i = 0;

    /* Este booleano sirve para que en el caso de que una transformacion ocurrio,
         no se pierda la transformacion de otro personaje. */
    bool huboTransformacion = false;

    while (i < this->getJugador(0)->personajesVivos())
    {
        personajes = this->getJugador(0)->getPersonajes();
        char caracter = personajes.at(i)->getCaracter();

        if (caracter == C_HUMANO || caracter == C_HUMANO_CV || caracter == C_VANESA)
        {
            Humano *humano = (Humano *)personajes.at(i);
            if (humano->yaSeTransformo())
            {
                vector<Elemento *> inv = humano->getInventario();

                int idHumano = humano->getId();
                int filaHumano = humano->getFila();
                int columnaHumano = humano->getColumna();

                Zombi *zombi = new Zombi(idHumano, filaHumano, columnaHumano);

                // Agarra aguas benditas si se encuentran en el inventario del humano.
                for (size_t i = 0; i < inv.size(); i++)
                    if (inv.at(i)->getCaracter() == C_AGUA_BENDITA)
                        zombi->agarrarObjeto();

                aplicarTransformacion(idHumano, zombi, Posicion(filaHumano, columnaHumano), true);

                huboTransformacion = true;
            }
        }
        if (huboTransformacion)
        {
            /* Si una transformacion ocurrio, se vuelve a recorrer
                 todo el vector de personajes en busca de otra transformacion */
            i = 0;
            huboTransformacion = false;
        }
        else
            i++;
    }
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
    delete diccionario;
    delete jugadores[0];
    delete jugadores[1];
}
