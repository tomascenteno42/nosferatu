#include "../../src/main.h"

int Humano_cazador::contador = 0;

Humano_cazador::Humano_cazador(int id) : Humano(S_HUMANO_CV, C_HUMANO_CV, id)
{
    Humano_cazador::contador++;
}

Humano_cazador::Humano_cazador(std::string nombre, char caracter, int id) : Humano(nombre, caracter, id)
{
    Humano_cazador::contador++;
}

int Humano_cazador::obtener_existentes()
{
    return Humano_cazador::contador;
}

Humano_cazador::~Humano_cazador()
{
    Humano_cazador::contador--;
}
