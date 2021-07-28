
#include "../../src/main.h"

Vampiro::Vampiro(int id, int fila, int columna) : Monstruo(S_VAMPIRO, C_VAMPIRO, id, fila, columna)
{
}

Vampiro::Vampiro(string nombre, char caracter, int id, int fila, int columna) : Monstruo(nombre, caracter, id, fila, columna)
{
}

void Vampiro::atacar(Juego *juego)
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
        Objeto *objeto_encontrado = juego->tablero->getElementoEnPosicion(arriba);
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
        objeto_encontrado = juego->tablero->getElementoEnPosicion(abajo);
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
        objeto_encontrado = juego->tablero->getElementoEnPosicion(izquierda);
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
        objeto_encontrado = juego->tablero->getElementoEnPosicion(derecha);
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
            Objeto *objeto = juego->tablero->getElementoEnPosicion(Posicion(filaEnemigo, columnaEnemigo));
            Ser *enemigo = dynamic_cast<Ser *>(objeto);
            int danio, escudo;
            escudo = enemigo->getEscudo();
            danio = (this->getFuerza());
            ajustarDanio(danio, escudo);
            enemigo->setVida(enemigo->getVida() - danio);
            this->setEnergia((this->getEnergia()) - 2);
            cout << "Atacado! (☞ ﾟヮﾟ)☞" << endl;
            cout << "Tu enemigo tenia un escudo de " << enemigo->getEscudo() << " entonces tu daño fue de " << danio << endl;
            objeto = juego->tablero->getElementoEnPosicion(Posicion(filaEnemigo, columnaEnemigo));
            enemigo = dynamic_cast<Ser *>(objeto);
            enemigo->mostrarInformacion();
        }
    }
}

void Vampiro::actualizar()
{
    int nuevaEnergia = this->energia + 4;

    if (nuevaEnergia > MAX_ENERGIA)
        this->energia = MAX_ENERGIA;
    else
        this->energia = nuevaEnergia;

    if(this->contadorTurnos == 1){
        this->escudo--;
        this->seDefendio = false;
        contadorTurnos = 0;
    }
    if(this->seDefendio)
        this->contadorTurnos = 1;
}

bool Vampiro::defender(Juego *juego) {
    bool puedeDefender = false;

    if(this->energia >= 4){
        puedeDefender = true;
        if(seDefendio)
            this->contadorTurnos = 0;
        else if(this->escudo < MAX_ESCUDO){
                int anterior = this->escudo;
                this->escudo++;
                this->seDefendio = true;
                cout << "Escudo:" << anterior << "--> " << this->escudo << endl;
        }
        else if(this->escudo == MAX_ESCUDO){
            cout << "Ya tenes el maximo escudo posible!!" << endl;
        }
        this->energia -= 4;
    }
    return puedeDefender;
}

Vampiro::~Vampiro()
{
}
