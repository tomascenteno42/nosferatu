
#ifndef NOFERATU_LOCAL_VOLCAN_H
#define NOFERATU_LOCAL_VOLCAN_H
#include "Casillero.h"

class Volcan : public Casillero{

public:
    explicit Volcan();

    int costo(char personaje);
};


#endif //NOFERATU_LOCAL_VOLCAN_H
