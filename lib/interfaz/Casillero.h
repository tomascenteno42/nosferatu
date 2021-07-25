#ifndef NOFERATU_LOCAL_CASILLERO_H
#define NOFERATU_LOCAL_CASILLERO_H
#include "../../src/main.h"

class Casillero
{
protected:
    string tipo;
    string color;
    int costo;
    Posicion coordenadas;
    bool ocupado; //por un personaje, no elemento
public:
    explicit Casillero(string tipo, string color, int fila, int columna);
    string obtenerTipo();

    string obtenerColor();

    int obtenerFila();

    int obtenerColumna();

    int obtenerCosto();

    bool estaOcupado();

    void ocupar();

    void desocupar();

    virtual void ajustarCosto(string personaje) = 0;

    virtual ~Casillero(){};
};

#endif //NOFERATU_LOCAL_CASILLERO_H
