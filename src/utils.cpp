#include "main.h"

void inicializarJugadores(Jugador *humanos, Jugador *monstruos)
{
    ifstream archivo;

    archivo.open(PATH_ARCHIVO_ESTADO);

    string basura, personaje;

    // Leemos las dimensiones de la matriz,
    // ya que no las necesitamos
    getline(archivo, basura);

    while (!archivo.eof())
    {
        //Lee el personaje
        getline(archivo, personaje, '(');

        //Salteo las posiciones que no sirven en este caso.
        getline(archivo, basura, '\n');

        //Eliminamos el espacio al final
        personaje = personaje.substr(0, personaje.size() - 1);

        BANDO bando = parsearTextoABando(personaje);

        if (bando == HUMANOS)
            humanos->agregarPersonaje(parsearTextoASer(personaje));
        else if (bando == MONSTRUOS)
            monstruos->agregarPersonaje(parsearTextoASer(personaje));
    }
}

BANDO parsearTextoABando(string texto)
{
    toLower(texto);

    if (texto == S_HUMANO || texto == S_HUMANO_CV || texto == S_VANESA)
        return HUMANOS;

    if (texto == S_VAMPIRELLA || texto == S_VAMPIRO || texto == S_NOSFERATU || texto == S_ZOMBI)
        return MONSTRUOS;

    return OBJETO;
}

Ser *parsearTextoASer(string texto)
{
    Ser *ser;

    toLower(texto);

    if (texto == S_HUMANO)
    {
        ser = new Humano();
    }
    else if (texto == S_HUMANO_CV)
    {
        ser = new Humano_cazador();
    }
    else if (texto == S_ZOMBI)
    {
        ser = new Zombi();
    }
    else if (texto == S_VAMPIRO)
    {
        ser = new Vampiro();
    }
    else if (texto == S_VAMPIRELLA)
    {
        ser = new Vampirella();
    }
    else if (texto == S_NOSFERATU)
    {
        ser = new Nosferatu();
    }
    else if (texto == S_VANESA)
    {
        ser = new Vanesa();
    }

    return ser;
}

void toLower(string &str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}