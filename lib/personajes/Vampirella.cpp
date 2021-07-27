#include "../../src/main.h"

Vampirella::Vampirella(int fila, int columna) : Vampiro(S_VAMPIRELLA, C_VAMPIRELLA, ID_VAMPIRELLA, fila, columna)
{
}

void Vampirella::atacar(Juego *juego)
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
        Objeto *objetoEncontrado = juego->tablero->getElementoEnPosicion(arriba);
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
        objetoEncontrado = juego->tablero->getElementoEnPosicion(abajo);
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
        objetoEncontrado = juego->tablero->getElementoEnPosicion(izquierda);
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
        objetoEncontrado = juego->tablero->getElementoEnPosicion(derecha);
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
            Objeto *objeto = juego->tablero->getElementoEnPosicion(Posicion(filaEnemigo, columnaEnemigo));
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
            objeto = juego->tablero->getElementoEnPosicion(Posicion(filaEnemigo, columnaEnemigo));
            enemigo = dynamic_cast<Ser *>(objeto);
            enemigo->mostrarInformacion();
        }
    }
}

void Vampirella::actualizar()
{
    int nuevaEnergia = this->energia + 6;

    if (nuevaEnergia > MAX_ENERGIA)
        this->energia = MAX_ENERGIA;
    else
        this->energia = nuevaEnergia;
}

Vampirella::~Vampirella()
{
}
