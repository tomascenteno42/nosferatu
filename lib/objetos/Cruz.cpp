#include "../../src/main.h"

Cruz::Cruz(int id, int fila, int columna) : Elemento(S_CRUZ, C_CRUZ, id, fila, columna)
{
    this->cantidad = 1;
}

void Cruz::mostrarInformacion()
{
    cout << this->nombre << endl;
}

Cruz::~Cruz()
{
}
