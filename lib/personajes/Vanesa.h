#ifndef NOSFERATUV2_VANESA_H
#define NOSFERATUV2_VANESA_H

#include "../../src/main.h"

class Vanesa : public Humano_cazador
{
private:
    static int contador;

public:
    /*
     * Post: se crea el objeto listo para usarse
     *       Aumenta en 1 la cantidad de objetos Vanesa existentes
     */
    Vanesa(int fila, int columna);

    /*
     * Post: obtiene la cantidad de objetos Vanesa existentes
     */
    static int getContador();

    void atacar(Tablero *tablero);

    void atacarEscopeta(Tablero *tablero);

    void atacarAgua(Tablero *tablero);

    void atacarEstaca(Tablero *tablero);

    /*
     * Post: decrece en 1 la cantidad de objetos Vanesa existentes
     */
    ~Vanesa() override;
};

#endif //NOSFERATUV2_VANESA_H
