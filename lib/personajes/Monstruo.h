#ifndef NOSFERATUV2_MONSTRUO_H
#define NOSFERATUV2_MONSTRUO_H

#include "../../src/main.h"

class Monstruo : public Ser
{
private:
public:
    /*
     * Post: se crea el objeto Monstruo con nombre y caracter por parametro
     */
    Monstruo(string nombre, char caracter, int id);
};

#endif //NOSFERATUV2_MONSTRUO_H
