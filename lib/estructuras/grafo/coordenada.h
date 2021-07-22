#ifndef PRUEBA_GRAFO_COORDENADA_H
#define PRUEBA_GRAFO_COORDENADA_H

#include "../../../src/main.h"

class Coordenada
{
private:
    int fila;
    int columna;

public:
    Coordenada();
    int get_fila();
    int get_columna();
    void set_fila(int n);
    void set_columna(int n);
};

#endif
