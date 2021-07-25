#include "main.h"

bool posicionEstaEnTablero(string texto, int &fila, int &columna, Tablero *tablero)
{
    bool rangoValido = false;

    string posicionX, posicionY;
    istringstream input(texto);

    getline(input, posicionX, ' ');
    getline(input, posicionY, ' ');

    if (esUnNumero(posicionX) && esUnNumero(posicionY))
    {
        fila = stoi(posicionX);
        columna = stoi(posicionY);
        rangoValido = tablero->getMapa()->coordenadaValida(Posicion(fila, columna));
    }

    return rangoValido;
}

bool esUnNumero(string str)
{
    bool esUnNumero = true;

    long unsigned i = 0;

    while (esUnNumero && i < str.length())
    {
        esUnNumero = isdigit(str[i]);
        i++;
    }

    return esUnNumero;
}