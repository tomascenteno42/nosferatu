#ifndef NOSFERATUV2_PARSER_H
#define NOSFERATUV2_PARSER_H

#include "../../src/main.h"

class Parser
{
private:
    Objeto *objeto_obtenido;
    Posicion *pos;
    string nombre;
    int cantidad;
    int clave;

    /*
     * post: Asigna la cantidad (si es que hay) o si es cazavampiros (caso humano)
     */
    void asignar_especial(const string &especial);

    /* Pre: -
     * Post: Devuelve un objeto (humano, vampiro etc) dependiendo del texto pasado por parametro
     *       Si no hay texto que coincida con algun objeto se lanza un Excepcion_error
     * WARNING: Se crea el objeto en memoria dinamica
     */
    Objeto *obtener_objeto_del_texto(string texto);

public:
    /*
     * Pre: la linea debe provenir del archivo estado.txt
     * Post: Divide la informacion de una linea y la transformar en objetos
     */
    Parser(const string &linea);

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
    Parser(const string &nombre, int cantidad);

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
    string obtener_nombre();

    int getClave();
    /*
     * Post: se libera los recursos (Posicion)
     */
    ~Parser();
};

#endif //NOSFERATUV2_PARSER_H
