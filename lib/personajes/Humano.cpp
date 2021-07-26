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

    cout << "Inventario: " << endl
         << endl;

    for (int i = 0; i < tamanio - 1; i++)
        cout << inventario.at(i)->getNombre() << "|";
    cout << inventario.at(tamanio - 1)->getNombre() << endl;
    cout << endl;
}

void Humano::atacar(Tablero *tablero)
{
    int fila_enemigo, columna_enemigo, posicion_balas;
    size_t i = 0;
    bool puedeAtacar = false;
    if (this->getEnergia() < 5)
    {
        cout << "No podes hacer eso, te falta energia ლ(ಠ_ಠლ)" << endl;
    }
    while (i < inventario.size() && this->getEnergia() >= 5)
    {
        if (inventario.at(i)->getCaracter() == C_ESCOPETA)
            contieneEscopeta = true;
        else if (inventario.at(i)->getCaracter() == C_BALAS && inventario.at(i)->getCantidad() > 2)
        {
            contieneBalas = true;
            posicion_balas = i;
        }
        i++;
    }
    if (!contieneBalas && contieneEscopeta && this->getEnergia() >= 5)
        cout << "No podes hacer eso, te faltan balas ლ(ಠ_ಠლ)" << endl;
    else if (contieneEscopeta && contieneBalas && this->getEnergia() >= 6)
    {
        Ser *personaje = dynamic_cast<Ser *>(tablero->getElementoEnPosicion(Posicion(fila, columna)));
        cout << "Indique a que posicion quiere atacar" << endl;
        cout << "A su alrededor hay: " << endl;
        for (int i = (this->fila - 1); i <= (this->fila + 1); i++)
        {
            for (int j = (this->columna - 1); j <= (this->columna + 1); j++)
            {
                Objeto *objeto_encontrado = tablero->getElementoEnPosicion(Posicion(i, j));
                if (objeto_encontrado)
                {
                    if (objeto_encontrado->getCaracter() == C_ZOMBI || objeto_encontrado->getCaracter() == C_VAMPIRO && (objeto_encontrado != this))
                    {
                        objeto_encontrado->mostrarInformacion();
                        puedeAtacar = true;
                        cout << "en la posicion: " << objeto_encontrado->getFila() << "," << objeto_encontrado->getColumna()
                             << "\n"
                             << endl;
                    }
                }
            }
        }
        if (!puedeAtacar)
            cout << "No tenes enemigos cerca para atacarlos" << endl;
        else if (puedeAtacar)
        {
            cout << "Ingrese la fila" << endl;
            cin >> fila_enemigo;
            cout << "Ingrese la columna" << endl;
            cin >> columna_enemigo;
            Objeto *objeto = tablero->getElementoEnPosicion(Posicion(fila_enemigo, columna_enemigo));
            Ser *enemigo = dynamic_cast<Ser *>(objeto);
            int danio, escudo;
            escudo = enemigo->getEscudo();
            if (enemigo->getCaracter() == C_ZOMBI)
            {
                danio = (this->getFuerza());
                ajustarDanio(danio, escudo);
                enemigo->setVida(enemigo->getVida() - danio);
            }
            else if (enemigo->getCaracter() == C_VAMPIRO)
            {
                danio = (((this->getFuerza()) * 0.20));
                ajustarDanio(danio, escudo);
                enemigo->setVida(enemigo->getVida() - danio);
            }
            this->setEnergia((this->getEnergia()) - 5);
            //this->inventario.at(posicion_balas)->setCantidad() -= 2;
            cout << "Atacado! (☞ ﾟヮﾟ)☞" << endl;
            cout << "Tu enemigo tenia un escudo de " << enemigo->getEscudo() << " entonces tu daño fue de " << danio
                 << endl;
            objeto = tablero->getElementoEnPosicion(Posicion(fila_enemigo, columna_enemigo));
            enemigo = dynamic_cast<Ser *>(objeto);
            enemigo->mostrarInformacion();
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
