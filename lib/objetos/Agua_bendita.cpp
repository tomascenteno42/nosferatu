#include "../../src/main.h"

Agua_bendita::Agua_bendita(int cantidad, int id, int fila, int columna) : Elemento(S_AGUA_BENDITA, C_AGUA_BENDITA, id, fila, columna)
{
    if (cantidad <= 0)
    {
        throw Excepcion_error("Error, no se puede crear agua_bendita con cantidad menor a 0");
    }
    else
    {
        this->cantidad = cantidad;
    }
}

void Agua_bendita::mostrarInformacion()
{
    cout << this->nombre << ", " << this->cantidad << endl;
}

Agua_bendita::~Agua_bendita()
{
}
