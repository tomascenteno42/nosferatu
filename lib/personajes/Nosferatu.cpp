#include "../../src/main.h"

Nosferatu::Nosferatu(int fila, int columna) : Vampiro(S_NOSFERATU, C_NOSFERATU, ID_NOSFERATU, fila, columna)
{
}

void Nosferatu::atacar(Juego *juego)
{
    int filaEnemigo, columnaEnemigo;
    bool puedeAtacar = false;
    if (this->getEnergia() < 6)
        cout << "No podes hacer eso, te falta energia ლ(ಠ_ಠლ)" << endl;
    else
    {
        cout << "Indique a que posicion quiere atacar" << endl;
        cout << "A su alrededor hay: " << endl;
        for (int i = (this->fila - 2); i <= (this->fila + 2); i++)
        {
            for (int j = (this->columna - 2); j <= (this->columna + 2); j++)
            {
                Objeto *objetoEncontrado = juego->tablero->getElementoEnPosicion(Posicion(i, j));
                if (objetoEncontrado)
                {
                    char caracter = objetoEncontrado->getCaracter();
                    if (caracter == C_HUMANO || caracter == C_HUMANO_CV || caracter == C_VANESA)
                    {
                        objetoEncontrado->mostrarInformacion();
                        puedeAtacar = true;
                        cout << "en la posicion: " << objetoEncontrado->getFila() << ","
                             << objetoEncontrado->getColumna()
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
            int danio, escudo;

            juego->pedirPosicion(filaEnemigo, columnaEnemigo);

            Posicion pos(filaEnemigo, columnaEnemigo);
            Humano *enemigo = (Humano *)juego->tablero->getElementoEnPosicion(Posicion(filaEnemigo, columnaEnemigo));

            if (enemigo->getVida() > 30)
            {
                escudo = enemigo->getEscudo();
                danio = this->getFuerza();
                ajustarDanio(danio, escudo);
                enemigo->setVida(enemigo->getVida() - danio);
                cout << "Atacado! (☞ ﾟヮﾟ)☞" << endl;
                cout << "Tu enemigo tenia un escudo de " << enemigo->getEscudo() << " entonces tu daño fue de " << danio
                     << endl;
                if (enemigo->estaMuerto())
                {
                    juego->tablero->matarPersonaje(pos);
                    cout << "El enemigo ha muerto." << endl;
                }
            }
            else
            {
                int idEnemigo = enemigo->getId();
                Vampiro *vampiro = new Vampiro(idEnemigo, filaEnemigo, columnaEnemigo);

                juego->tablero->aplicarTransformacion(idEnemigo, vampiro, pos, false);
            }
            this->setEnergia((this->getEnergia()) - 6);
        }
    }
}

bool Nosferatu::posicionValida(vector<Posicion> posiciones, int fila, int columna)
{
    bool valida = false;
    int i = 0;

    while (!valida && i < posiciones.size())
    {
        if (posiciones.at(i).getFila() == fila && posiciones.at(i).getColumna() == columna)
            valida = true;
        i++;
    }
    return valida;
}

void Nosferatu::actualizar()
{
    int nuevaEnergia = this->energia + 10;

    if (nuevaEnergia > MAX_ENERGIA)
        this->energia = MAX_ENERGIA;
    else
        this->energia = nuevaEnergia;
}

void Nosferatu::defender(Juego *juego)
{
    vector<Posicion> posiciones;
    Objeto *objetoEncontrado;
    bool puedeCambiar = false;
    bool puedeDefender = false;

    if (puedeDefenderse())
    {
        for (int i = (this->fila - 2); i <= (this->fila + 2); i++)
        {
            for (int j = (this->columna - 2); j <= (this->columna + 2); j++)
            {
                objetoEncontrado = juego->tablero->getElementoEnPosicion(Posicion(i, j));

                if (objetoEncontrado)
                {
                    string nombre = objetoEncontrado->getNombre();
                    if (nombre == S_VAMPIRO)
                    {
                        objetoEncontrado->mostrarInformacion();
                        puedeCambiar = true;
                        posiciones.push_back(Posicion(i, j));
                        cout << "en la posicion: " << objetoEncontrado->getFila() << "," << objetoEncontrado->getColumna()
                             << endl
                             << endl;
                    }
                }
            }
        }
        if (!puedeCambiar)
            cout << "No hay vampiros para cambiar vida a tu alrededor" << endl;
        else
        {
            puedeDefender = true;
            int filaVampiro, columnaVampiro;
            juego->pedirPosicion(filaVampiro, columnaVampiro);
            while (!this->posicionValida(posiciones, filaVampiro, columnaVampiro))
            {
                cout << "Ingrese una posicion valida" << endl;
                juego->pedirPosicion(filaVampiro, columnaVampiro);
            }
            objetoEncontrado = juego->tablero->getElementoEnPosicion(Posicion(filaVampiro, columnaVampiro));
            int aux;
            Vampiro *vampiro;
            vampiro = dynamic_cast<Vampiro *>(objetoEncontrado);

            aux = vampiro->getVida();
            vampiro->setVida(this->vida);
            this->vida = aux;

            cout << "Vida: " << vampiro->getVida() << "-->" << this->vida << endl;
            Sleep(750)
        }
    }
    else
    {
        cout << "O no se cumplen las condiciones para ejecutar la defensa o no tiene suficiente energia" << endl;
        Sleep(2000)
    }
}

bool Nosferatu::puedeDefenderse()
{
    return this->energia >= 10;
}

bool Nosferatu::puedeAtacar()
{
    return this->energia >= 6;
}

Nosferatu::~Nosferatu()
{
}
