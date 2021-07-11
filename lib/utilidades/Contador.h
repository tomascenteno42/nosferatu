#ifndef NOSFERATUV2_CONTADOR_H
#define NOSFERATUV2_CONTADOR_H

#include <iostream>

#include "../../Constantes.h"

#include "../personajes/Humano.h"
#include "../personajes/Humano_cazador.h"
#include "../personajes/Monstruo.h"
#include "../personajes/Nosferatu.h"
#include "../personajes/Ser.h"
#include "../personajes/Vampirella.h"
#include "../personajes/Vampiro.h"
#include "../personajes/Vanesa.h"
#include "../personajes/Zombi.h"

#include "../objetos/Objeto.h"
#include "../objetos/Agua_bendita.h"
#include "../objetos/Bala.h"
#include "../objetos/Cruz.h"
#include "../objetos/Escopeta.h"
#include "../objetos/Estaca.h"

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
