#ifndef NOFERATU_LOCAL_VACIO_H
#define NOFERATU_LOCAL_VACIO_H
#include "../../src/main.h"

class Vacio : public Casillero
{

public:
    explicit Vacio();

    int costo(char personaje);
};

#endif //NOFERATU_LOCAL_VACIO_H
