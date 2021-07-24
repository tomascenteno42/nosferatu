#ifndef NOFERATU_LOCAL_LAGO_H
#define NOFERATU_LOCAL_LAGO_H
#include "Casillero.h"


class Lago : public Casillero{

public:
    explicit Lago();

    int costo(char personaje);

    //std::string devolver_color();
};


#endif //NOFERATU_LOCAL_LAGO_H
