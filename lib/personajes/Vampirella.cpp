#include "../../src/main.h"

int Vampirella::contador = 0;

Vampirella::Vampirella(int fila, int columna) : Vampiro(S_VAMPIRELLA, C_VAMPIRELLA, ID_VAMPIRELLA, fila, columna)
{
    Vampirella::contador++;
}

int Vampirella::obtener_existentes()
{
    return Vampirella::contador;
}

void Vampirella::atacar(Tablero *tablero)
{
    if (this->getEnergia() < 4)
    {
        cout << "No podes hacer eso, te falta energia ლ(ಠ_ಠლ)" << endl;
    }
    if (this->getEnergia() >= 4)
    {
        int filaEnemigo, columnaEnemigo;
        bool puedeAtacar = false;
        cout << "Indique a que posicion quiere atacar" << endl;
        cout << "A su alrededor hay: " << endl;
        Posicion arriba((this->getFila() - 1), this->getColumna());
        Objeto *objetoEncontrado = tablero->getElementoEnPosicion(arriba);
        if (objetoEncontrado)
        {
            if (objetoEncontrado->getCaracter() == C_HUMANO)
            {
                objetoEncontrado->mostrarInformacion();
                puedeAtacar = true;
                cout << "en la posicion: " << objetoEncontrado->getFila() << "," << objetoEncontrado->getColumna()
                     << "\n"
                     << endl;
            }
        }

        Posicion abajo((this->getFila() + 1), this->getColumna());
        objetoEncontrado = tablero->getElementoEnPosicion(abajo);
        if (objetoEncontrado)
        {
            if (objetoEncontrado->getCaracter() == C_HUMANO)
            {
                objetoEncontrado->mostrarInformacion();
                puedeAtacar = true;
                cout << "en la posicion: " << objetoEncontrado->getFila() << "," << objetoEncontrado->getColumna()
                     << "\n"
                     << endl;
            }
        }

        Posicion izquierda(this->getFila(), (this->getColumna() - 1));
        objetoEncontrado = tablero->getElementoEnPosicion(izquierda);
        if (objetoEncontrado)
        {
            if (objetoEncontrado->getCaracter() == C_HUMANO)
            {
                objetoEncontrado->mostrarInformacion();
                puedeAtacar = true;
                cout << "en la posicion: " << objetoEncontrado->getFila() << "," << objetoEncontrado->getColumna()
                     << "\n"
                     << endl;
            }
        }

        Posicion derecha(this->getFila(), (this->getColumna() + 1));
        objetoEncontrado = tablero->getElementoEnPosicion(derecha);
        if (objetoEncontrado)
        {
            if (objetoEncontrado->getCaracter() == C_HUMANO)
            {
                objetoEncontrado->mostrarInformacion();
                puedeAtacar = true;
                cout << "en la posicion: " << objetoEncontrado->getFila() << "," << objetoEncontrado->getColumna()
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
            if (escudo != 0)
                enemigo->setEscudo((enemigo->getEscudo()) - 1);
            this->setEnergia((this->getEnergia()) - 4);
            cout << "Atacado! (☞ ﾟヮﾟ)☞" << endl;
            cout << "Tu enemigo tenia un escudo de " << enemigo->getEscudo() << " entonces tu daño fue de " << danio << endl;
            objeto = tablero->getElementoEnPosicion(Posicion(filaEnemigo, columnaEnemigo));
            enemigo = dynamic_cast<Ser *>(objeto);
            enemigo->mostrarInformacion();
        }
    }
}

Vampirella::~Vampirella()
{
    Vampirella::contador--;
}
