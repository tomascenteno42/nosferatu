#ifndef NOSFERATUV2_VAMPIRO_H
#define NOSFERATUV2_VAMPIRO_H

#include "../../src/main.h"

class Vampiro : public Monstruo
{
private:
    static int contador;

public:
    /*
     * Post: Se crea el objeto vampiro listo para usarse
     *       Aumenta en 1 la cantidad de objetos Vampiro existentes
     */
    Vampiro(int id);

    /*
     * Post: Se crea el objeto Vampiro con nombre y caracter pasado por parametro
     *       Aumenta en 1 la cantidad de objetos Vampiro existentes
     */
    Vampiro(string nombre, char caracter, int id);

    /*
     * Post: aumenta en 1 la cantidad de objetos Vampiro existentes
     */
    static int obtener_existentes();

    /*
     * Post: decrece en 1 la cantidad de objetos Vampiro existentes
     */
    ~Vampiro() override;
};

#endif //NOSFERATUV2_VAMPIRO_H
