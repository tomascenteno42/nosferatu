//
// Created by lucas on 6/5/21.
//

#ifndef NOSFERATUV2_HUMANO_H
#define NOSFERATUV2_HUMANO_H

#include "Ser.h"

class Humano : public Ser{
private:
    static int contador;
public:
    /*
     * Post: Se crea el humano con nombre = S_HUMANO y caracter C_HUMANO
     *       Aumenta en 1 la cantidad de humanos existentes
     */
    Humano();

    /*
     * Post: Se crea un un humano con nombre = "nombre" y caracter "caracter"
     *       Aumenta en 1 la cantidad de humanos existentes
     */
    Humano(std:: string nombre, char caracter);

    /*
     * Post: obtiene la cantidad de humanos (normales) existentes
     */
    static int obtener_existentes();

    /*
     * Post: decrece en 1 la cantidad existentes de humanos
     */
    ~Humano() override;
};


#endif //NOSFERATUV2_HUMANO_H
