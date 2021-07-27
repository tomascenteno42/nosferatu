#include "../../src/main.h"

Escopeta::Escopeta(int id, int fila, int columna) : Elemento(S_ESCOPETA, C_ESCOPETA, id, fila, columna)
{
}

void Escopeta::mostrarInformacion()
{
    cout << this->nombre << endl;
}

Escopeta::~Escopeta()
{
}
