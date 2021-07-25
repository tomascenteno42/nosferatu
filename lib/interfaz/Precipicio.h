#ifndef NOFERATU_LOCAL_PRECIPICIO_H
#define NOFERATU_LOCAL_PRECIPICIO_H
#include "../../src/main.h"

class Precipicio : public Casillero
{

public:
    explicit Precipicio(int fila, int columna);

    void ajustarCosto(string personaje);
};

#endif //NOFERATU_LOCAL_PRECIPICIO_H
