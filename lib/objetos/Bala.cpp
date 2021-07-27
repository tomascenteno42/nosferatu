
#include "../../src/main.h"

Bala::Bala(int cantidad, int id, int fila, int columna) : Elemento(S_BALA, C_BALAS, id, fila, columna)
{
    if (cantidad <= 0)
    {
        throw Excepcion_error("no se puede asignar una cantidad menor o igual a 0");
    }
    else
    {
        this->cantidad += cantidad;
    }
}

void Bala::mostrarInformacion()
{
    cout << this->nombre << ", " << this->cantidad << endl;
}

Bala::~Bala()
{
}
