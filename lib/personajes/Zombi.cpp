#include "../../src/main.h"

Zombi::Zombi(int id, int fila, int columna) : Monstruo(S_ZOMBI, C_ZOMBI, id, fila, columna)
{
    cantidadDeAguaBenditas = 0;
}

void Zombi::agarrarObjeto()
{
    cantidadDeAguaBenditas++;
}

void Zombi::atacar(Juego *juego)
{
    vector<Posicion > posicionesPosibles;
    bool puedeAtacar = false, posArriba = false, posAbajo = false, posIzq = false, posDer = false;
    if (this->getEnergia() < 5)
    {
        cout << "No podes hacer eso, te falta energia ლ(ಠ_ಠლ)" << endl;
    }
    else if (this->getEnergia() >= 5)
    {
        Posicion arriba((this->getFila() - 1), this->getColumna());
        if (juego->tablero->getMapa()->coordenadaValida(arriba)) {
            posArriba = buscarAlrededor(juego, arriba, posArriba);
            if(posArriba){
                posicionesPosibles.push_back(arriba);
                puedeAtacar = true;
            }
        }
        Posicion abajo((this->getFila() + 1), this->getColumna());
        if (juego->tablero->getMapa()->coordenadaValida(abajo)) {
            posAbajo = buscarAlrededor(juego, abajo, posAbajo);
            if(posAbajo){
                posicionesPosibles.push_back(abajo);
                puedeAtacar = true;
            }
        }
        Posicion izquierda(this->getFila(), (this->getColumna() - 1));
        if (juego->tablero->getMapa()->coordenadaValida(izquierda)) {
            posIzq = buscarAlrededor(juego, izquierda, posIzq);
            if(posIzq){
                posicionesPosibles.push_back(izquierda);
                puedeAtacar = true;
            }
        }
        Posicion derecha(this->getFila(), (this->getColumna() + 1));
        if (juego->tablero->getMapa()->coordenadaValida(derecha)) {
            posDer = buscarAlrededor(juego, derecha, posDer);
            if(posDer){
                posicionesPosibles.push_back(derecha);
                puedeAtacar = true;
            }
        }
    }
        /*Posicion arriba((this->getFila() - 1), this->getColumna());
        Objeto *objetoEncontrado = juego->tablero->getElementoEnPosicion(arriba);
        if (objetoEncontrado)
        {
            int id = objetoEncontrado->getId();
            if (id >= ID_VANESA && id < ID_ZOMBIE)
            {
                posicionesPosibles.push_back(arriba);
                puedeAtacar = true;
            }
        }

        Posicion abajo((this->getFila() + 1), this->getColumna());
        objetoEncontrado = juego->tablero->getElementoEnPosicion(abajo);
        if (objetoEncontrado)
        {
            int id = objetoEncontrado->getId();
            if (id >= ID_VANESA && id < ID_ZOMBIE)
            {
                posicionesPosibles.push_back(abajo);
                puedeAtacar = true;
            }
        }

        Posicion izquierda(this->getFila(), (this->getColumna() - 1));
        objetoEncontrado = juego->tablero->getElementoEnPosicion(izquierda);
        if (objetoEncontrado)
        {
            int id = objetoEncontrado->getId();
            if (id >= ID_VANESA && id < ID_ZOMBIE)
            {
                posicionesPosibles.push_back(izquierda);
                puedeAtacar = true;
            }
        }

        Posicion derecha(this->getFila(), (this->getColumna() + 1));
        objetoEncontrado = juego->tablero->getElementoEnPosicion(derecha);
        if (objetoEncontrado)
        {
            int id = objetoEncontrado->getId();
            if (id >= ID_VANESA && id < ID_ZOMBIE)
            {
                posicionesPosibles.push_back(derecha);
                puedeAtacar = true;
            }
        }*/
        if (!puedeAtacar)
            cout << "No tenes enemigos cerca para atacarlos" << endl;
        else
        {
            int random = rand()%((posicionesPosibles.size()));
            Objeto* objetoElegido = juego->tablero->getElementoEnPosicion(posicionesPosibles.at(random));
            Humano *enemigo = dynamic_cast<Humano *>(objetoElegido);
            enemigo->modificarTransformacion(true);
            this->setEnergia((this->getEnergia()) - 5);
        }
}


bool Zombi::buscarAlrededor(Juego *juego, Posicion posicion, bool esCorrecto){
        Objeto *objetoEncontrado = juego->tablero->getElementoEnPosicion(posicion);;
        Ser *serEncontrado = dynamic_cast<Ser *>(objetoEncontrado);
        if (serEncontrado) {
            int id = serEncontrado->getId();
            if (id >= ID_VANESA && id < ID_ZOMBIE) {
                if(serEncontrado->seEstaDefendiendo() && serEncontrado->getCaracter() == C_VANESA){
                    cout << "Vanesa se esta defendiendo, no podes atacarla esta vez ¯\\_(⊙︿⊙)_/¯\n" << endl;
                }
                else{
                    serEncontrado->mostrarInformacion();
                    esCorrecto = true;
                    cout << "en la posicion: " << serEncontrado->getFila() << "," << serEncontrado->getColumna()
                    << "\n"
                    << endl;
                }
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

    if(contadorTurnos == 1){
        this->contadorTurnos = 0;
        this->seDefendio = false;
    }
    if(seDefendio)
        this->contadorTurnos = 1;
}

bool Zombi::defender(Juego *juego) {
    bool puedeDefender = false;

    if(this->energia >= 2){
        if(this->vida + 20 > MAX_VIDA)
            this->vida = MAX_VIDA;
        else
            this->vida += 20;

        this->seDefendio = true;
        this->energia -= 2;
        puedeDefender = true;
    }
    return puedeDefender;
}

Zombi::~Zombi()
{
}
