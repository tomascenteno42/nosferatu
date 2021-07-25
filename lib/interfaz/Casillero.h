#ifndef NOFERATU_LOCAL_CASILLERO_H
#define NOFERATU_LOCAL_CASILLERO_H
#include "../../src/main.h"

class Casillero
{
protected:
    string tipo;
    string color;

public:
    explicit Casillero(string tipo, string color);

    string obtener_tipo();

    string obtener_color();

    virtual int costo(char personaje) = 0;

    virtual ~Casillero(){};
};

#endif //NOFERATU_LOCAL_CASILLERO_H
