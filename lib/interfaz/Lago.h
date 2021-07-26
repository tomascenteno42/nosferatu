#ifndef NOFERATU_LOCAL_LAGO_H
#define NOFERATU_LOCAL_LAGO_H
#include "../../src/main.h"

class Lago : public Casillero
{

public:
    explicit Lago(int fila, int columna);

    void ajustarCosto(string personaje);

    // string devolver_color();
};

#endif //NOFERATU_LOCAL_LAGO_H
