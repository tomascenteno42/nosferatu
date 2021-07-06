#ifndef NOSFERATUV2_PARSER_H
#define NOSFERATUV2_PARSER_H

#include "../../Constantes.h"
#include "../excepciones/Excepcion_error.h"
#include "../interfaz/Posicion.h"
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

#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>

class Parser
{
private:
    Objeto *objeto_obtenido;
    std::string nombre;
    int cantidad;
    Posicion *pos;

    /*
     * post: Asigna la cantidad (si es que hay) o si es cazavampiros (caso humano)
     */
    void asignar_especial(const std::string &especial);

    /* Pre: -
     * Post: Devuelve un objeto (humano, vampiro etc) dependiendo del texto pasado por parametro
     *       Si no hay texto que coincida con algun objeto se lanza un Excepcion_error
     * WARNING: Se crea el objeto en memoria dinamica
     */
    Objeto *obtener_objeto_del_texto(std::string texto);

public:
    /*
     * Pre: la linea debe provenir del archivo estado.txt
     * Post: Divide la informacion de una linea y la transformar en objetos
     */
    Parser(const std::string &linea);

    /* Metodo que guarda el nombre de un objeto a partir del enumerado ENUM_OBJETOS
     * Post: se crea el objeto Parser con datos:
     *       Nombre del objeto (a partir del enumerado)
     *       El objeto en si no se crea
     *       No se guardan posiciones
     *       No se guardan cantidades
     */
    Parser(ENUM_OBJETOS enum_objeto);

    /*
     * Pre: cantidad > 0 y el nombre debe ser alguno de los asociados a los objetos
     * Post: Guarda un objeto a partir del nombre y la cantidad, con posiciones nulas.
     *
     */
    Parser(const std::string &nombre, int cantidad);

    /*
     * Post: Devuelve el objeto creado en memoria dinamica
     */
    Objeto *obtener_objeto();

    /*
     * Pre: -
     * Post: Devuelve la posicion del objeto
     */
    Posicion *obtener_posicion();

    /*
     * Post: devuelve el nombre del objeto
     */
    std::string obtener_nombre();

    /*
     * Post: se libera los recursos (Posicion)
     */
    ~Parser();
};

#endif //NOSFERATUV2_PARSER_H
