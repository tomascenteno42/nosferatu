#ifndef NOSFERATUV2_TABLERO_H
#define NOSFERATUV2_TABLERO_H

#include "../../src/main.h"

class Contador;
class Jugador;

template <class K, class T>
class ABB;

class Tablero
{
private:
    //atributos
    Objeto ***objetos;
    int cant_filas;
    int cant_columnas;
    Contador *contador;

    // jugadores[0] -> HUMANOS
    // jugadores[1] -> MONSTRUOS
    Jugador *jugadores[2];

    ABB<int, Objeto *> *diccionario;

public:
    /*
     * Pre: La direccion (dir) es el directorio del archivo "estado.txt"
     * Post: Crea el tablero de tamanio pos_x y pos_y, ambos > 0
     */
    explicit Tablero(const string &dir);

    /*
     * Post: obtiene el objeto en la posicion indicada por parametro
     *       Si no hay ningun objeto en esa posicion, se retorna un NULL
     */
    Objeto *getElementoEnPosicion(int fila, int columna);

    /*
     * Post: obtiene la cantidad de filas
     */
    int cantidadFilas();

    /*
     * Post: obtiene la cantidad de columnas
     */
    int cantidadColumnas();

    /*
     * Post: Devuelve true  si la fila y columna estan dentro del rango del tablero
     *       False en otro caso
     */
    bool posicionValida(int fila, int columna);

    /*
     * Pre: El objeto en la fila y columna especificada debe existir
     *      La fila y columna deben estar dentro del rango del tablero
     * Post: Se elimina el objeto en la posicion (fila, columna) pasada por parametro
     */
    void darDeBaja(int fila, int columna);

    /*
     * Pre: en la posicion no hay ningun objeto (NULL)
     * Post: Se asigna un objeto en la posicion indicada por parametro
     */
    void darDeAlta(int fila, int columna, Objeto *nuevo_objeto);

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
     * Post: el cuadrante debe ser valido
     * Post: devuelve true si encuentra el objeto hallado en el cuadrante
     */
    bool existeObjetoEnCuadrante(const string &buscado, Posicion pos_min, Posicion pos_max);

    Jugador *getJugador(int idx);

    ABB<int, Objeto *> *getDiccionario();
    /*
     * Post: Libera los recursos asociados
     */
    ~Tablero();

private:
    /* Pre: La cantidad de filas y columnas > 0
     * Post: Reserva en memoria dinamica una matriz
     */
    void inicializarMatriz();

    /*
     * Post: devuelve true si el nombre del objeto buscado es igual al hallado en el tablero
     */
    bool compararObjetos(const string &buscado, const string &hallado);
};

#endif //NOSFERATUV2_TABLERO_H
