#ifndef _CONSTANTES_
#define _CONSTANTES_
#include <string>

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
const std::string S_BALA = "bala";
const std::string S_CRUZ = "cruz";
const std::string S_ESTACA = "estaca";
const std::string S_AGUA_BENDITA = "agua";
const std::string S_HUMANO = "humano";
const std::string S_VAMPIRO = "vampiro";
const std::string S_ZOMBI = "zombi";
const std::string S_NOSFERATU = "nosferatu";
const std::string S_VAMPIRELLA = "vampirella";
const std::string S_VANESA = "vanesa";
const std::string S_HUMANO_CV = "humano cv";
const std::string S_ESCOPETA = "escopeta";

const int MAX_OBJETOS = 12;

const std::string PATH_ARCHIVO_ESTADO = "archivos/estado.txt";

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

#endif // _CONSTANTES_