#include "../../src/main.h"

Menu::Menu(int cantidad)
{
    this->cantidad = cantidad;
    opciones = new string[this->cantidad];
}

void Menu::alta(string opcion)
{
    opciones[index] = opcion;
    index++;
}

string Menu::getOpcion(int idx)
{
    return opciones[idx];
}

int Menu::getCantidad()
{
    return this->cantidad;
}

Menu::~Menu()
{
    delete[] opciones;
}