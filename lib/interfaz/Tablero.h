#ifndef NOSFERATUV2_TABLERO_H
#define NOSFERATUV2_TABLERO_H

#include "../../src/main.h"

class Contador;
class Jugador;

template <class K, class T>
class ABB;

class Grafo;

class Tablero
{
private:
    //atributos
    Grafo *mapa;

    Contador *contador;

    // jugadores[0] -> HUMANOS
    // jugadores[1] -> MONSTRUOS
    Jugador *jugadores[2];

    ABB<int, Objeto *> *diccionario;

public:
    int idxJugadorActual;

    /*
     * Pre: La direccion (dir) es el directorio del archivo "estado.txt"
     * Post: Crea el tablero de tamanio pos_x y pos_y, ambos > 0
     */
    explicit Tablero(const string &dir);

    /*
     * Post: obtiene el objeto en la posicion indicada por parametro
     *       Si no hay ningun objeto en esa posicion, se retorna un NULL
     */
    Objeto *getElementoEnPosicion(Posicion pos);

    /*
     * Pre: El objeto en la fila y columna especificada debe existir
     *      La fila y columna deben estar dentro del rango del tablero
     * Post: Se elimina el objeto en la posicion (fila, columna) pasada por parametro
     */
    void darDeBaja(Posicion pos);

    void matarPersonaje(Posicion pos);

    /*
     * Pre: en la posicion no hay ningun objeto (NULL)
     * Post: Se asigna un objeto en la posicion indicada por parametro
     */
    void darDeAlta(Posicion pos, Objeto *nuevo_objeto);

    /*
     *
     * Post: obtiene la cantidad de
     */
    int getExistentes(const string &nombre);

    /*
    *
    * Post: Se obtiene el porcentaje del objeto en referencia al nombre en el mapa
    */
    float getPorcentaje(const string &nombre);

    /*
    *
    * Post: Se obtiene el porcentaje del objeto en referencia al nombre en el mapa
    */
    Grafo *getMapa();

    /*
     * Post: el cuadrante debe ser valido
     * Post: devuelve true si encuentra el objeto hallado en el cuadrante
     */
    bool existeObjetoEnCuadrante(const string &buscado, Posicion minPos, Posicion maxPos);

    /**
     * @brief Buscar el jugador en el indice pasado por parametro (0 o 1)
     * 
     * @param idx 
     * @return Jugador* 
     */
    Jugador *getJugador(int idx);

    /**
     * @brief Busca y devuelve el jugador en el idxJugadorActual
     * 
     * @return Jugador* 
     */
    Jugador *getJugadorActual();

    ABB<int, Objeto *> *getDiccionario();
    /*
     * Post: Libera los recursos asociados
     */
    ~Tablero();

private:
    /*
     * Post: devuelve true si el nombre del objeto buscado es igual al hallado en el tablero
     */
    bool compararObjetos(const string &buscado, const string &hallado);
};

#endif //NOSFERATUV2_TABLERO_H
