#ifndef PRUEBA_GRAFO_VERTICE_H
#define PRUEBA_GRAFO_VERTICE_H

#include "../../../src/main.h"

class Vertice
{
private:
    int costo;
    Coordenada coordenadas;
    string terreno;

public:
    Vertice(string terreno, int fila, int columna);
    int get_costo();
    int get_fila();
    int get_columna();
    string get_terreno();
    void ajustar_costo(string tipo);
};

#endif
