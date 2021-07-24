#include "../../../src/main.h"

/*Construye un objeto de tipo agrafo, inicializando sus atributos a valores nulos*/

Grafo::Grafo()
{
    filas = 0;
    columnas = 0;
    matriz_adyacencia = nullptr;
}

/* Pre: fila y columna deben ser numeros positivos
 * Pos: Dado un terreno, una fila y una columna, agrega un nuevo vertice con esas caracteristicas al vector de vertices
 */
void Grafo::agregar_vertice(string terreno, int fila, int columna)
{
    agrandar_matriz();
    Vertice *nuevo = new Vertice(terreno, fila, columna);
    vertices.push_back(nuevo);
}

/* Pos: Destruye el objeto grafo, liberando la matriz de adyacencia y todos los punteros del vector de vertices
*/
Grafo::~Grafo()
{
    liberar_matriz_adyacencia();
    int tamanio = (int)vertices.size();
    for (int i = 0; i < tamanio; i++)
    {
        delete vertices[i];
    }
    vertices.clear();
}

/* Pre: n debe ser un numero positivo
 * Pos: asigna n al atributo filas
 */
void Grafo::set_fila(int n)
{
    filas = n;
}

/* Pre: n debe ser un numero positivo
 * Pos: asigna n al atributo columnas
 * */
void Grafo::set_columna(int n)
{
    columnas = n;
}

/* Pos: agranda la matriz de adyacencia en 1, para poder acomodar un nuevo vertice
 * */
void Grafo::agrandar_matriz()
{
    int **aux;
    int nueva_cantidad = (int)vertices.size() + 1;

    aux = new int *[nueva_cantidad];
    for (int i = 0; i < nueva_cantidad; i++)
    {
        aux[i] = new int[nueva_cantidad];
    }
    copiar_matriz(aux);
    inicializar_nuevo(aux);
    liberar_matriz_adyacencia();
    matriz_adyacencia = aux;
}

/* Pre: Recibe una matriz de 1 dimension mas grande que la matriz de adyacencia actual
 * Pos: Copia los contenidos de la matriz de adyacencia a la nueva matriz
 * */
void Grafo::copiar_matriz(int **nueva_matriz)
{
    int tamanio = (int)vertices.size();
    for (int i = 0; i < tamanio; i++)
    {
        for (int j = 0; j < tamanio; j++)
            nueva_matriz[i][j] = matriz_adyacencia[i][j];
    }
}

/* Pre: Recibe una matriz de 1 dimension mas grande que la matriz de adyacencia actual
 * Pos: Inicializa las nuevas posiciones vacias de la nueva matriz
 */
void Grafo::inicializar_nuevo(int **nueva_matriz)
{
    int cantidad_vertices = (int)vertices.size();
    for (int i = 0; i < cantidad_vertices; i++)
    {
        nueva_matriz[cantidad_vertices][i] = INF;
        nueva_matriz[i][cantidad_vertices] = INF;
    }
    nueva_matriz[cantidad_vertices][cantidad_vertices] = 0;
}

/* Pos: Libera la memoria de la matriz de adyacencia
*/
void Grafo::liberar_matriz_adyacencia()
{
    int tamanio = (int)vertices.size();
    for (int i = 0; i < tamanio; i++)
    {
        delete[] matriz_adyacencia[i];
    }
    delete[] matriz_adyacencia;
}

/* Pos: Imprime por pantalla todos los vertices y la matriz de adyacencia
 * */
void Grafo::mostrar_grafo()
{
    mostrar_vertices();
    mostrar_matriz();
}

/* Pos: Muestra por pantalla los vertices
*/
void Grafo::mostrar_vertices()
{
    int tamanio = (int)vertices.size();
    for (int i = 0; i < tamanio; i++)
    {
        cout << vertices[i]->get_terreno() << "|";
    }
    cout << endl;
    cout << endl;
}

/* Pos: Muestra por pantalla la matriz de adyacencia
 * */
