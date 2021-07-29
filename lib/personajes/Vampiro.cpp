
#include "../../src/main.h"

Vampiro::Vampiro(int id, int fila, int columna) : Monstruo(S_VAMPIRO, C_VAMPIRO, id, fila, columna)
{
}

Vampiro::Vampiro(string nombre, char caracter, int id, int fila, int columna) : Monstruo(nombre, caracter, id, fila, columna)
{
}

void Vampiro::atacar(Juego *juego)
{
    int filaEnemigo, columnaEnemigo;
    bool puedeAtacar = false;

    if(this->getEnergia() < 2)
        cout << "No podes hacer eso, te falta energia ლ(ಠ_ಠლ)" << endl;
    else {
        cout << "Indique a que posicion quiere atacar" << endl;
        cout << "A su alrededor hay: " << endl;
        Posicion arriba((this->getFila() - 1), this->getColumna());
        if (juego->tablero->getMapa()->coordenadaValida(arriba)) {
            puedeAtacar = buscarAlrededor(juego, arriba, puedeAtacar);
        }
        Posicion abajo((this->getFila() + 1), this->getColumna());
        if (juego->tablero->getMapa()->coordenadaValida(abajo)) {
            puedeAtacar = buscarAlrededor(juego, abajo, puedeAtacar);
        }
        Posicion izquierda(this->getFila(), (this->getColumna() - 1));
        if (juego->tablero->getMapa()->coordenadaValida(izquierda)) {
            puedeAtacar = buscarAlrededor(juego, izquierda, puedeAtacar);
        }
        Posicion derecha(this->getFila(), (this->getColumna() + 1));
        if (juego->tablero->getMapa()->coordenadaValida(derecha)) {
            puedeAtacar = buscarAlrededor(juego, derecha, puedeAtacar);
        }
        if (!puedeAtacar)
            cout << "No tenes enemigos cerca para atacarlos" << endl;
        else {
            juego->pedirPosicion(filaEnemigo, columnaEnemigo);

            Objeto *objeto = juego->tablero->getElementoEnPosicion(Posicion(filaEnemigo, columnaEnemigo));
            Ser *enemigo = dynamic_cast<Ser *>(objeto);
            int danio, escudo;
            escudo = enemigo->getEscudo();
            danio = (this->getFuerza());
            ajustarDanio(danio, escudo);
            enemigo->setVida(enemigo->getVida() - danio);
            if (enemigo->estaMuerto()) {
                cout << "Eliminaste a tu enemigo " << endl;
                juego->tablero->matarPersonaje(Posicion(filaEnemigo, columnaEnemigo));
            }
            else{
                cout << "Atacado! (☞ ﾟヮﾟ)☞" << endl;
                cout << "Tu enemigo tenia un escudo de " << enemigo->getEscudo() << " entonces tu daño fue de " << danio << endl;
            }
            this->setEnergia((this->getEnergia()) - 2);
        }
    }
}

bool Vampiro::buscarAlrededor(Juego *juego, Posicion posicion, bool puedeAtacar){
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
                puedeAtacar = true;
                cout << "en la posicion: " << serEncontrado->getFila() << "," << serEncontrado->getColumna()
                << "\n"
                << endl;
            }
        }
    }
    return puedeAtacar;
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
