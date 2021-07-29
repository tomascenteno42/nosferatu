#ifndef MAIN_H
#define MAIN_H

using namespace std;

#ifdef __linux__
#include <unistd.h>
#include <chrono>
#include <thread>
#define Sleep(x) std::this_thread::sleep_for(std::chrono::milliseconds(x));
#elif _WIN32
#include <windows.h>
#endif

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

#include "../lib/utilidades/Parser.h"

#include "../lib/interfaz/Casillero.h"
#include "../lib/interfaz/Camino.h"
#include "../lib/interfaz/Lago.h"
#include "../lib/interfaz/Montania.h"
#include "../lib/interfaz/Precipicio.h"
#include "../lib/interfaz/Vacio.h"
#include "../lib/interfaz/Volcan.h"

#include "../lib/interfaz/Menu.h"
#include "../lib/interfaz/Juego.h"

// ARCHIVOS
void guardarItems(ABB<int, Objeto *> *diccionario, ofstream &archivo);
void guardarPersonajes(int cantidadPersonajes, Jugador *jugador, ofstream &archivo);

// UTILS
void clearTerminal();
void mostrarBando(BANDO bando);

string parsearBandoATexto(BANDO bando);
BANDO parsearTextoABando(string texto);
BANDO parseBando(string texto);

ENUM_OBJETOS parsearTextoAObjeto(string texto);
void toLower(string &str);
ID parseId(int id);
bool esIdValido(int id, ENUM_OBJETOS objeto);
vector<Posicion> *obtenerPosiciones(Grafo *mapa, vector<int> *camino);
void mostrarPosiciones(vector<Posicion> *posiciones);

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

BANDO pedirBando();

/* IMPORTANTE: MIGRAR A OTRO LADO */
bool buscarObjetoEnCuadrante(const string &nombreObjeto, CUADRANTE zona, Tablero *tablero);

// Validadores
bool esUnNumero(string str);
bool posicionEstaEnTablero(string texto, int &fila, int &columna, Tablero *tablero);

//MENU UTILS
void llenarMenu(Menu *menu, const char *nombre);
int getCantidadOpcionesMenu(const char *nombre);

/* MENU MAIN */
void procesarAgregarObjeto(Juego *juego);
void procesarEliminarObjeto(Juego *juego);
void procesarBuscarPorCuadrante(Juego *juego);
void procesarMostrarEstadisticasPorId(Juego *juego);
void procesarComenzarSimulacion(Juego *juego);

/* MENU SIMULACION */
void mostrarCantidadPersonajesPorBando(Juego *juego);
void procesarSeleccionBando(Juego *juego);

/* MENU TURNO */
void procesarOpcionDefenderse(Juego *juego);
void procesarOpcionAtacar(Juego *juego);
void procesarOpcionMoverse(Juego *juego);
void procesarOpcionPasarTurno(Juego *juego);

/* MENU COMIENZO DE TURNO */
void procesarGuardarJuego(Juego *juego);
void cargarCasillerosGrafo(Grafo *mapa, ifstream &datos);

#endif
