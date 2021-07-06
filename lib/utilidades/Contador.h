#ifndef NOSFERATUV2_CONTADOR_H
#define NOSFERATUV2_CONTADOR_H

#include <iostream>
#include "../../Constantes.h"

class Contador
{
private:
public:
    /*
     * Post: se inicia el objeto con las cantidades existentes de las diferentes clases
     */
    Contador();

    /*
     * Se deben haber creado objetos para que la cantidad sea > 0 (No es un requisito)
     * Post: obtiene la cantidad de
     */
    int obtener_cantidad_existentes(const std::string &nombre);

    /*
     * Se deben haber creado objetos para que la cantidad sea > 0 (No es un requisito)
     * Post: Se obtiene el porcentaje del objeto en el mapa
     */
    float obtener_porcentaje(const std::string &nombre);
};

#endif //NOSFERATUV2_CONTADOR_H
