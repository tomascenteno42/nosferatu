#include "../../src/main.h"

int Vampiro::contador = 0;

Vampiro::Vampiro(int id, int fila, int columna) : Monstruo(S_VAMPIRO, C_VAMPIRO, id, fila, columna)
{
    Vampiro::contador++;
}

Vampiro::Vampiro(std::string nombre, char caracter, int id, int fila, int columna) : Monstruo(nombre, caracter, id, fila, columna)
{
    Vampiro::contador++;
}

int Vampiro::obtener_existentes()
{
    return Vampiro::contador;
}

Vampiro::~Vampiro()
{
    Vampiro::contador--;
}
