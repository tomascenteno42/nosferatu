#include "../../../src/main.h"

/*Construye un objeto de tipo grafo, inicializando sus atributos a valores nulos*/

Grafo::Grafo()
{
    filas = 0;
    columnas = 0;
    matriz_adyacencia = nullptr;
}

/* Pre: fila y columna deben ser numeros positivos
 * Pos: Dado un terreno, una fila y una columna, agrega un nuevo casillero con esas caracteristicas al vector de casilleros
 */
void Grafo::agregarCasillero(string terreno, int fila, int columna)
{
    agrandarMatriz();
    Casillero *nuevo;
    if (terreno == MONTANIA)
        nuevo = new Montania(fila, columna);
    else if (terreno == CAMINO)
        nuevo = new Camino(fila, columna);
    else if (terreno == LAGO)
        nuevo = new Lago(fila, columna);
    else if (terreno == PRECIPICIO)
        nuevo = new Precipicio(fila, columna);
    else if (terreno == VACIO)
        nuevo = new Vacio(fila, columna);
    else if (terreno == VOLCAN)
        nuevo = new Volcan(fila, columna);

    casilleros.push_back(nuevo);
}

/* Pos: Destruye el objeto grafo, liberando la matriz de adyacencia y todos los punteros del vector de casilleros
*/
Grafo::~Grafo()
{
    liberarMatrizAdyacencia();

    for (int i = 0; i < casilleros.size(); i++)
        delete casilleros.at(i);

    casilleros.clear();
}

/* Pre: n debe ser un numero positivo
 * Pos: asigna n al atributo filas
 */
void Grafo::setFilas(int n)
{
    filas = n;
}

/* Pre: n debe ser un numero positivo
 * Pos: asigna n al atributo columnas
 * */
void Grafo::setColumnas(int n)
{
    columnas = n;
}

/* Pos: agranda la matriz de adyacencia en 1, para poder acomodar un nuevo casillero
 * */
void Grafo::agrandarMatriz()
{
    int **aux;
    int nueva_cantidad = (int)casilleros.size() + 1;

    aux = new int *[nueva_cantidad];
    for (int i = 0; i < nueva_cantidad; i++)
    {
        aux[i] = new int[nueva_cantidad];
    }
    copiarMatriz(aux);
    inicializarNuevo(aux);
    liberarMatrizAdyacencia();
    matriz_adyacencia = aux;
}

/* Pre: Recibe una matriz de 1 dimension mas grande que la matriz de adyacencia actual
 * Pos: Copia los contenidos de la matriz de adyacencia a la nueva matriz
 * */
void Grafo::copiarMatriz(int **nueva_matriz)
{
    int tamanio = (int)casilleros.size();
    for (int i = 0; i < tamanio; i++)
    {
        for (int j = 0; j < tamanio; j++)
            nueva_matriz[i][j] = matriz_adyacencia[i][j];
    }
}

/* Pre: Recibe una matriz de 1 dimension mas grande que la matriz de adyacencia actual
 * Pos: Inicializa las nuevas posiciones vacias de la nueva matriz
 */
void Grafo::inicializarNuevo(int **nueva_matriz)
{
    int cantidad_vertices = (int)casilleros.size();
    for (int i = 0; i < cantidad_vertices; i++)
    {
        nueva_matriz[cantidad_vertices][i] = INF;
        nueva_matriz[i][cantidad_vertices] = INF;
    }
    nueva_matriz[cantidad_vertices][cantidad_vertices] = 0;
}

/* Pos: Libera la memoria de la matriz de adyacencia
*/
void Grafo::liberarMatrizAdyacencia()
{
    int tamanio = (int)casilleros.size();
    for (int i = 0; i < tamanio; i++)
    {
        delete[] matriz_adyacencia[i];
    }
    delete[] matriz_adyacencia;
}

/* Pos: Imprime por pantalla todos los vertices y la matriz de adyacencia
 * */
void Grafo::mostrarGrafo()
{
    mostrarCasilleros();
    mostrarMatriz();
}

void Grafo::mostrarMapa()
{
    int tamanio = (int)casilleros.size();
    int contador = 0;
    int i = 0;

    while (i < tamanio && contador <= columnas)
    {
        cout << casilleros[i]->getColor();

        if (casilleros[i]->getObjeto() != nullptr)
        {
            cout << setw(1) << " ";
            cout << casilleros[i]->getObjeto()->getCaracter();
            cout << setw(1) << " ";
        }
        else
            cout << setw(3) << " ";

        i++;
        contador++;
        if (contador == columnas)
        {
            contador = 0;
            cout << SIN_COLOR << endl;
        }
    }
    cout << SIN_COLOR << endl;
}

