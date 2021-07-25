#ifndef NOFERATU_LOCAL_MONTANIA_H
#define NOFERATU_LOCAL_MONTANIA_H
#include "../../src/main.h"

class Montania : public Casillero
{

public:
    explicit Montania(int fila, int columna);
    void ajustarCosto(string personaje);
};

#endif //NOFERATU_LOCAL_MONTANIA_H
