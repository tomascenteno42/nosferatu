#include "../../src/main.h"

int Humano::contador = 0;
bool contieneEscopeta = false;

Humano::Humano(int id, int fila, int columna) : Ser(S_HUMANO, C_HUMANO, id, fila, columna)
{
    Humano::contador++;
}

Humano::Humano(string nombre, char caracter, int id, int fila, int columna) : Ser(nombre, caracter, id, fila, columna)
{
    Humano::contador++;
}

void Humano::agarrarObjeto(Elemento *objeto)
{

    if (objeto->getCaracter() == C_ESCOPETA)
    {
        size_t i = 0;

        while (!contieneEscopeta && i < inventario.size())
            if (inventario.at(i)->getCaracter() == C_ESCOPETA)
                contieneEscopeta = true;
    }

    if (!contieneEscopeta)
    {
        inventario.push_back(objeto);
    }
}

bool Humano::inventarioVacio()
{
    return ((int)inventario.size() == 0);
}

void Humano::mostrarInventario()
{
    int tamanio = (int)inventario.size();
    for(int i = 0; i < tamanio - 1; i++)
        cout << inventario.at(i)->getNombre() << "|";
    cout << inventario.at(tamanio - 1)->getNombre() << endl;
    cout << endl;
}

void Humano::atacar(Tablero *tablero)
{
    int fila_enemigo, columna_enemigo;
    bool habilitado = true;
    size_t i = 0;
    if (energia < 5)
    {
        cout << "No papi, no podes hacer eso, te falta energia ლ(ಠಠლ)" << endl;
        habilitado = false;
    }
    while (contieneEscopeta && i < inventario.size())
    {
        if (inventario.at(i)->getCaracter() == C_BALAS && inventario.at(i)->getCantidad() < 2)
        {
            cout << "No papi, no podes hacer eso, te faltan balas ლ(ಠಠლ)" << endl;
            habilitado = false;
        }
    }
    if (habilitado)
    {
        Ser *personaje = dynamic_cast<Ser *>(tablero->getElementoEnPosicion(Posicion(fila, columna)));
        cout << "Indique a que posicion quiere atacar" << endl;
        cout << "A su alrededor hay: " << endl;
        int danio = 0;
        for (int i = (fila - 1); i < (fila + 1); i++)
        {
            for (int j = (columna - 1); j < (columna + 1); j++)
            {
                Objeto *objeto_encontrado = tablero->getElementoEnPosicion(Posicion(i, j));
                if (objeto_encontrado)
                    objeto_encontrado->mostrarInformacion();
                cout << "en la posicion" << objeto_encontrado->getFila() << "," << objeto_encontrado->getColumna() << endl;
            }
        }
        cout << "Ingrese la fila" << endl;
        cin >> fila_enemigo;

        cout << "Ingrese la columna" << endl;
        cin >> columna_enemigo;

        Ser *enemigo = dynamic_cast<Ser *>(tablero->getElementoEnPosicion(Posicion(fila_enemigo, columna_enemigo))); // works fine
        if (enemigo->getCaracter() == C_ZOMBI)
        {
            enemigo->setVida((enemigo->getVida() - personaje->getFuerza()));
        }
        else if (enemigo->getCaracter() == C_VAMPIRO)
        {
            enemigo->setVida(enemigo->getVida() - ((personaje->getFuerza())));
        }
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
