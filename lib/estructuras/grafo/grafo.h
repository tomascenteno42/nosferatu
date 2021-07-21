#ifndef PRUEBA_GRAFO_GRAFO_H
#define PRUEBA_GRAFO_GRAFO_H

#include <vector>
#include "vertice.h"
#include "coordenada.h"
using namespace std;

const int INF = 9999;
const int NO_ENCONTRADO = -1;

class Grafo{
private:
    vector<Vertice*> vertices;
    int filas;
    int columnas;
    int** matriz_adyacencia;
    void copiar_matriz(int **nueva_matriz);
    void agrandar_matriz();
    void inicializar_nuevo(int ** nueva_matriz);
    void liberar_matriz_adyacencia();
    void mostrar_vertices();
    void mostrar_matriz();
    bool comprobar_coordenada(Coordenada coordenada);
    int buscar_indice(Coordenada coordenada);
    void agregar_camino(int origen, int destino, int costo);
    int indice_minimo(int distancias[], bool visitados[]);
public:
    Grafo();
    void agregar_vertice(string terreno, int fila, int columna);
    void set_fila(int n);
    void set_columna(int n);
    void mostrar_grafo();
    void establecer_caminos(string personaje);
    int camino_minimo(Coordenada origen, Coordenada destino);
    ~Grafo();
};

#endif