void Grafo::mostrar_matriz()
{
    int tamanio = (int)vertices.size();
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

/* Pre: Recibe un objeto de tipo Coordenada
 * Pos: Chequea si la coordenada es valida, es decir que no se sale de los limites establecidos
 * por filas y columnas. Devuelve true si es valida, y false si no lo es
 * */
bool Grafo::comprobar_coordenada(Coordenada coordenada)
{
    bool cumple_filas = ((coordenada.get_fila() <= filas) && (coordenada.get_fila() > 0));
    bool cumple_columnas = ((coordenada.get_columna() <= columnas) && (coordenada.get_columna() > 0));
    if (cumple_filas && cumple_columnas)
        return true;
    return false;
}

/* Pre: Recibe un objeto de tipo Coordenada
 * Pos: Dada las coordenadas, devuelve el indice (en el vector de vertices) del vertice que tiene esas coordenadas
 */
int Grafo::buscar_indice(Coordenada coordenada)
{
    int i = 0;
    int indice = NO_ENCONTRADO;
    int tamanio = (int)vertices.size();
    int fila = coordenada.get_fila();
    int columna = coordenada.get_columna();
    bool fue_encontrado = false;
    while (!fue_encontrado && (i < tamanio))
    {
        if ((vertices[i]->get_fila() == fila) && (vertices[i]->get_columna() == columna))
        {
            fue_encontrado = true;
            indice = i;
        }
        i++;
    }
    return indice;
}

/* Pre: Tanto origen como destino representan indices en el vector de vertices, por lo que deben ser mayores o iguales a 0
 * y simultaneamente menores a la longitud del vector. Costo debe ser positivo
 * Pos: Agrega el costo en la matriz de adyacencia
 */
void Grafo::agregar_camino(int origen, int destino, int costo)
{
    matriz_adyacencia[origen][destino] = costo;
}

/* Pre: Personaje debe representar, justamente, un personaje (zombi, vampiro, humano, etc)
 * Pos: De acuerdo al personaje, establece los costos de moverse de un vertice a sus adyacentes
 */
void Grafo::establecer_caminos(string personaje)
{
    int tamanio = (int)vertices.size();
    for (int i = 0; i < tamanio; i++)
    {
        vertices[i]->ajustar_costo(personaje);
        if ((i + columnas) < tamanio) //ajusto el de abajo
            agregar_camino(i, i + columnas, vertices[i]->get_costo());
        if ((i - columnas) >= 0) //ajusto el de arriba
            agregar_camino(i, i - columnas, vertices[i]->get_costo());
        if ((i + 1) < tamanio)
        {
            if (vertices[i]->get_fila() == vertices[i + 1]->get_fila()) //ajusto el de la derecha
                agregar_camino(i, i + 1, vertices[i]->get_costo());
        }
        if ((i - 1) >= 0)
        {
            if (vertices[i]->get_fila() == vertices[i - 1]->get_fila()) //ajusto el de la izquierda
                agregar_camino(i, i - 1, vertices[i]->get_costo());
        }
    }
}

/* Pre: Recibe un vector de distancias y uno de vertices visitados, ninguno vacio
 * Pos: Devuelve el indice del vertice con menor distancia que no fue visitado aun
 * */
int Grafo::indice_minimo(int distancias[], bool visitados[])
{
    int minimo = INF;
    int indice = 0;
    int tamanio = (int)vertices.size();

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

/* Pre: Recibe dos coordenadas, el origen y el destino deben ser coordenadas validas
 * Pos: Devuelve el costo minimo de moverse de origen a destino, si no hay forma de ir, devuelve NO_ENCONTRADO
 * */
int Grafo::camino_minimo(Coordenada origen, Coordenada destino)
{
    bool origen_valido = comprobar_coordenada(origen);
    bool destino_valido = comprobar_coordenada(destino);
    if (origen_valido && destino_valido)
    {
        int indice_origen = buscar_indice(origen);
        int indice_destino = buscar_indice(destino);
        int tamanio = (int)vertices.size();

        int distancias[tamanio];
        bool visitados[tamanio];

        for (int i = 0; i < tamanio; i++)
        {
            distancias[i] = INF;
            visitados[i] = false;
        }
        distancias[indice_origen] = 0;
        for (int i = 0; i < tamanio - 1; i++)
        {
            int minimo = indice_minimo(distancias, visitados);
            visitados[minimo] = true;

            for (int j = 0; j < tamanio; j++)
            {
                if (!visitados[j] && (distancias[minimo] + matriz_adyacencia[minimo][j] < distancias[j]))
                    distancias[j] = distancias[minimo] + matriz_adyacencia[minimo][j];
            }
        }
        return distancias[indice_destino];
    }
    return NO_ENCONTRADO;
}
