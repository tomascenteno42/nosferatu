
#include "../../src/main.h"

int Vampiro::contador = 0;

Vampiro::Vampiro(int id, int fila, int columna) : Monstruo(S_VAMPIRO, C_VAMPIRO, id, fila, columna)
{
    Vampiro::contador++;
}

Vampiro::Vampiro(string nombre, char caracter, int id, int fila, int columna) : Monstruo(nombre, caracter, id, fila, columna)
{
    Vampiro::contador++;
}

int Vampiro::obtener_existentes()
{
    return Vampiro::contador;
}

void Vampiro::atacar(Tablero *tablero)
{
    if (this->getEnergia() < 2)
    {
        cout << "No podes hacer eso, te falta energia ლ(ಠ_ಠლ)" << endl;
    }
    if (this->getEnergia() >= 2)
    {
        int filaEnemigo, columnaEnemigo;
        bool puedeAtacar = false;
        cout << "Indique a que posicion quiere atacar" << endl;
        cout << "A su alrededor hay: " << endl;
        Posicion arriba((this->getFila() - 1), this->getColumna());
        Objeto *objeto_encontrado = tablero->getElementoEnPosicion(arriba);
        if (objeto_encontrado)
        {
            if (objeto_encontrado->getCaracter() == C_HUMANO)
            {
                objeto_encontrado->mostrarInformacion();
                puedeAtacar = true;
                cout << "en la posicion: " << objeto_encontrado->getFila() << "," << objeto_encontrado->getColumna()
                     << "\n"
                     << endl;
            }
        }

        Posicion abajo((this->getFila() + 1), this->getColumna());
        objeto_encontrado = tablero->getElementoEnPosicion(abajo);
        if (objeto_encontrado)
        {
            if (objeto_encontrado->getCaracter() == C_HUMANO)
            {
                objeto_encontrado->mostrarInformacion();
                puedeAtacar = true;
                cout << "en la posicion: " << objeto_encontrado->getFila() << "," << objeto_encontrado->getColumna()
                     << "\n"
                     << endl;
            }
        }

        Posicion izquierda(this->getFila(), (this->getColumna() - 1));
        objeto_encontrado = tablero->getElementoEnPosicion(izquierda);
        if (objeto_encontrado)
        {
            if (objeto_encontrado->getCaracter() == C_HUMANO)
            {
                objeto_encontrado->mostrarInformacion();
                puedeAtacar = true;
                cout << "en la posicion: " << objeto_encontrado->getFila() << "," << objeto_encontrado->getColumna()
                     << "\n"
                     << endl;
            }
        }

        Posicion derecha(this->getFila(), (this->getColumna() + 1));
        objeto_encontrado = tablero->getElementoEnPosicion(derecha);
        if (objeto_encontrado)
        {
            if (objeto_encontrado->getCaracter() == C_HUMANO)
            {
                objeto_encontrado->mostrarInformacion();
                puedeAtacar = true;
                cout << "en la posicion: " << objeto_encontrado->getFila() << "," << objeto_encontrado->getColumna()
                     << "\n"
                     << endl;
            }
        }
        if (!puedeAtacar)
            cout << "No tenes enemigos cerca para atacarlos" << endl;
        else if (puedeAtacar)
        {
            cout << "Ingrese la fila" << endl;
            cin >> filaEnemigo;
            cout << "Ingrese la columna" << endl;
            cin >> columnaEnemigo;
            Objeto *objeto = tablero->getElementoEnPosicion(Posicion(filaEnemigo, columnaEnemigo));
            Ser *enemigo = dynamic_cast<Ser *>(objeto);
            int danio, escudo;
            escudo = enemigo->getEscudo();
            danio = (this->getFuerza());
            ajustarDanio(danio, escudo);
            enemigo->setVida(enemigo->getVida() - danio);
            this->setEnergia((this->getEnergia()) - 2);
            cout << "Atacado! (☞ ﾟヮﾟ)☞" << endl;
            cout << "Tu enemigo tenia un escudo de " << enemigo->getEscudo() << " entonces tu daño fue de " << danio << endl;
            objeto = tablero->getElementoEnPosicion(Posicion(filaEnemigo, columnaEnemigo));
            enemigo = dynamic_cast<Ser *>(objeto);
            enemigo->mostrarInformacion();
        }
    }
}

void Vampiro::actualizar()
{
    cout << "ACTUALIZAR";
}

Vampiro::~Vampiro()
{
    Vampiro::contador--;
}
