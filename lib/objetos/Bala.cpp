
#include "../../src/main.h"

int Bala::contador = 0;

Bala::Bala(int cantidad, int id, int fila, int columna) : Elemento(S_BALA, C_BALAS, id, fila, columna)
{
    if (cantidad <= 0)
    {
        throw Excepcion_error("no se puede asignar una cantidad menor o igual a 0");
    }
    else
    {
        this->cantidad = cantidad;
        Bala::contador += cantidad;
    }
}

void Bala::mostrarInformacion()
{
    cout << this->nombre << ", " << this->cantidad << endl;
}

int Bala::obtener_existentes()
{
    return Bala::contador;
}

Bala::~Bala()
{
    Bala::contador -= this->cantidad;
}
