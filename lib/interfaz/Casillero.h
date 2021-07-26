#ifndef NOFERATU_LOCAL_CASILLERO_H
#define NOFERATU_LOCAL_CASILLERO_H
#include "../../src/main.h"

class Casillero
{
protected:
    Posicion coordenadas;
    string tipo;
    string color;
    int costo;
    bool ocupado; //por un personaje, no elemento
    Objeto *objeto;

public:
    explicit Casillero(string tipo, string color, int fila, int columna);

    string getTipo();

    string getColor();

    Objeto *getObjeto();

    void setObjeto(Objeto *nuevoObjeto);

    void eliminarObjeto();

    int getFila();

    int getColumna();

    int getCosto();

    bool estaOcupado();

    void ocupar();

    void desocupar();

    virtual void ajustarCosto(string personaje) = 0;

    virtual ~Casillero();
};

#endif //NOFERATU_LOCAL_CASILLERO_H
