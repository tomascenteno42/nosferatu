#ifndef NOFERATU_LOCAL_CAMINO_H
#define NOFERATU_LOCAL_CAMINO_H
#include "Casillero.h"

class Camino : public Casillero{

public:
    explicit Camino();

    int costo(char personaje);
};


#endif //NOFERATU_LOCAL_CAMINO_H
