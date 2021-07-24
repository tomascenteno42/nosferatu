#include "../../src/main.h"

int Estaca::contador = 0;

Estaca::Estaca(int id) : Elemento(S_ESTACA, C_ESTACA, id)
{
    Estaca::contador++;
}

void Estaca::mostrarInformacion()
{
    cout << this->nombre << endl;
}

int Estaca::obtener_existentes()
{
    return Estaca::contador;
}

Estaca::~Estaca()
{
    Estaca::contador--;
}
