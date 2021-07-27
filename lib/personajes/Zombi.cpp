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
    bool humanoSup, humanoInf, humanoIzq, humanoDer;
    if (this->getEnergia() < 5)
    {
        cout << "No podes hacer eso, te falta energia ლ(ಠ_ಠლ)" << endl;
    }
    if (this->getEnergia() >= 5)
    {
        int filaEnemigo, columna_enemigo;
        Posicion arriba((this->getFila() - 1), this->getColumna());
        Objeto *objeto_encontrado = juego->tablero->getElementoEnPosicion(arriba);
        if (objeto_encontrado)
        {
            if (objeto_encontrado->getCaracter() == C_HUMANO)
            {
                humanoSup = true;
            }
        }

        Posicion abajo((this->getFila() + 1), this->getColumna());
        objeto_encontrado = juego->tablero->getElementoEnPosicion(abajo);
        if (objeto_encontrado)
        {
            if (objeto_encontrado->getCaracter() == C_HUMANO)
            {
                humanoInf = true;
            }
        }

        Posicion izquierda(this->getFila(), (this->getColumna() - 1));
        objeto_encontrado = juego->tablero->getElementoEnPosicion(izquierda);
        if (objeto_encontrado)
        {
            if (objeto_encontrado->getCaracter() == C_HUMANO)
            {
                humanoIzq = true;
            }
        }

        Posicion derecha(this->getFila(), (this->getColumna() + 1));
        objeto_encontrado = juego->tablero->getElementoEnPosicion(derecha);
        if (objeto_encontrado)
        {
            if (objeto_encontrado->getCaracter() == C_HUMANO)
            {
                humanoDer = true;
            }
        }
        bool puedeAtacar = false;
        if (!puedeAtacar)
            cout << "No tenes enemigos cerca para atacarlos" << endl;
        else
        {
            cout << "Ingrese la fila" << endl;
            cin >> filaEnemigo;
            cout << "Ingrese la columna" << endl;
            cin >> columna_enemigo;
            Objeto *objeto = juego->tablero->getElementoEnPosicion(Posicion(filaEnemigo, columna_enemigo));
            Ser *enemigo = dynamic_cast<Ser *>(objeto);

            this->setEnergia((this->getEnergia()) - 5);
        }
    }
}

void Zombi::actualizar()
{
    int nuevaEnergia = this->energia + 5;

    if (nuevaEnergia > MAX_ENERGIA)
        this->energia = MAX_ENERGIA;
    else
        this->energia = nuevaEnergia;
}

void Zombi::defender(Juego *juego) {

}

Zombi::~Zombi()
{
}
