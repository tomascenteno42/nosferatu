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
                    int id = objetoEncontrado->getId();
                    if (id >= ID_VANESA && id < ID_ZOMBIE && (objetoEncontrado != this))
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
            cout << "Ingrese la fila" << endl;
            cin >> filaEnemigo;
            cout << "Ingrese la columna" << endl;
            cin >> columnaEnemigo;
            Objeto *objeto = juego->tablero->getElementoEnPosicion(Posicion(filaEnemigo, columnaEnemigo));
            Ser *enemigo = dynamic_cast<Ser *>(objeto);
            int danio, escudo, vida, energia, fuerza, id;
            //REVISAR INVENTARIO, GUARDAR AGUA BENDITA
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
                    juego->tablero->matarPersonaje(Posicion(filaEnemigo, columnaEnemigo));
                    cout << "El enemigo ha muerto." << endl;
                }
            }
            else
            {
                vida = enemigo->getVida();
                escudo = enemigo->getEscudo();
                energia = enemigo->getEnergia();
                fuerza = enemigo->getFuerza();
                id = enemigo->getId();
                juego->tablero->matarPersonaje(Posicion(filaEnemigo, columnaEnemigo));
                Objeto *vampiro_nuevo = new Vampiro(id, filaEnemigo, columnaEnemigo);
                juego->tablero->darDeAlta(Posicion(filaEnemigo, columnaEnemigo), vampiro_nuevo);
                Ser *vampiro = dynamic_cast<Ser *>(vampiro_nuevo);
                vampiro->setVida(vida);
                vampiro->setEscudo(escudo);
                vampiro->setEnergia(energia);
                vampiro->setFuerza(fuerza);
                //AGREGAR AGUA BENDITA AL INVENTARIO
            }
            this->setEnergia((this->getEnergia()) - 6);
            objeto = juego->tablero->getElementoEnPosicion(Posicion(filaEnemigo, columnaEnemigo));
            enemigo = dynamic_cast<Ser *>(objeto);
            enemigo->mostrarInformacion();
        }
    }
}
/*
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
}*/

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

bool Nosferatu::defender(Juego *juego)
{
    vector<Posicion> posiciones;
    Objeto *objetoEncontrado;
    bool puedeCambiar = false;
    bool puedeDefender = false;

    if (this->energia >= 10)
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
    return puedeDefender;
}

Nosferatu::~Nosferatu()
{
}
