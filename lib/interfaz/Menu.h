// #ifndef NOSFERATUV2_MENU_H
// #define NOSFERATUV2_MENU_H

// #include "../../src/main.h"

// enum OPCION
// {
//     MOSTRAR_TABLERO = 1,
//     BUSCAR_POR_CUADRANTE,
//     ALTA,
//     BAJA,
//     BUSCAR_POR_ID,
//     MAX_OPCIONES // Delimitador de opciones
// };

// class Menu
// {
// private:
//     //atributos
//     int opcionElegida;
//     Tablero *tablero;

// public:
//     //metodos

//     /*
//      * Pre: La direccion del archivo estado.txt debe ser correcta
//      * Post: Se crea el menu del juego listo para usarse
//      */
//     Menu(string dir_archivo);

//     /*
//      * Post: Se muestra por pantalla dos opciones, salir del juego o entrar a las opciones generales
//      */
//     void accederAOpciones();

//     /*
//      * Post: Se imprime por pantalla las diferentes opciones del menu
//      */
//     void mostrarOpciones();

//     /*
//      * Pre: Se debe informar al usuario las opciones que dispone el menu
//      * Post: Obtiene la opcion del usuario y la almacena en opcion_elegida.
//      */
//     void pedirOpcion();

//     /* Pre: se debe haber elegido una opcion valida previamente
//      * Post: Procesa la opcion elegida
//      */
//     void procesarOpcion();

//     /*
//      * Post: Obtiene la opcion elegida
//      */
//     int getOpcionElegida();

//     /*
//      * Post: se liberan los recursos asociados (tablero)
//      */
//     ~Menu();

//     //cambiar a private
// public:
//     //metodos privados

//     /*
//      * Post: se imprime por pantalla el tablero
//      */
//     void mostrarTablero();

//     /*
//      * Post: Se imprime por pantalla el resumen del juego
//      */
//     void mostrarResumen();

//     /**
//      * @brief Busca por id un objeto en el juego.
//      */
//     void buscarPorId();

//     void imprimirDetallesDeObjeto();

//     /*
//      * Post: Se lleva a cabo una instancia para buscar un objeto a traves
//      *       del ingreso manual del usuario
//      */
//     void buscarPorCuadrante();

//     /*
//      * Post: Se lleva a cabo una instancia para dar de alta un objeto a traves
//      *       del ingreso manual del usuario
//      */
//     void darDeAlta();

//     /*
//      *  Post: Se lleva a cabo una instancia para dar de baja un objeto a traves
//      *        del ingreso manual del usuario
//      */
//     void darDeBaja();

//     /*
//      *  Post: Se lleva a cabo una instancia para buscar un objeto en el tablero
//      *        a traves del ingreso manual del usuario
//      */
//     void buscarPorPosicion();

//     /*
//     * Post: Devuelve true si la opcion ingresada esta dentro del rango valido
//     */
//     bool verificarOpcionValida();

//     /* Pre:
//      * Post: Devuelve true si el texto ingresado son dos coordenadas separadas y caen
//      *       dentro del rango del tablero y guarda las coordenadas
//      *       en fila y columna, devuelve false en otro caso
//      *       Ejemplo para el rango del tablero (10,10)
//      *       texto_ingresado = "asdkfj werwer" -> resultado = false
//      *       texto_ingresado = 123 432 -> resultado = false
//      *       texto_ingreado = 1 1 -> resultado = true;
//      */
//     bool rangoValido(const string &texto_ingresado, int &fila, int &columna);

//     /*
//      * Devuelve true si el texto es un numero, false en otro caso
//      */
//     bool esUnNumero(string texto);

//     void pedirPosicion(int &fila, int &columna);

//     /**
//      * @brief Le pide al usuario la clave a almacenar en el diccionario.
//      *
//      * @return clave
//      */
//     int usuarioPedirClave(ENUM_OBJETOS objeto);

//     /*  Este metodo le pide al usuario (por pantalla) que elija un objeto
//      *  a asignar en el tablero
//      * Post: devuelve el objeto elegido por el usuario
//      * Warning: Se reserva memoria para la creacion de dicho objeto
//      */
//     string usuarioPedirObjeto();

//     /*
//      * Post: Pide por pantalla la cantidad deseada de agua o balas
//      *       para asignarle a un objeto y lo devuelve
//      *
//      */
//     int usuarioPedirCantidad();

//     /*
//      * Post: Devuelve un CUADRANTE elegido por el usuario
//      */
//     CUADRANTE usuarioPedirCuadrante();

//     /*
//      * Post: La zona debe ser un cuadrante valido y el nombre_objeto un nombre valido
//      * Post: devuelve true si se halla el objeto en el cuadrante elegido
//      */
//     bool buscarObjetoEnCuadrante(const string &nombre_objeto, CUADRANTE zona);

//     Tablero *getTablero();
// };

// #endif //NOSFERATUV2_MENU_H
