//
// Created by lucas on 6/5/21.
//

#ifndef NOSFERATUV2_SER_H
#define NOSFERATUV2_SER_H

#include "Objeto.h"

class Ser : public Objeto {
public:

    /*
     * Post: Se crea el npc con la posicion Pos
     */
    explicit Ser(std::string nombre, char caracter);

    /*
     * Post: Se muestra por pantalla la informacion del objeto: nombre
     */
    void mostrar_informacion() override;

};


#endif //NOSFERATUV2_SER_H
