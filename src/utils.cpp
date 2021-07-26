#include "main.h"

void clearTerminal()
{
    cout << "\033[2J\033[1;1H";
}

void mostrarBando(BANDO bando)
{
    cout << parsearBandoATexto(bando) << endl
         << endl;
}

string parsearBandoATexto(BANDO bando)
{
    if (bando == MONSTRUOS)
        return "Monstruos";
    else if (bando == HUMANOS)
        return "Humanos";

    return "OBJETOS";
}

BANDO parsearTextoABando(string texto)
{
    toLower(texto);

    if (texto == S_HUMANO || texto == S_HUMANO_CV || texto == S_VANESA)
        return HUMANOS;

    if (texto == S_VAMPIRELLA || texto == S_VAMPIRO || texto == S_NOSFERATU || texto == S_ZOMBI)
        return MONSTRUOS;

    return OBJETO;
}

ENUM_OBJETOS parsearTextoAObjeto(string texto)
{
    toLower(texto);

    if (texto == S_HUMANO)
        return HUMANO;
    else if (texto == S_HUMANO_CV)
        return HUMANO_CV;
    else if (texto == S_ZOMBI)
        return ZOMBIE;
    else if (texto == S_VAMPIRO)
        return VAMPIRO;
    else if (texto == S_VAMPIRELLA)
        return VAMPIRELLA;
    else if (texto == S_NOSFERATU)
        return NOSFERATU;
    else if (texto == S_VANESA)
        return VANESA;
    else if (texto == S_AGUA_BENDITA)
        return AGUA_BENDITA;
    else if (texto == S_CRUZ)
        return CRUZ;
    else if (texto == S_ESTACA)
        return ESTACA;
    else if (texto == S_ESCOPETA)
        return ESCOPETA;
    else
        return BALAS;
}

ID parseId(int id)
{
    if (id == ID_VANESA)
        return ID_VANESA;

    if (id == ID_VAMPIRELLA)
        return ID_VAMPIRELLA;

    if (id == ID_NOSFERATU)
        return ID_NOSFERATU;

    if (id >= ID_HUMANO && id < ID_HUMANO_CV)
        return ID_HUMANO;

    else if (id >= ID_HUMANO_CV && id < ID_ZOMBIE)
        return ID_HUMANO_CV;

    else if (id >= ID_ZOMBIE && id < ID_NOSFERATU)
        return ID_ZOMBIE;

    else if (id >= ID_VAMPIRO && id < ID_AGUA_BENDITA)
        return ID_VAMPIRO;

    else if (id >= ID_AGUA_BENDITA && id < ID_CRUZ)
        return ID_AGUA_BENDITA;

    else if (id >= ID_CRUZ && id < ID_ESCOPETA)
        return ID_CRUZ;

    else if (id >= ID_ESCOPETA && id < ID_BALAS)
        return ID_ESCOPETA;

    else if (id >= ID_BALAS && id < ID_ESTACA)
        return ID_BALAS;

    else if (id >= ID_ESTACA && id < ID_NO_VALIDO)
        return ID_ESTACA;

    return ID_NO_VALIDO;
}

bool esIdValido(int id, ENUM_OBJETOS objeto)
{
    switch (objeto)
    {
    case VANESA:
        return id == ID_VANESA;
    case HUMANO:
        return id >= ID_HUMANO && id < ID_HUMANO_CV;
    case HUMANO_CV:
        return id >= ID_HUMANO_CV && id < ID_ZOMBIE;
    case ZOMBIE:
        return id >= ZOMBIE && id < ID_NOSFERATU;
    case NOSFERATU:
        return id == ID_NOSFERATU;
    case VAMPIRELLA:
        return id == ID_VAMPIRELLA;
    case VAMPIRO:
        return id >= ID_VAMPIRO && id < ID_AGUA_BENDITA;
    case AGUA_BENDITA:
        return id >= ID_AGUA_BENDITA && id < ID_CRUZ;
    case CRUZ:
        return id >= ID_CRUZ && id < ID_ESCOPETA;
    case ESCOPETA:
        return id >= ID_ESCOPETA && id < ID_BALAS;
    case BALAS:
        return id >= ID_BALAS && id < ID_ESTACA;
    case ESTACA:
        return id >= ID_ESTACA && id < ID_NO_VALIDO;
    default:
        return false;
    }
}

void toLower(string &str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

/* Pre: *mapa no debe ser nullptr, y datos debe existir
 * Pos: Llena el grafo con los datos extraidos del archivo de casilleros
 */
void cargarCasillerosGrafo(Grafo *mapa, ifstream &datos)
{
    string s_filas;
    string s_columnas;
    string leido;
    int contador = 1;

    getline(datos, s_filas, ' ');
    getline(datos, s_columnas, '\n');

    int filas = stoi(s_filas);
    int columnas = stoi(s_columnas);

    mapa->setFilas(filas);
    mapa->setColumnas(columnas);

    while (!datos.eof())
    {
        for (int j = 0; j < (columnas - 1); j++)
        {
            getline(datos, leido, ',');
            mapa->agregarCasillero(leido, contador, j + 1);
        }
        getline(datos, leido, '\n');
        mapa->agregarCasillero(leido, contador, columnas);
        contador++;
    }
}

/* Pre: Los punteros mapa y camino no son nullptr
 * Pos: Dado el camino tomado, transforma la secuencia de casilleros en Posiciones
 * */
vector<Posicion>* obtenerPosiciones(Grafo* mapa, vector<int>* camino)
{
    int tamanio = (int)camino->size();
    int fila, columna;
    Posicion aux;
    Casillero* casillero;
    vector<Posicion>* posiciones = new vector<Posicion>;

    for(int i = 0; i < tamanio; i++){
        casillero = mapa->getCasillero(camino->at(i));
        fila = casillero->getFila();
        columna = casillero->getColumna();
        aux.cambiarFila(fila);
        aux.cambiarColumna(columna);
        posiciones->push_back(aux);
    }
    reverse(posiciones->begin(), posiciones->end());
    return posiciones;
}

/* Pre: El puntero posiciones no es nullptr
 * Pos: Imprime por pantalla la secuencia de posiciones por las que paso el personaje
 */
void mostrarPosiciones(vector<Posicion>* posiciones)
{
    int tamanio = (int)posiciones->size();
    int fila, columna;

    cout << "Camino tomado: " << endl;

    for(int i = 0; i < tamanio - 1; i++){
        fila = posiciones->at(i).getFila();
        columna = posiciones->at(i).getColumna();
        cout << "(" << fila << "," << columna << ")" << "->";
    }
    fila = posiciones->at(tamanio - 1).getFila();
    columna = posiciones->at(tamanio - 1).getColumna();
    cout << "(" << fila << "," << columna << ")" << endl;
}
