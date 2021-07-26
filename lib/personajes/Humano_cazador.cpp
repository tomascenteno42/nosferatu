#include "../../src/main.h"

int Humano_cazador::contador = 0;

Humano_cazador::Humano_cazador(int id, int fila, int columna) : Humano(S_HUMANO_CV, C_HUMANO_CV, id, fila, columna)
{
    Humano_cazador::contador++;
}

Humano_cazador::Humano_cazador(string nombre, char caracter, int id, int fila, int columna) : Humano(nombre, caracter, id, fila, columna)
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
