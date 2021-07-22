#ifndef NOSFERATUV2_HUMANO_CAZADOR_H
#define NOSFERATUV2_HUMANO_CAZADOR_H

#include "../../src/main.h"

class Humano_cazador : public Humano
{
private:
    static int contador;

public:
    /*
     * Post: Se crea el objeto listo para usarse
     *       Aumenta en 1 la cantidad de humanos cazadores existentes
     */
    Humano_cazador();

    /* Humano Cazador Especial *
     * Post: Se crea el objeto, con el nombre y caracter pasado por parametros
     *       Aumenta en 1 la cantidad de humanos cazadores existentes
     */
    Humano_cazador(std::string nombre, char caracter);

    /*
     * Post: obtiene la cantidad de humanos cazadores existentes
     */
    static int obtener_existentes();

    /*
     * Post: decrece en 1 la cantidad de humanos cazadores existentes
     */
    ~Humano_cazador() override;
};

#endif //NOSFERATUV2_HUMANO_CAZADOR_H
