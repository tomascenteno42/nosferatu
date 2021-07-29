#include "../../src/main.h"

Zombi::Zombi(int id, int fila, int columna) : Monstruo(S_ZOMBI, C_ZOMBI, id, fila, columna)
{
    cantidadDeAguaBenditas = 0;
}

void Zombi::agarrarObjeto()
{
    cantidadDeAguaBenditas++;
}

int Zombi::getCantidadDeAguaBenditas()
{
    return cantidadDeAguaBenditas;
}

void Zombi::atacar(Juego *juego)
{
    vector<Posicion> posicionesPosibles;
    bool puedeAtacar = false, posArriba = false, posAbajo = false, posIzq = false, posDer = false;
    if (this->getEnergia() < 5)
    {
        cout << "No podes hacer eso, te falta energia ლ(ಠ_ಠლ)" << endl;
    }
    else if (this->getEnergia() >= 5)
    {
        Posicion arriba((this->getFila() - 1), this->getColumna());
        if (juego->tablero->getMapa()->coordenadaValida(arriba))
        {
            posArriba = buscarAlrededor(juego, arriba, posArriba);
            if (posArriba)
            {
                posicionesPosibles.push_back(arriba);
                puedeAtacar = true;
            }
        }
        Posicion abajo((this->getFila() + 1), this->getColumna());
        if (juego->tablero->getMapa()->coordenadaValida(abajo))
        {
            posAbajo = buscarAlrededor(juego, abajo, posAbajo);
            if (posAbajo)
            {
                posicionesPosibles.push_back(abajo);
                puedeAtacar = true;
            }
        }
        Posicion izquierda(this->getFila(), (this->getColumna() - 1));
        if (juego->tablero->getMapa()->coordenadaValida(izquierda))
        {
            posIzq = buscarAlrededor(juego, izquierda, posIzq);
            if (posIzq)
            {
                posicionesPosibles.push_back(izquierda);
                puedeAtacar = true;
            }
        }
        Posicion derecha(this->getFila(), (this->getColumna() + 1));
        if (juego->tablero->getMapa()->coordenadaValida(derecha))
        {
            posDer = buscarAlrededor(juego, derecha, posDer);
            if (posDer)
            {
                posicionesPosibles.push_back(derecha);
                puedeAtacar = true;
            }
        }
    }
    if (!puedeAtacar)
        cout << "No tenes enemigos cerca para atacarlos" << endl;
    else
    {
        int random = rand() % ((posicionesPosibles.size()));
        Objeto *objetoElegido = juego->tablero->getElementoEnPosicion(posicionesPosibles.at(random));
        Humano *enemigo = dynamic_cast<Humano *>(objetoElegido);
        enemigo->modificarTransformacion(true);
        this->setEnergia((this->getEnergia()) - 5);
    }
}

bool Zombi::buscarAlrededor(Juego *juego, Posicion posicion, bool esCorrecto)
{
    Objeto *objetoEncontrado = juego->tablero->getElementoEnPosicion(posicion);
    Ser *serEncontrado = dynamic_cast<Ser *>(objetoEncontrado);
    if (serEncontrado)
    {
        char caracter = serEncontrado->getCaracter();
        if (caracter == C_HUMANO || caracter == C_HUMANO_CV || caracter == C_VANESA)
            if (serEncontrado->seEstaDefendiendo() && serEncontrado->getCaracter() == C_VANESA)
            {
                cout << "Vanesa se esta defendiendo, no podes atacarla esta vez ¯\\_(⊙︿⊙)_/¯\n"
                     << endl;
            }
            else
            {
                esCorrecto = true;
            }
    }
    return esCorrecto;
}

void Zombi::actualizar()
{
    int nuevaEnergia = this->energia + 5;

    if (nuevaEnergia > MAX_ENERGIA)
        this->energia = MAX_ENERGIA;
    else
        this->energia = nuevaEnergia;

    if (contadorTurnos == 1)
    {
        this->contadorTurnos = 0;
        this->seDefendio = false;
    }
    if (seDefendio)
        this->contadorTurnos = 1;
}

void Zombi::defender(Juego *juego)
{
    if (puedeDefenderse())
    {
        if (this->vida + 20 > MAX_VIDA)
            this->vida = MAX_VIDA;
        else
            this->vida += 20;

        this->seDefendio = true;
        this->energia -= 2;
    }
    else
    {
        cout << "O no se cumplen las condiciones para ejecutar la defensa o no tiene suficiente energia" << endl;
        Sleep(2000)
    }
}

bool Zombi::puedeDefenderse()
{
    return this->energia >= 2;
}

bool Zombi::puedeAtacar()
{
    return this->energia >= 5;
}

Zombi::~Zombi()
{
}
