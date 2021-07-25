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
        fila = stoi(posicionX) - 1;
        columna = stoi(posicionY) - 1;
        rangoValido = tablero->posicionValida(fila, columna);
    }
    return rangoValido;
}

bool esUnNumero(string str)
{
    for (int i = 0; i < str.length(); i++)
        if ((int)str[i] < 48 || (int)str[i] > 57)
            return false;

    return true;
}