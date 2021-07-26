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
    Vampiro(int id, int fila, int columna);

    /*
     * Post: Se crea el objeto Vampiro con nombre y caracter pasado por parametro
     *       Aumenta en 1 la cantidad de objetos Vampiro existentes
     */
    Vampiro(string nombre, char caracter, int id, int fila, int columna);

    /*
     * Post: aumenta en 1 la cantidad de objetos Vampiro existentes
     */
    static int obtener_existentes();

    void atacar(Tablero *tablero);

    void actualizar() override;

    /*
     * Post: decrece en 1 la cantidad de objetos Vampiro existentes
     */
    ~Vampiro() override;
};

#endif //NOSFERATUV2_VAMPIRO_H
