#include "../../src/main.h"

int Agua_bendita::contador = 0;

Agua_bendita::Agua_bendita(int cantidad, int id) : Elemento(S_AGUA_BENDITA, C_AGUA_BENDITA, id)
{
    if (cantidad <= 0)
    {
        throw Excepcion_error("Error, no se puede crear agua_bendita con cantidad menor a 0");
    }
    else
    {
        this->cantidad = cantidad;
        Agua_bendita::contador += cantidad;
    }
}

void Agua_bendita::mostrarInformacion()
{
    cout << this->nombre << ", " << this->cantidad << endl;
}

int Agua_bendita::obtener_existentes()
{
    return Agua_bendita::contador;
}

Agua_bendita::~Agua_bendita()
{
    Agua_bendita::contador -= cantidad;
}