/* Pos: Muestra por pantalla los casilleros
*/
void Grafo::mostrarCasilleros()
{
    size_t tamanio = casilleros.size();
    for (size_t i = 0; i < tamanio; i++)
    {
        cout << casilleros[i]->getColor() << " ";
    }
    cout << SIN_COLOR;
    cout << endl;
    cout << endl;
}

/* Pos: Muestra por pantalla la matriz de adyacencia
 * */
void Grafo::mostrarMatriz()
{
    int tamanio = (int)casilleros.size();
    for (int i = 0; i < tamanio; i++)
    {
        for (int j = 0; j < tamanio * 2; j++)
        {
            if (j == ((tamanio * 2) - 1))
                cout << endl;
            else if (j % 2 == 0)
            {
                if (matriz_adyacencia[i][j / 2] == INF)
                    cout << "∞";
                else
                    cout << matriz_adyacencia[i][j / 2];
            }
            else
                cout << "|";
        }
    }
    cout << endl;
}

/* Pre: Recibe un objeto de tipo Posicion
 * Pos: Chequea si la posicion es valida, es decir que no se sale de los limites establecidos
 * por filas y columnas. Devuelve true si es valida, y false si no lo es
 * */
bool Grafo::coordenadaValida(Posicion coordenada)
{
    bool cumple_filas = ((coordenada.getFila() <= filas) && (coordenada.getFila() > 0));
    bool cumple_columnas = ((coordenada.getColumna() <= columnas) && (coordenada.getColumna() > 0));
    if (cumple_filas && cumple_columnas)
        return true;
    return false;
}

/* Pre: Recibe un objeto de tipo Posicion
 * Pos: Dada la posicion, devuelve el indice (en el vector de vertices) del casillero que tiene esas coordenadas
 */
int Grafo::buscarIndice(Posicion coordenada)
{
    int i = 0;
    int indice = NO_ENCONTRADO;
    int tamanio = (int)casilleros.size();
    int fila = coordenada.getFila();
    int columna = coordenada.getColumna();
    bool fue_encontrado = false;
    while (!fue_encontrado && (i < tamanio))
    {
        if ((casilleros[i]->getFila() == fila) && (casilleros[i]->getColumna() == columna))
        {
            fue_encontrado = true;
            indice = i;
        }
        i++;
    }
    return indice;
}

int Grafo::sumarCamino(vector<int> *camino) {
    int tamanio = (int)camino->size();
    int total = 0;
    int parcial;
    int indice;
    for(int i = 0; (i + 1) < tamanio; i++){
        indice = camino->at(i);
        parcial = matriz_adyacencia[indice][camino->at(i + 1)];
        total += parcial;
    }
    return total;
}

/* Pre: la fila y la columna deben ser numeros positivos, el puntero a objeto no debe ser nullptr
 * Pos: Dado un puntero a un objeto y una posicion, agrega el puntero al casillero que se encuentra en esa posicion
 */
void Grafo::agregarObjeto(Objeto *nuevoObjeto, Posicion pos)
{
    if (coordenadaValida(pos))
    {
        int indice = buscarIndice(pos);
        casilleros.at(indice)->setObjeto(nuevoObjeto);
    }
}

void Grafo::eliminarObjeto(Posicion pos) {
    if(coordenadaValida(pos))
    {
        int indice = buscarIndice(pos);
        casilleros.at(indice)->eliminarObjeto();
    }
}

/* Pre: Tanto origen como destino representan indices en el vector de vertices, por lo que deben ser mayores o iguales a 0
 * y simultaneamente menores a la longitud del vector. Costo debe ser positivo
 * Pos: Agrega el costo en la matriz de adyacencia
 */
void Grafo::agregarCamino(int origen, int destino, int costo)
{
    matriz_adyacencia[origen][destino] = costo;
}

/* Pre: Personaje debe representar, justamente, un personaje (zombi, vampiro, humano, etc)
 * Pos: De acuerdo al personaje, establece los costos de moverse de un vertice a sus adyacentes
 */
void Grafo::establecerCaminos(string personaje)
{
    int tamanio = (int)casilleros.size();
    for (int i = 0; i < tamanio; i++)
    {
        casilleros[i]->ajustarCosto(personaje);
        if ((i + columnas) < tamanio) //ajusto el de abajo
            agregarCamino(i, i + columnas, casilleros[i]->getCosto());
        if ((i - columnas) >= 0) //ajusto el de arriba
            agregarCamino(i, i - columnas, casilleros[i]->getCosto());
        if ((i + 1) < tamanio)
        {
            if (casilleros[i]->getFila() == casilleros[i + 1]->getFila()) //ajusto el de la derecha
                agregarCamino(i, i + 1, casilleros[i]->getCosto());
        }
        if ((i - 1) >= 0)
        {
            if (casilleros[i]->getFila() == casilleros[i - 1]->getFila()) //ajusto el de la izquierda
                agregarCamino(i, i - 1, casilleros[i]->getCosto());
        }
    }
}

