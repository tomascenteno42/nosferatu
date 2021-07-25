#include "../../src/main.h"

Ser::Ser(std::string nombre, char caracter, int id, int fila, int columna) : Objeto(nombre, caracter, id, fila, columna)
{
    nombre = nombre;
    caracter = caracter;
    energia = rand() % 20;
    vida = rand() % 100 + 20;
    escudo = rand() % 2;
    fuerza = rand() % 30 + 10;

}

/* GETTERS */

int Ser::getEnergia()
{
    return energia;
}

int Ser::getVida()
{
    return vida;
}

int Ser::getEscudo()
{
    return escudo;
}

int Ser::getFuerza()
{
    return fuerza;
}

/* SETTERS */

void Ser::setEnergia(int e)
{
    energia = e;
}

void Ser::setVida(int v)
{
    vida = v;
}

void Ser::setEscudo(int e)
{
    escudo = e;
}

void Ser::setFuerza(int f)
{
    fuerza = f;
}

void Ser::ajustarDanio(int &danio)
{
    switch (getEscudo())
    {
    case 0:
        break;
    case 1:
        danio *= 0.9;
        break;
    case 2:
        danio *= 0.8;
        break;
    default:
        danio *= 0.2;
        break;
    }
}

bool Ser::estaMuerto()
{
    return getVida() == 0;
}

void Ser::mostrarInformacion()
{
    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Escudo: " << escudo << endl;
    cout << "Fuerza: " << fuerza << endl;
}
