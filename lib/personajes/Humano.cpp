#include "../../src/main.h"

int Humano::contador = 0;

Humano::Humano() : Ser(S_HUMANO, C_HUMANO)
{
    Humano::contador++;
}

Humano::Humano(std::string nombre, char caracter) : Ser(nombre, caracter)
{
    Humano::contador++;
}

void Humano::agarrarObjeto(Elemento *objeto)
{
    bool contieneEscopeta = false;

    if (objeto->obtener_caracter() == C_ESCOPETA)
    {
        size_t i = 0;

        while (!contieneEscopeta && i < inventario.size())
            if (inventario.at(i)->obtener_caracter() == C_ESCOPETA)
                contieneEscopeta = true;
    }

    if (!contieneEscopeta)
    {
        inventario.push_back(objeto);
    }
}

int Humano::obtener_existentes()
{
    return Humano::contador;
}

Humano::~Humano()
{
    Humano::contador--;
}
