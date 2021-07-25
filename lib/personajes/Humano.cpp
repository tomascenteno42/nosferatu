#include "../../src/main.h"

int Humano::contador = 0;
bool contieneEscopeta = false;

Humano::Humano(int id, int fila, int columna) : Ser(S_HUMANO, C_HUMANO, id, fila, columna)
{
    Humano::contador++;
}

Humano::Humano(std::string nombre, char caracter, int id, int fila, int columna) : Ser(nombre, caracter, id, fila, columna)
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

void Humano::atacar(Tablero *tablero)
{
    bool habilitado = true;
    size_t i = 0;
    if (energia < 5){
        cout << "No papi, no podes hacer eso, te falta energia ლ(ಠ_ಠლ)" <<endl;
        habilitado = false;
    }
    while (contieneEscopeta && i < inventario.size()){
        if (inventario.at(i)->getCaracter() == C_BALAS && inventario.at(i)->obtener_cantidad() < 2){
            cout << "No papi, no podes hacer eso, te faltan balas ლ(ಠ_ಠლ)" <<endl;
            habilitado = false;
        }
    }
    if (habilitado){
        cout << "Indique a quien quiere atacar" << endl;
        cout << "A su alrededor hay: " << endl;
        int danio = 0;
        for (int i = (fila-1); i < (fila+1); i++) {
            for (int j = (columna-1); j < (columna+1); j++) {
                Objeto *objeto_encontrado = tablero->getElementoEnPosicion(i, j);
                if (objeto_encontrado)
                    objeto_encontrado->mostrarInformacion();
            }
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
