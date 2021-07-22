#ifndef NOSFERATUV2_TABLERO_H
#define NOSFERATUV2_TABLERO_H

#include "../../src/main.h"

class Contador;
class Jugador;

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
    Objeto *obtener_elemento_en_posicion(int fila, int columna);

    /*
     * Post: obtiene la cantidad de filas
     */
    int cantidad_filas();

    /*
     * Post: obtiene la cantidad de columnas
     */
    int cantidad_columnas();

    /*
     * Post: Devuelve true  si la fila y columna estan dentro del rango del tablero
     *       False en otro caso
     */
    bool posicion_valida(int fila, int columna);

    /*
     * Pre: El objeto en la fila y columna especificada debe existir
     *      La fila y columna deben estar dentro del rango del tablero
     * Post: Se elimina el objeto en la posicion (fila, columna) pasada por parametro
     */
    void dar_de_baja(int fila, int columna);

    /*
     * Pre: en la posicion no hay ningun objeto (NULL)
     * Post: Se asigna un objeto en la posicion indicada por parametro
     */
    void dar_de_alta(int fila, int columna, Objeto *nuevo_objeto);

    /*
     *
     * Post: obtiene la cantidad de
     */
    int obtener_existentes(const string &nombre);

    /*
    *
    * Post: Se obtiene el porcentaje del objeto en referencia al nombre en el mapa
    */
    float obtener_porcentaje(const string &nombre);

    /*
     * Post: el cuadrante debe ser valido
     * Post: devuelve true si encuentra el objeto hallado en el cuadrante
     */
    bool existe_objeto_en_cuadrante(const string &buscado, Posicion pos_min, Posicion pos_max);

    Jugador *getJugador(int idx);

    /*
     * Post: Libera los recursos asociados
     */
    ~Tablero();

private:
    /* Pre: La cantidad de filas y columnas > 0
     * Post: Reserva en memoria dinamica una matriz
     */
    void inicializar_matriz();

    /*
     * Post: devuelve true si el nombre del objeto buscado es igual al hallado en el tablero
     */
    bool comparar_objetos(const string &buscado, const string &hallado);
};

#endif //NOSFERATUV2_TABLERO_H
