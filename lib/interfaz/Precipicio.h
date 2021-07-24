#ifndef NOFERATU_LOCAL_PRECIPICIO_H
#define NOFERATU_LOCAL_PRECIPICIO_H
#include "Casillero.h"

class Precipicio : public Casillero{

public:
    explicit Precipicio();

    int costo(char personaje);
};


#endif //NOFERATU_LOCAL_PRECIPICIO_H
