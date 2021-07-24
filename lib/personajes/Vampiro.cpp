#include "../../src/main.h"

int Vampiro::contador = 0;

Vampiro::Vampiro(int id) : Monstruo(S_VAMPIRO, C_VAMPIRO, id)
{
    Vampiro::contador++;
}

Vampiro::Vampiro(std::string nombre, char caracter, int id) : Monstruo(nombre, caracter, id)
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
