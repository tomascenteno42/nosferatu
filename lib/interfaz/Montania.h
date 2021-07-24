#ifndef NOFERATU_LOCAL_MONTANIA_H
#define NOFERATU_LOCAL_MONTANIA_H
#include "Casillero.h"

class Montania : public Casillero{

public:
    explicit Montania();

    int costo(char personaje);
};


#endif //NOFERATU_LOCAL_MONTANIA_H
