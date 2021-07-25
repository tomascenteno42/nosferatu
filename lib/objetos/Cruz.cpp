#include "../../src/main.h"

int Cruz::contador = 0;

Cruz::Cruz(int id, int fila, int columna) : Elemento(S_CRUZ, C_CRUZ, id, fila, columna)
{
    this->cantidad = 1;
    Cruz::contador++;
}

void Cruz::mostrarInformacion()
{
    cout << this->nombre << endl;
}

Cruz::~Cruz()
{
    Cruz::contador--;
}

int Cruz::obtener_existentes()
{
    return Cruz::contador;
}
