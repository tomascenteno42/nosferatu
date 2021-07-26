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

void Vampirella::atacar(Tablero *tablero){
    if (this->getEnergia() < 4)
    {
        cout << "No podes hacer eso, te falta energia ლ(ಠ_ಠლ)" << endl;
    }
    if (this->getEnergia() >= 4) {
        int filaEnemigo, columnaEnemigo;
        bool puedeAtacar = false;
        cout << "Indique a que posicion quiere atacar" << endl;
        cout << "A su alrededor hay: " << endl;
        Posicion arriba((this->getFila() - 1), this->getColumna());
        Objeto *objeto_encontrado = tablero->getElementoEnPosicion(arriba);
        if (objeto_encontrado) {
            if (objeto_encontrado->getCaracter() == C_HUMANO) {
                objeto_encontrado->mostrarInformacion();
                puedeAtacar = true;
                cout << "en la posicion: " << objeto_encontrado->getFila() << "," << objeto_encontrado->getColumna()
                     << "\n" << endl;
            }
        }

        Posicion abajo((this->getFila() + 1), this->getColumna());
        objeto_encontrado = tablero->getElementoEnPosicion(abajo);
        if (objeto_encontrado) {
            if (objeto_encontrado->getCaracter() == C_HUMANO) {
                objeto_encontrado->mostrarInformacion();
                puedeAtacar = true;
                cout << "en la posicion: " << objeto_encontrado->getFila() << "," << objeto_encontrado->getColumna()
                     << "\n" << endl;
            }
        }

        Posicion izquierda(this->getFila(), (this->getColumna() - 1));
        objeto_encontrado = tablero->getElementoEnPosicion(izquierda);
        if (objeto_encontrado) {
            if (objeto_encontrado->getCaracter() == C_HUMANO) {
                objeto_encontrado->mostrarInformacion();
                puedeAtacar = true;
                cout << "en la posicion: " << objeto_encontrado->getFila() << "," << objeto_encontrado->getColumna()
                     << "\n" << endl;
            }
        }

        Posicion derecha(this->getFila(), (this->getColumna() + 1));
        objeto_encontrado = tablero->getElementoEnPosicion(derecha);
        if (objeto_encontrado) {
            if (objeto_encontrado->getCaracter() == C_HUMANO) {
                objeto_encontrado->mostrarInformacion();
                puedeAtacar = true;
                cout << "en la posicion: " << objeto_encontrado->getFila() << "," << objeto_encontrado->getColumna()
                     << "\n" << endl;
            }
        }
        if(!puedeAtacar)
            cout << "No tenes enemigos cerca para atacarlos" << endl;
        else if(puedeAtacar){
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
            if(escudo != 0)
                enemigo->setEscudo((enemigo->getEscudo())-1);
            this->setEnergia((this->getEnergia())-4);
            cout << "Atacado! (☞ ﾟヮﾟ)☞" << endl;
            cout << "Tu enemigo tenia un escudo de " << enemigo->getEscudo() << " entonces tu daño fue de " << danio << endl;
            objeto = tablero->getElementoEnPosicion(Posicion(filaEnemigo, columnaEnemigo));
            enemigo = dynamic_cast<Ser *>(objeto);
            enemigo->mostrarInformacion();
        }
    }
}
}

void Vampirella::actualizar() {
    this->energia += 6;
}

Vampirella::~Vampirella()
{
    Vampirella::contador--;
}