/* Pos: Dada una cierta coordenada, indica el casillero correspondiente como ocupado
 */
void Grafo::ocupar(Posicion coordenada)
{
    bool valida = coordenadaValida(coordenada);
    if (valida)
    {
        int indice = buscarIndice(coordenada);
        casilleros[indice]->ocupar();
    }
}

/* Pos: Dada una cierta coordenada, indica el casillero correspondiente como desocupado
 */
void Grafo::desocupar(Posicion coordenada)
{
    bool valida = coordenadaValida(coordenada);
    if (valida)
    {
        int indice = buscarIndice(coordenada);
        casilleros[indice]->desocupar();
    }
}

/*Pos: Devuelve la cantidad de casilleros
 */
int Grafo::getCantidad()
{
    return ((int)casilleros.size());
}

/*Devuelve el casillero en la coordenada
*/
Casillero *Grafo::getCasillero(Posicion coordenada)
{
    if (!coordenadaValida(coordenada))
        return nullptr;

    int idx = buscarIndice(coordenada);

    return casilleros.at(idx);
}

Casillero* Grafo::getCasillero(int indice)
{
    return casilleros.at(indice);
}

int Grafo::getFilas()
{
    return this->filas;
}

int Grafo::getColumnas()
{
    return this->columnas;
}

/* Pre: Recibe un vector de distancias y uno de vertices visitados, ninguno vacio
 * Pos: Devuelve el indice del vertice con menor distancia que no fue visitado aun
 * */
int Grafo::indiceMinimo(int distancias[], bool visitados[])
{
    int minimo = INF;
    int indice = 0;
    int tamanio = (int)casilleros.size();

    for (int i = 0; i < tamanio; i++)
    {
        if (!visitados[i] && distancias[i] < minimo)
        {
            minimo = distancias[i];
            indice = i;
        }
    }
    return indice;
}

/* Pre: indiceDestino debe ser un indice valido, mayor o igual a 0 y menor a la cantidad de casilleros*/
void Grafo::ordenarCamino(int anteriores[], vector<int> *camino, int indiceDestino)
{
    int i = indiceDestino;
    while (anteriores[i] != -1)
    {
        camino->push_back(i);
        i = anteriores[i];
    }
    camino->push_back(i);
}

/* Pre: Recibe dos coordenadas, el origen y el destino deben ser coordenadas validas
 * Pos: Devuelve un puntero a un vector, que contiene los indices de los casilleros que conforman el
 * camino minimo
 */
vector<int> *Grafo::caminoMinimo(Posicion origen, Posicion destino, int energiaPersonaje)
{
    bool origen_valido = coordenadaValida(origen);
    bool destino_valido = coordenadaValida(destino);
    if (origen_valido && destino_valido)
    {
        int indice_origen = buscarIndice(origen);
        int indice_destino = buscarIndice(destino);
        int tamanio = (int)casilleros.size();

        int distancias[tamanio];
        bool visitados[tamanio];
        int anteriores[tamanio];
        vector<int> *camino = new vector<int>;

        anteriores[indice_origen] = -1;
        for (int i = 0; i < tamanio; i++)
        {
            distancias[i] = INF;
            visitados[i] = false;
        }
        distancias[indice_origen] = 0;
        for (int i = 0; i < tamanio - 1; i++)
        {
            int minimo = indiceMinimo(distancias, visitados);
            visitados[minimo] = true;

            for (int j = 0; j < tamanio; j++)
            {
                if (!visitados[j] && (!casilleros[j]->estaOcupado()) && (distancias[minimo] + matriz_adyacencia[minimo][j] < distancias[j]))
                {
                    distancias[j] = distancias[minimo] + matriz_adyacencia[minimo][j];
                    anteriores[j] = minimo;
                }
            }
        }
        if (distancias[indice_destino] <= energiaPersonaje)
        {
            ordenarCamino(anteriores, camino, indice_destino);
            reverse(camino->begin(), camino->end());
            return camino;
        }
        delete camino;
    }
    return nullptr;
}


bool Grafo::estaOcupado(Posicion coordenada) {
    int indice = buscarIndice(coordenada);
    return casilleros[indice]->estaOcupado();

}