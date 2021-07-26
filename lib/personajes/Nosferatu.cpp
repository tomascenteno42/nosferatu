#include "../../src/main.h"

int Nosferatu::contador = 0;

Nosferatu::Nosferatu(int fila, int columna) : Vampiro(S_NOSFERATU, C_NOSFERATU, ID_NOSFERATU, fila ,columna)
{
    Nosferatu::contador++;
}

int Nosferatu::obtener_existentes()
{
    return Nosferatu::contador;
}

void Nosferatu::atacar(Tablero *tablero) {
    int fila_enemigo, columna_enemigo;
    bool puedeAtacar = false;
    if (this->getEnergia() < 6) {
        cout << "No podes hacer eso, te falta energia ლ(ಠ_ಠლ)" << endl;
    }
    if (this->getEnergia() >= 6)
        cout << "Indique a que posicion quiere atacar" << endl;
    cout << "A su alrededor hay: " << endl;
    for (int i = (this->fila - 2); i <= (this->fila + 2); i++) {
        for (int j = (this->columna - 2); j <= (this->columna + 2); j++) {

            Objeto *objeto_encontrado = tablero->getElementoEnPosicion(Posicion(i, j));
            if (objeto_encontrado) {
                if (objeto_encontrado->getCaracter() == C_HUMANO && (objeto_encontrado != this)) {
                    objeto_encontrado->mostrarInformacion();
                    puedeAtacar = true;
                    cout << "en la posicion: " << objeto_encontrado->getFila() << "," << objeto_encontrado->getColumna()
                         << "\n" << endl;
                }
            }
        }
    }
    if (!puedeAtacar)
        cout << "No tenes enemigos cerca para atacarlos" << endl;
    else if (puedeAtacar) {
        cout << "Ingrese la fila" << endl;
        cin >> fila_enemigo;
        cout << "Ingrese la columna" << endl;
        cin >> columna_enemigo;
        Objeto *objeto = tablero->getElementoEnPosicion(Posicion(fila_enemigo, columna_enemigo));
        Ser *enemigo = dynamic_cast<Ser *>(objeto);
        int danio, escudo, vida, energia, fuerza;
        vida = enemigo->getVida();
        if (vida > 30) {
            escudo = enemigo->getEscudo();
            danio = (this->getFuerza());
            ajustarDanio(danio, escudo);
            enemigo->setVida(enemigo->getVida() - danio);
            this->setEnergia((this->getEnergia() - 6));
            cout << "Atacado! (☞ ﾟヮﾟ)☞" << endl;
            cout << "Tu enemigo tenia un escudo de " << enemigo->getEscudo() << " entonces tu daño fue de " << danio
                 << endl;
        } else {
            vida = enemigo->getVida();
            escudo = enemigo->getEscudo();
            energia = enemigo->getEnergia();
            fuerza = enemigo->getFuerza();
            int id = enemigo->getId();
            tablero->darDeBaja(Posicion(fila_enemigo, columna_enemigo));
            Objeto *vampiro_nuevo = new Vampiro(id, fila_enemigo, columna_enemigo);
            tablero->darDeAlta(Posicion(fila_enemigo, columna_enemigo), vampiro_nuevo);
            Ser *vampiro = dynamic_cast<Ser *>(vampiro_nuevo);
            vampiro->setVida(vida);
            vampiro->setEscudo(escudo);
            vampiro->setEnergia(energia);
            vampiro->setFuerza(fuerza);
            this->setEnergia((this->getEnergia())-6);
        }
        objeto = tablero->getElementoEnPosicion(Posicion(fila_enemigo, columna_enemigo));
        enemigo = dynamic_cast<Ser *>(objeto);
        enemigo->mostrarInformacion();
    }
}


void Nosferatu::actualizar() {
    this->energia += 10;
}

Nosferatu::~Nosferatu()
{
    Nosferatu::contador--;
}
