#ifndef NOSFERATUV2_NOSFERATU_H
#define NOSFERATUV2_NOSFERATU_H

#include "../../src/main.h"

class Nosferatu : public Vampiro
{
private:
    static int contador;

public:
    /*
    * Post: Se crea nosferatu listo para usarse
     *      Aumenta en 1 la cantidad de Nosferatu existentes
    */
    explicit Nosferatu(int fila, int columna);

    /*
     * Post: obtiene la cantidad de Nosferatu existentes
     */
    static int obtener_existentes();

    void atacar(Tablero *tablero);

    /*
     * Post: decrece en 1 la cantidad de Nosferatu existentes
     */
    ~Nosferatu() override;
};

#endif //NOSFERATUV2_NOSFERATU_H
