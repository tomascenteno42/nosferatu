#ifndef PRUEBA_GRAFO_VERTICE_H
#define PRUEBA_GRAFO_VERTICE_H

#include "coordenada.h"
#include <string>

using namespace std;

const string HUMANO = "humano";
const string ZOMBI = "zombi";
const string VAMPIRO = "vampiro";
const string VANESA = "Vanesa";
const string VAMPIRELLA = "Vampirella";
const string NOSFERATU = "Nosferatu";
const string CV = "CV";
const string MONTANIA = "M";
const string PRECIPICIO = "P";
const string VOLCAN = "V";
const string LAGO = "L";
const string CAMINO = "C";
const string VACIO = "O";

class Vertice{
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
