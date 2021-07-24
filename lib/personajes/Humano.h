#ifndef NOSFERATUV2_HUMANO_H
#define NOSFERATUV2_HUMANO_H

#include "../../src/main.h"

class Humano : public Ser
{
private:
    static int contador;
    vector<Elemento *> inventario;

public:
    /*
     * Post: Se crea el humano con nombre = S_HUMANO y caracter C_HUMANO
     *       Aumenta en 1 la cantidad de humanos existentes
     */
    Humano(int id);

    /*
     * Post: Se crea un un humano con nombre = "nombre" y caracter "caracter"
     *       Aumenta en 1 la cantidad de humanos existentes
     */
    Humano(string nombre, char caracter, int id);

    /**
     * @brief Agrega el objeto pasado por parametro a el inventario.
     * 
     * @param objeto 
     */
    void agarrarObjeto(Elemento *objeto);

    /*
     * Post: obtiene la cantidad de humanos (normales) existentes
     */
    static int obtener_existentes();

    /*
     * Post: decrece en 1 la cantidad existentes de humanos
     */
    ~Humano() override;
};

#endif
