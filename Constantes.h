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

const int MAX_OBJETOS = 12;

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