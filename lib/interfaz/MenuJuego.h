#ifndef MENU_JUEGO_H_
#define MENU_JUEGO_H_

#include "../../src/main.h"

class MenuJuego
{
private:
    Lista<Menu *> *menues;
    Menu *menuActual;
    enumMenu idxMenu;

    // Es el mensaje que se le muestra al usuario
    // a la hora de que ingrese un valor.
    string entrada;

    bool salir;

    void setEntrada(string newEntrada);

    /*
     * Llena la lista de menues con las opciones establecidas en los archivos.
     */
    void llenarMenues();

    /**
     * @brief Se encarga de procesar la opcion segun el menu actual.
     * 
     */
    void procesarOpcion(int opcion, ABB<int, Objeto *> *diccionario);

    /**
     * @brief Procesa la opcion elegida en el menu main
     * 
     * @param opcion 
     */
    void procesarOpcionMenuMain(int opcion);

    /**
     * @brief Procesa la opcion elegida en el menu de simulacion
     * 
     * @param opcion 
     */
    void procesarOpcionMenuSimulacion(int opcion);

    /**
     * @brief Procesa la opcion elegida en el menu que se muestra al comienzo de turno
     * 
     * @param opcion 
     */
    void procesarOpcionMenuComienzoTurno(int opcion);

    /**
     * @brief Procesa la opcion elegida en el menu de cada turno
     * 
     * @param opcion 
     */
    void procesarOpcionMenuTurno(int opcion);

    /**
     * @brief Determina si el ingreso por terminal del usuario es valido.
     * 
     * @param ingreso 
     */
    bool esValidaElIngresoDelUsuario(string ingreso);

public:
    Juego *juego;

    MenuJuego(Juego *juego);

    enumMenu getIdxMenuActual();
    string getEntrada();
    bool cerrarMenu();
    /*
     * Cambia el menuActual y el idxMenu al menu especificado.
     */
    void cambiarMenu(enumMenu menu);

    /**
     * @brief Nucleo del menu, se encarga de renderizar la opcion del menu.
     * 
     * @param diccionario 
     */
    void renderizarOpcion(ABB<int, Objeto *> *diccionario);

    /**
     * @brief Muestra las opciones del menuActual
     */
    void mostrarMenu();

    /**
     * @brief Solicita un ingreso por terminal de parte del usuario y la retorna.
     * 
     * @return string Ingreso del usuario
     */
    string solicitarOpcion();

    /**
     * @brief Solicita una posicion (fila columna) al usuario 
     * y modifica los parametros por referencia
     * 
     * @param fila 
     * @param columna 
     */
    void pedirPosicion(int &fila, int &columna);

    ~MenuJuego();
};

#endif