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

    cout << "Inventario: " << endl;

    for (int i = 0; i < tamanio - 1; i++)
        cout << inventario.at(i)->getNombre() << "|";

    cout << inventario.at(tamanio - 1)->getNombre() << endl
         << endl;
}

void Humano::atacar(Juego *juego)
{
    int filaEnemigo, columnaEnemigo, posBalas;
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
        else if (inventario.at(i)->getCaracter() == C_BALAS && inventario.at(i)->getCantidad() >= 2)
        {
            contieneBalas = true;
            posBalas = i;
        }
        i++;
    }
    if (!contieneBalas && contieneEscopeta && this->getEnergia() >= 5)
        cout << "No podes hacer eso, te faltan balas ლ(ಠ_ಠლ)" << endl;

    else if (contieneEscopeta && contieneBalas && this->getEnergia() >= 6)
    {
        Ser *personaje = dynamic_cast<Ser *>(juego->tablero->getElementoEnPosicion(Posicion(fila, columna)));
        cout << "Indique a que posicion quiere atacar" << endl;
        cout << "A su alrededor hay los siguiente personajes: " << endl;
        for (int i = (this->fila - 1); i <= (this->fila + 1); i++)
        {
            for (int j = (this->columna - 1); j <= (this->columna + 1); j++)
            {
                Objeto *objetoEncontrado = juego->tablero->getElementoEnPosicion(Posicion(i, j));
                if (objetoEncontrado)
                {
                    if (objetoEncontrado->getCaracter() == C_ZOMBI || objetoEncontrado->getCaracter() == C_VAMPIRO && (objetoEncontrado != this))
                    {
                        objetoEncontrado->mostrarInformacion();
                        puedeAtacar = true;
                        cout << "En la posicion: " << objetoEncontrado->getFila() << "," << objetoEncontrado->getColumna();
                        cout << endl
                             << endl;
                    }
                }
            }
        }
        if (!puedeAtacar)
            cout << "No tenes enemigos cerca para atacarlos" << endl;
        else
        {
            cout << "Ingrese la fila" << endl;
            cin >> filaEnemigo;
            cout << "Ingrese la columna" << endl;
            cin >> columnaEnemigo;

            Objeto *objeto = juego->tablero->getElementoEnPosicion(Posicion(filaEnemigo, columnaEnemigo));
            Ser *enemigo = dynamic_cast<Ser *>(objeto);

            int danio;
            int escudo = enemigo->getEscudo();

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
            //this->inventario.at(posBalas)->setCantidad() -= 2;
            cout << "Atacado! (☞ ﾟヮﾟ)☞" << endl;
            cout << "Tu enemigo tenia un escudo de " << enemigo->getEscudo() << " entonces tu daño fue de " << danio
                 << endl;
            objeto = juego->tablero->getElementoEnPosicion(Posicion(filaEnemigo, columnaEnemigo));
            enemigo = dynamic_cast<Ser *>(objeto);
            enemigo->mostrarInformacion();
        }
    }
}

int Humano::obtener_existentes()
{
    return Humano::contador;
}

void Humano::actualizar()
{
    this->energia += 5;
}

Humano::~Humano()
{
    Humano::contador--;
}
