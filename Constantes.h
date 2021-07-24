#ifndef _CONSTANTES_
#define _CONSTANTES_

#include "./src/main.h"

//Caracteres que aparecen en el mapa
const char C_HUMANO = 'h';
const char C_HUMANO_CV = 'H';
const char C_VAMPIRO = 'v';
const char C_ZOMBI = 'z';
const char C_VACIO = '*';
const char C_AGUA_BENDITA = 'a';
const char C_VAMPIRELLA = 'V';
const char C_VANESA = 'W';
const char C_NOSFERATU = 'N';
const char C_CRUZ = 'c';
const char C_ESTACA = 'e';
const char C_ESCOPETA = 'E';
const char C_BALAS = 'b';

//strings de los nombres
const string S_BALA = "bala";
const string S_CRUZ = "cruz";
const string S_ESTACA = "estaca";
const string S_AGUA_BENDITA = "agua";
const string S_HUMANO = "humano";
const string S_VAMPIRO = "vampiro";
const string S_ZOMBI = "zombi";
const string S_NOSFERATU = "nosferatu";
const string S_VAMPIRELLA = "vampirella";
const string S_VANESA = "vanesa";
const string S_HUMANO_CV = "humano cv";
const string S_ESCOPETA = "escopeta";

//strings de los casilleros
const string MONTANIA = "M";
const string PRECIPICIO = "P";
const string CAMINO = "C";
const string LAGO = "L";
const string VOLCAN = "V";
const string VACIO = "O";

//colores de los casilleros
const string COLOR_LAGO = "\e[30;44m";
const string COLOR_VOLCAN = "\e[30;41m";
const string COLOR_PRECIPICIO = "\e[30;107m";
const string COLOR_MONTANIA = "\e[30;43m";
const string COLOR_CAMINO = "\e[30;103m";
const string COLOR_VACIO = "\e[30;45m";
const string SIN_COLOR = "\e[0m";

const int MAX_OBJETOS = 12;
const int MAX_ID = 999;

const string PATH_ARCHIVO_ESTADO = "archivos/estado.txt";

enum ENUM_OBJETOS
{
    HUMANO = 1,
    HUMANO_CV,
    ZOMBIE,
    VAMPIRO,
    VAMPIRELLA,
    NOSFERATU,
    VANESA,
    AGUA_BENDITA,
    CRUZ,
    ESTACA,
    ESCOPETA,
    BALAS
};

enum ID
{
    ID_VANESA = 0,
    ID_HUMANO = 1,
    ID_HUMANO_CV = 50,
    ID_ZOMBIE = 100,
    ID_NOSFERATU = 200,
    ID_VAMPIRELLA = 201,
    ID_VAMPIRO = 202,
    ID_AGUA_BENDITA = 300,
    ID_CRUZ = 320,
    ID_ESCOPETA = 340,
    ID_BALAS = 360,
    ID_ESTACA = 380,
    ID_NO_VALIDO = 1000
};

enum CUADRANTE
{
    NOROESTE = 1,
    NORESTE,
    SUROESTE,
    SURESTE
};

enum BANDO
{
    HUMANOS = 1,
    MONSTRUOS = 2,
    OBJETO = 3
};

#endif // _CONSTANTES_