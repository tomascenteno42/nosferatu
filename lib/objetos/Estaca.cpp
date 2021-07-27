#include "../../src/main.h"

Estaca::Estaca(int id, int fila, int columna) : Elemento(S_ESTACA, C_ESTACA, id, fila, columna)
{
}

void Estaca::mostrarInformacion()
{
    cout << this->nombre << endl;
}

Estaca::~Estaca()
{
}
