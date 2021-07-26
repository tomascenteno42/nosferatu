#ifndef PRUEBA_GRAFO_GRAFO_H
#define PRUEBA_GRAFO_GRAFO_H

#include "../../interfaz/Casillero.h"
#include "../../interfaz/Montania.h"
#include "../../interfaz/Lago.h"
#include "../../interfaz/Camino.h"
#include "../../interfaz/Posicion.h"
#include "../../interfaz/Precipicio.h"
#include "../../interfaz/Vacio.h"
#include "../../interfaz/Volcan.h"

const int INF = 9999;
const int NO_ENCONTRADO = -1;

class Grafo
{
private:
    vector<Casillero *> casilleros;
    int filas;
    int columnas;
    int **matriz_adyacencia;
    void copiarMatriz(int **nueva_matriz);
    void agrandarMatriz();
    void inicializarNuevo(int **nueva_matriz);
    void liberarMatrizAdyacencia();
    void mostrarCasilleros();
    void mostrarMatriz();
    int buscarIndice(Posicion coordenada);
    void agregarCamino(int origen, int destino, int costo);
    int indiceMinimo(int distancias[], bool visitados[]);
    void ordenarCamino(int anteriores[], vector<int> *camino, int indiceDestino);

public:
    Grafo();
    bool coordenadaValida(Posicion coordenada);
    bool estaOcupado(Posicion coordenada);
    void agregarCasillero(string terreno, int fila, int columna);
    void agregarObjeto(Objeto *nuevoObjeto, Posicion pos);
    void eliminarObjeto(Posicion pos);
    void setFilas(int n);
    void setColumnas(int n);
    int getFilas();
    int getColumnas();
    int getCantidad();
    void mostrarGrafo();
    void mostrarMapa();
    void establecerCaminos(string personaje);
    int sumarCamino(vector<int>* camino);
    void ocupar(Posicion coordenada);
    void desocupar(Posicion coordenada);
    Casillero *getCasillero(Posicion coordenada);
    Casillero *getCasillero(int indice);
    vector<int> *caminoMinimo(Posicion origen, Posicion destino, int energiaPersonaje);
    ~Grafo();
};

#endif
