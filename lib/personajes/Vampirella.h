#ifndef NOSFERATUV2_VAMPIRELLA_H
#define NOSFERATUV2_VAMPIRELLA_H

#include "../../src/main.h"

class Vampirella : public Vampiro
{
private:
    static int contador;

public:
    /*
     * Post: se crea el objeto listo para usarse
     *       Aumenta en 1 la cantidad de objetos vampirella existentes
     */
    Vampirella(int fila, int columna);

    /*
     * Post: obtiene la cantidad de objetos vampirella existentes
     */
    static int obtener_existentes();

    void atacar(Tablero *tablero);

    void actualizar() override;
    /*
     * Post: decrece en 1 la cantidad de objetos vampirella existentes
     */
    ~Vampirella() override;
};

#endif
