#include "../../src/main.h"

int Escopeta::contador = 0;

Escopeta::Escopeta(int id) : Elemento(S_ESCOPETA, C_ESCOPETA, id)
{
    Escopeta::contador++;
}

void Escopeta::mostrarInformacion()
{
    cout << this->nombre << endl;
}

int Escopeta::obtener_existentes()
{
    return Escopeta::contador;
}

Escopeta::~Escopeta()
{
    Escopeta::contador--;
}
