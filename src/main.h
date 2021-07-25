#ifndef MAIN_H
#define MAIN_H

using namespace std;

#include <vector>
#include <exception>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>

#include "../Constantes.h"
#include "../lib/excepciones/Excepcion_error.h"

#include "../lib/interfaz/Posicion.h"
#include "../lib/objetos/Objeto.h"
#include "../lib/objetos/Elemento.h"

#include "../lib/personajes/Ser.h"
#include "../lib/personajes/Monstruo.h"

#include "../lib/interfaz/Tablero.h"

#include "jugador.h"

#include "../lib/personajes/Humano.h"
#include "../lib/personajes/Humano_cazador.h"
#include "../lib/personajes/Vanesa.h"

#include "../lib/personajes/Vampiro.h"
#include "../lib/personajes/Nosferatu.h"
#include "../lib/personajes/Vampirella.h"

#include "../lib/personajes/Zombi.h"

#include "../lib/interfaz/Menu.h"

#include "../lib/objetos/Agua_bendita.h"
#include "../lib/objetos/Bala.h"
#include "../lib/objetos/Cruz.h"
#include "../lib/objetos/Escopeta.h"
#include "../lib/objetos/Estaca.h"

#include "../lib/estructuras/Nodo.h"
#include "../lib/estructuras/Lista.h"
#include "../lib/estructuras/NodoABB.h"
#include "../lib/estructuras/ABB.h"

#include "../lib/estructuras/grafo/grafo.h"

#include "../lib/utilidades/Contador.h"
#include "../lib/utilidades/Parser.h"

#include "../lib/interfaz/Casillero.h"
#include "../lib/interfaz/Camino.h"
#include "../lib/interfaz/Lago.h"
#include "../lib/interfaz/Montania.h"
#include "../lib/interfaz/Precipicio.h"
#include "../lib/interfaz/Vacio.h"
#include "../lib/interfaz/Volcan.h"

#include "../lib/interfaz/test.h"
#include "../lib/interfaz/Juego.h"
#include "../lib/interfaz/MenuJuego.h"

// UTILS
BANDO parsearTextoABando(string texto);
ENUM_OBJETOS parsearTextoAObjeto(string texto);
void toLower(string &str);
ID parseId(int id);
bool esIdValido(int id, ENUM_OBJETOS objeto);

// Solicitudes al usuario
/**
 * @brief Solicita al usuario que objeto desea crear
 * 
 * @return string 
 */
string pedirTipoObjeto();

/**
 * @brief Solicita al usuario que cantidad de objetos desea crear.
 * 
 * @return int 
 */
int pedirCantidad();

/**
 * @brief Solicita al usuario que id desea darle al tipo de objeto pasado por parametro
 * 
 * @param objeto
 * @return string 
 */
int pedirId(ABB<int, Objeto *> *diccionario, ENUM_OBJETOS objeto);

/**
 * @brief Solicita al usuario un cuadrante.
 * 
 * @return CUADRANTE 
 */
CUADRANTE pedirCuadrante();

/* IMPORTANTE: MIGRAR A OTRO LADO */
bool buscarObjetoEnCuadrante(const string &nombreObjeto, CUADRANTE zona, Tablero *tablero);

// Validadores
bool esUnNumero(string str);
bool posicionEstaEnTablero(string texto, int &fila, int &columna, Tablero *tablero);

//MENU UTILS
void llenarMenu(Menu *menu, const char *nombre);
int getCantidadOpcionesMenu(const char *nombre);

void mostrarTablero(Tablero *tablero);

/* MENU MAIN */
void procesarAgregarObjeto(MenuJuego *menu);
void procesarEliminarObjeto(MenuJuego *menu);
void procesarBuscarPorCuadrante(MenuJuego *menu);
void procesarMostrarEstadisticasPorId(MenuJuego *menu);
void procesarComenzarSimulacion(MenuJuego *menu);

/* MENU SIMULACION */
void mostrarCantidadPersonajesPorBando(MenuJuego *menu);
void procesarSeleccionBando(MenuJuego *menu);

/* MENU TURNO */
void procesarOpcionDefenderse(MenuJuego *menu);
void procesarOpcionAtacar(MenuJuego *menu);
void procesarOpcionMoverse(MenuJuego *menu);
void procesarOpcionPasarTurno(MenuJuego *menu);

/* MENU COMIENZO DE TURNO */
void procesarGuardarJuego();
void cargarCasillerosGrafo(Grafo *mapa, ifstream &datos);

#endif
