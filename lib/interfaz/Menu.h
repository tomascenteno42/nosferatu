#ifndef NOSFERATUV2_MENU_H
#define NOSFERATUV2_MENU_H

#include "Tablero.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

enum OPCION
{
    MOSTRAR_TABLERO = 1,
    MOSTRAR_RESUMEN,
    BUSCAR_POR_CUADRANTE,
    ALTA,
    BAJA,
    BUSCAR_POR_POSICION,
    MAX_OPCIONES // Delimitador de opciones
};

class Menu
{
private:
    //atributos
    int opcion_elegida;
    Tablero *tablero;

public:
    //metodos

    /*
     * Pre: La direccion del archivo estado.txt debe ser correcta
     * Post: Se crea el menu del juego listo para usarse
     */
    Menu(std::string dir_archivo);

    /*
     * Post: Se muestra por pantalla dos opciones, salir del juego o entrar a las opciones generales
     */
    void acceder_a_opciones();

    /*
     * Post: Se imprime por pantalla las diferentes opciones del menu
     */
    void mostrar_opciones();

    /*
     * Pre: Se debe informar al usuario las opciones que dispone el menu
     * Post: Obtiene la opcion del usuario y la almacena en opcion_elegida.
     */
    void pedir_opcion();

    /* Pre: se debe haber elegido una opcion valida previamente
     * Post: Procesa la opcion elegida
     */
    void procesar_opcion();

    /*
     * Post: Obtiene la opcion elegida
     */
    int obtener_opcion_elegida();

    /*
     * Post: se liberan los recursos asociados (tablero)
     */
    ~Menu();

    //cambiar a private
public:
    //metodos privados

    /*
     * Post: se imprime por pantalla el tablero
     */
    void mostrar_tablero();

    /*
     * Post: Se imprime por pantalla el resumen del juego
     */
    void mostrar_resumen();

    /*
     * Post: Se lleva a cabo una instancia para buscar un objeto a traves
     *       del ingreso manual del usuario
     */
    void buscar_por_cuadrante();

    /*
     * Post: Se lleva a cabo una instancia para dar de alta un objeto a traves
     *       del ingreso manual del usuario
     */
    void dar_de_alta();

    /*
     *  Post: Se lleva a cabo una instancia para dar de baja un objeto a traves
     *        del ingreso manual del usuario
     */
    void dar_de_baja();

    /*
     *  Post: Se lleva a cabo una instancia para buscar un objeto en el tablero
     *        a traves del ingreso manual del usuario
     */
    void buscar_por_posicion();

    /*
    * Post: Devuelve true si la opcion ingresada esta dentro del rango valido
    */
    bool verificar_opcion_valida();

    /* Pre:
     * Post: Devuelve true si el texto ingresado son dos coordenadas separadas y caen
     *       dentro del rango del tablero y guarda las coordenadas
     *       en fila y columna, devuelve false en otro caso
     *       Ejemplo para el rango del tablero (10,10)
     *       texto_ingresado = "asdkfj werwer" -> resultado = false
     *       texto_ingresado = 123 432 -> resultado = false
     *       texto_ingreado = 1 1 -> resultado = true;
     */
    bool rango_valido(const std::string &texto_ingresado, int &fila, int &columna);

    /*
     * Devuelve true si el texto es un numero, false en otro caso
     */
    bool es_un_numero(std::string texto);

    void pedir_posicion(int &fila, int &columna);

    /*  Este metodo le pide al usuario (por pantalla) que elija un objeto
     *  a asignar en el tablero
     * Post: devuelve el objeto elegido por el usuario
     * Warning: Se reserva memoria para la creacion de dicho objeto
     */
    std::string usuario_pedir_objeto();

    /*
     * Post: Pide por pantalla la cantidad deseada de agua o balas
     *       para asignarle a un objeto y lo devuelve
     *
     */
    int usuario_pedir_cantidad();

    /*
     * Post: Devuelve un CUADRANTE elegido por el usuario
     */
    CUADRANTE usuario_pedir_cuadrante();

    /*
     * Post: La zona debe ser un cuadrante valido y el nombre_objeto un nombre valido
     * Post: devuelve true si se halla el objeto en el cuadrante elegido
     */
    bool buscar_objeto_en_cuadrante(const std::string &nombre_objeto, CUADRANTE zona);
};

#endif //NOSFERATUV2_MENU_H
