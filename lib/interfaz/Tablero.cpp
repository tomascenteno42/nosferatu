#include "../../src/main.h"

class Contador;
class Parser;

Tablero::Tablero(const string &dir)
{
    fstream archivo(dir, ios::in);

    diccionario = new ABB<int, Objeto *>();

    jugadores[0] = new Jugador(HUMANOS);
    jugadores[1] = new Jugador(MONSTRUOS);

    if (!archivo)
    {
        throw invalid_argument("Error: no se puede abrir el archivo");
    }
    else
    {
        this->contador = new Contador();

        string linea, s_filas, s_columnas;

        /* Lee la cantidad de filas */
        getline(archivo, s_filas, ' ');

        /* Lee la cantidad de columnas */
        getline(archivo, s_columnas);

        /* Establece la cantidad de filas y columnas del tablero */
        this->cant_filas = stoi(s_filas);
        this->cant_columnas = stoi(s_columnas);

        this->inicializarMatriz();

        while (getline(archivo, linea))
        {
            // El parser agarra la linea y mapea la data a sus atributos.
            Parser parser(linea);

            Objeto *objeto = parser.obtenerObjeto();
            string nombreEntidad = parser.obtener_nombre();
            int claveEntidad = parser.getClave();

            // Posicion donde se ubicara el objeto
            int fila = parser.obtener_posicion()->obtener_fila() - 1;
            int columna = parser.obtener_posicion()->obtener_columna() - 1;

            // Establecemos el objeto en la posicion indicada
            this->objetos[fila][columna] = objeto;

            // Insertamos el objeto con su respectiva clave en el diccionario
            diccionario->insertar(claveEntidad, objeto);

            // Almacenamos el objeto en el jugador de acuerdo a su bando.
            if (parsearTextoABando(nombreEntidad) == HUMANOS)
                jugadores[0]->agregarPersonaje(objeto);

            else if (parsearTextoABando(nombreEntidad) == MONSTRUOS)
                jugadores[1]->agregarPersonaje(objeto);
        }
    }
}

void Tablero::inicializarMatriz()
{

    this->objetos = new Objeto **[this->cantidadFilas()];
    for (int i = 0; i < this->cantidadFilas(); i++)
    {
        this->objetos[i] = new Objeto *[this->cantidadColumnas()];
        for (int j = 0; j < this->cantidadColumnas(); j++)
        {
            this->objetos[i][j] = NULL;
        }
    }
}

bool Tablero::posicionValida(int fila, int columna)
{
    return (fila >= 0 && columna >= 0 && fila < this->cantidadFilas() && columna < this->cantidadColumnas());
}

void Tablero::darDeBaja(int fila, int columna)
{
    if (this->posicionValida(fila, columna))
    {
        delete this->objetos[fila][columna];
        this->objetos[fila][columna] = NULL;
    }
}

Objeto *Tablero::getElementoEnPosicion(int fila, int columna)
{
    return this->objetos[fila][columna];
}

int Tablero::cantidadFilas()
{
    return this->cant_filas;
}

int Tablero::cantidadColumnas()
{
    return this->cant_columnas;
}

void Tablero::darDeAlta(int fila, int columna, Objeto *nuevo_objeto)
{
    if (this->objetos[fila][columna] == NULL)
    {
        this->objetos[fila][columna] = nuevo_objeto;
    }
    else
    {
        delete this->objetos[fila][columna];
        this->objetos[fila][columna] = nuevo_objeto;
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

bool Tablero::existeObjetoEnCuadrante(const string &buscado, Posicion pos_min, Posicion pos_max)
{
    bool objeto_hallado = false;
    int i = pos_min.obtener_fila() - 1;
    int j = pos_min.obtener_columna() - 1;
    while (!objeto_hallado && i < pos_max.obtener_fila())
    {
        while (!objeto_hallado && j < pos_max.obtener_columna())
        {
            if (this->objetos[i][j] != NULL)
            {
                objeto_hallado = this->compararObjetos(buscado, this->objetos[i][j]->getNombre());
            }
            j++;
        }
        i++;
    }
    return objeto_hallado;
}

bool Tablero::compararObjetos(const string &buscado, const string &hallado)
{
    bool objeto_hallado = false;
    objeto_hallado = buscado == hallado;
    if (!objeto_hallado && buscado == S_VAMPIRO)
    {
        objeto_hallado = hallado == S_VAMPIRO || hallado == S_NOSFERATU;
    }
    else if (!objeto_hallado && buscado == S_HUMANO)
    {
        objeto_hallado = hallado == S_HUMANO_CV || hallado == S_VANESA;
    }
    return objeto_hallado;
}

Jugador *Tablero::getJugador(int idx)
{
    if (idx < 0 || idx > 1)
        return nullptr;

    return jugadores[idx];
}

ABB<int, Objeto *> *Tablero::getDiccionario()
{
    return this->diccionario;
}

Tablero::~Tablero()
{
    for (int i = 0; i < this->cantidadFilas(); i++)
    {
        for (int j = 0; j < this->cantidadColumnas(); j++)
        {
            if (this->objetos[i][j] != NULL)
            {
                delete this->objetos[i][j];
            }
        }
        delete[] objetos[i];
    }
    delete[] objetos;
    delete contador;
    delete diccionario;
    delete jugadores[0];
    delete jugadores[1];
}
