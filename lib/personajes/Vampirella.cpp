#include "../../src/main.h"

Vampirella::Vampirella(int fila, int columna) : Vampiro(S_VAMPIRELLA, C_VAMPIRELLA, ID_VAMPIRELLA, fila, columna)
{
}

void Vampirella::atacar(Juego *juego)
{
    int filaEnemigo, columnaEnemigo;
    bool puedeAtacar = false;

    Posicion arriba((this->getFila() - 1), this->getColumna());
    Objeto *objetoEncontrado;
    if (this->getEnergia() < 4)
        cout << "No podes hacer eso, te falta energia ლ(ಠ_ಠლ)" << endl;
    else
    {
        cout << "Indique a que posicion quiere atacar" << endl;
        cout << "A su alrededor hay: " << endl;
        if (juego->tablero->getMapa()->coordenadaValida(arriba))
        {
            objetoEncontrado = juego->tablero->getElementoEnPosicion(arriba);
            if (objetoEncontrado)
            {
                char caracter = objetoEncontrado->getCaracter();
                if (caracter == C_HUMANO || caracter == C_HUMANO_CV || caracter == C_VANESA)
                {
                    objetoEncontrado->mostrarInformacion();
                    puedeAtacar = true;
                    cout << "en la posicion: " << objetoEncontrado->getFila() << "," << objetoEncontrado->getColumna()
                         << "\n"
                         << endl;
                }
            }
        }
        Posicion abajo((this->getFila() + 1), this->getColumna());
        if (juego->tablero->getMapa()->coordenadaValida(abajo))
        {

            objetoEncontrado = juego->tablero->getElementoEnPosicion(abajo);
            if (objetoEncontrado)
            {
                char caracter = objetoEncontrado->getCaracter();
                if (caracter == C_HUMANO || caracter == C_HUMANO_CV || caracter == C_VANESA)
                {
                    objetoEncontrado->mostrarInformacion();
                    puedeAtacar = true;
                    cout << "en la posicion: " << objetoEncontrado->getFila() << "," << objetoEncontrado->getColumna()
                         << "\n"
                         << endl;
                }
            }
        }
        Posicion izquierda(this->getFila(), (this->getColumna() - 1));
        if (juego->tablero->getMapa()->coordenadaValida(izquierda))
        {

            objetoEncontrado = juego->tablero->getElementoEnPosicion(izquierda);
            if (objetoEncontrado)
            {
                char caracter = objetoEncontrado->getCaracter();
                if (caracter == C_HUMANO || caracter == C_HUMANO_CV || caracter == C_VANESA)
                {
                    objetoEncontrado->mostrarInformacion();
                    puedeAtacar = true;
                    cout << "en la posicion: " << objetoEncontrado->getFila() << "," << objetoEncontrado->getColumna()
                         << "\n"
                         << endl;
                }
            }
        }
        Posicion derecha(this->getFila(), (this->getColumna() + 1));
        if (juego->tablero->getMapa()->coordenadaValida(derecha))
        {

            objetoEncontrado = juego->tablero->getElementoEnPosicion(derecha);
            if (objetoEncontrado)
            {
                char caracter = objetoEncontrado->getCaracter();
                if (caracter == C_HUMANO || caracter == C_HUMANO_CV || caracter == C_VANESA)
                {
                    objetoEncontrado->mostrarInformacion();
                    puedeAtacar = true;
                    cout << "en la posicion: " << objetoEncontrado->getFila() << "," << objetoEncontrado->getColumna()
                         << "\n"
                         << endl;
                }
            }
        }

        if (!puedeAtacar)
            cout << "No tenes enemigos cerca para atacarlos" << endl;
        else
        {
            juego->pedirPosicion(filaEnemigo, columnaEnemigo);
            Objeto *objeto = juego->tablero->getElementoEnPosicion(Posicion(filaEnemigo, columnaEnemigo));
            Ser *enemigo = dynamic_cast<Ser *>(objeto);
            int danio, escudo;
            escudo = enemigo->getEscudo();
            danio = (this->getFuerza());
            ajustarDanio(danio, escudo);
            enemigo->setVida(enemigo->getVida() - danio);
            if (enemigo->estaMuerto())
            {
                cout << "Eliminaste a tu enemigo " << endl;
                juego->tablero->matarPersonaje(Posicion(filaEnemigo, columnaEnemigo));
            }
            else
            {
                cout << "Atacado! (☞ ﾟヮﾟ)☞" << endl;
                cout << "Tu enemigo tenia un escudo de " << enemigo->getEscudo() << " entonces tu daño fue de " << danio << endl;
            }
            this->setEnergia((this->getEnergia()) - 4);
            if (escudo > 0)
                enemigo->setEscudo(escudo - 1);
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

    if (this->contadorTurnos == 1)
    {
        this->seDefendio = false;
        this->contadorTurnos = 0;
    }

    if (this->seDefendio)
        contadorTurnos = 1;
}

void Vampirella::defender(Juego *juego)
{
    if (puedeDefenderse())
    {
        this->seDefendio = true;
        this->energia -= 5;
    }
    else
    {
        cout << "O no se cumplen las condiciones para ejecutar la defensa o no tiene suficiente energia" << endl;
        Sleep(2000)
    }
}

bool Vampirella::puedeDefenderse()
{
    return this->energia >= 5;
}

bool Vampirella::puedeAtacar()
{
    return this->energia >= 4;
}

Vampirella::~Vampirella()
{
}
