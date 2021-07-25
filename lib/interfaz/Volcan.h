
#ifndef NOFERATU_LOCAL_VOLCAN_H
#define NOFERATU_LOCAL_VOLCAN_H
#include "../../src/main.h"

class Volcan : public Casillero
{

public:
    explicit Volcan(int fila, int columna);

    void ajustarCosto(string personaje);
};

#endif //NOFERATU_LOCAL_VOLCAN_H
