#ifndef NOFERATU_LOCAL_CAMINO_H
#define NOFERATU_LOCAL_CAMINO_H
#include "../../src/main.h"

class Camino : public Casillero
{

public:
    explicit Camino(int fila, int columna);

    void ajustarCosto(string personaje);
};

#endif //NOFERATU_LOCAL_CAMINO_H
