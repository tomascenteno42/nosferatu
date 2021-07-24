#ifndef NOFERATU_LOCAL_CASILLERO_H
#define NOFERATU_LOCAL_CASILLERO_H
#include "../../Constantes.h"

class Casillero {
protected:
    std::string tipo;
    std::string color;
public:

    explicit Casillero(std::string tipo, std::string color);


    std::string obtener_tipo();


    std::string obtener_color();


    virtual int costo (char personaje) = 0;


    virtual ~Casillero(){};
};


#endif //NOFERATU_LOCAL_CASILLERO_H
