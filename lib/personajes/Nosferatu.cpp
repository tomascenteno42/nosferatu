#include "../../src/main.h"

int Nosferatu::contador = 0;

Nosferatu::Nosferatu(int fila, int columna) : Vampiro(S_NOSFERATU, C_NOSFERATU, ID_NOSFERATU, fila, columna)
{
}

void Nosferatu::atacar(Juego *juego)
{
    int filaEnemigo, columnaEnemigo;
    bool puedeAtacar = false;

    if (this->getEnergia() < 6)
    {
        cout << "No podes hacer eso, te falta energia ლ(ಠ_ಠლ)" << endl;
    }
    else
        cout << "Indique a que posicion quiere atacar" << endl;
    cout << "A su alrededor hay: " << endl;
    for (int i = (this->fila - 2); i <= (this->fila + 2); i++)
    {
        for (int j = (this->columna - 2); j <= (this->columna + 2); j++)
        {

            Objeto *objeto_encontrado = juego->tablero->getElementoEnPosicion(Posicion(i, j));
            if (objeto_encontrado)
            {
                if (objeto_encontrado->getCaracter() == C_HUMANO && (objeto_encontrado != this))
                {
                    objeto_encontrado->mostrarInformacion();
                    puedeAtacar = true;
                    cout << "en la posicion: " << objeto_encontrado->getFila() << "," << objeto_encontrado->getColumna()
                         << "\n"
                         << endl;
                }
            }
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
        int danio, escudo, vida, energia, fuerza;
        vida = enemigo->getVida();
        if (vida > 30)
        {
            escudo = enemigo->getEscudo();
            danio = (this->getFuerza());
            ajustarDanio(danio, escudo);
            enemigo->setVida(enemigo->getVida() - danio);
            this->setEnergia((this->getEnergia() - 6));
            cout << "Atacado! (☞ ﾟヮﾟ)☞" << endl;
            cout << "Tu enemigo tenia un escudo de " << enemigo->getEscudo() << " entonces tu daño fue de " << danio
                 << endl;
        }
        else
        {
            vida = enemigo->getVida();
            escudo = enemigo->getEscudo();
            energia = enemigo->getEnergia();
            fuerza = enemigo->getFuerza();
            int id = enemigo->getId();
            juego->tablero->darDeBaja(Posicion(filaEnemigo, columnaEnemigo));
            Objeto *vampiro_nuevo = new Vampiro(id, filaEnemigo, columnaEnemigo);
            juego->tablero->darDeAlta(Posicion(filaEnemigo, columnaEnemigo), vampiro_nuevo);
            Ser *vampiro = dynamic_cast<Ser *>(vampiro_nuevo);
            vampiro->setVida(vida);
            vampiro->setEscudo(escudo);
            vampiro->setEnergia(energia);
            vampiro->setFuerza(fuerza);
            this->setEnergia((this->getEnergia()) - 6);
        }
        objeto = juego->tablero->getElementoEnPosicion(Posicion(filaEnemigo, columnaEnemigo));
        enemigo = dynamic_cast<Ser *>(objeto);
        enemigo->mostrarInformacion();
    }
}

void Nosferatu::actualizar()
{
    int nuevaEnergia = this->energia + 10;

    if (nuevaEnergia > MAX_ENERGIA)
        this->energia = MAX_ENERGIA;
    else
        this->energia = nuevaEnergia;
}

void Nosferatu::defender(Juego *juego) {
}

Nosferatu::~Nosferatu()
{
    Nosferatu::contador--;
}
