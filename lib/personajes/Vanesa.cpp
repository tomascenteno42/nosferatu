#include "../../src/main.h"

int Vanesa::contador = 0;

Vanesa::Vanesa(int fila, int columna) : Humano_cazador(S_VANESA, C_VANESA, ID_VANESA, fila, columna)
{
    Vanesa::contador++;
}

int Vanesa::getContador()
{
    return Vanesa::contador;
}

void Vanesa::atacar(Juego *juego)
{
    size_t i = 0;
    int idxAgua = -1;

    if (this->getEnergia() < 8)
        cout << "No podes hacer eso, te falta energia ლ(ಠ_ಠლ)" << endl;
    while (i < inventario.size() && this->getEnergia() >= 8)
    {
        if (inventario.at(i)->getCaracter() == C_ESCOPETA)
            contieneEscopeta = true;
        else if (inventario.at(i)->getCaracter() == C_BALAS && inventario.at(i)->getCantidad() > 2)
            contieneBalas = true;
        else if (inventario.at(i)->getCaracter() == C_AGUA_BENDITA)
        {
            idxAgua = i;
            contieneAguas = true;
        }
        else if (inventario.at(i)->getCaracter() == C_ESTACA)
            contieneEstaca = true;
        i++;
    }
    if (!contieneBalas && contieneEscopeta && !contieneAguas && !contieneEstaca && this->getEnergia() >= 8)
        cout << "No podes hacer eso, te faltan balas ლ(ಠ_ಠლ)" << endl;
    else if ((!contieneEscopeta ||
              contieneEscopeta) &&
             !contieneAguas && !contieneBalas && !contieneEstaca && this->getEnergia() >= 6)
        cout << "No tenes nada en tu inventario que te sirva ¯\\(°_o)/¯" << endl;
    else if ((contieneEscopeta && contieneBalas) || contieneAguas || contieneEstaca && this->getEnergia() >= 8)
    {
        vector<string> opcionesValidas;
        string entrada;
        int opcion;
        int i = 0;
        bool esValida = false;
        cout << left << "Indique que quiere utilizar para atacar" << endl;

        if (contieneBalas)
        {
            cout << S_ESCOPETA << endl;
            opcionesValidas.push_back(S_ESCOPETA);
        }
        if (contieneAguas)
        {
            cout << S_AGUA_BENDITA << " ";
            cout << inventario.at(idxAgua)->getCantidad() << endl;
            opcionesValidas.push_back(S_AGUA_BENDITA);
        }
        if (contieneEstaca)
        {
            cout << S_ESTACA << endl;
            opcionesValidas.push_back(S_ESTACA);
        }

        do
        {
            cout << "Elija una opcion: " << endl;

            cin.clear();
            cin >> entrada;

            while (i < opcionesValidas.size() && !esValida)
            {
                if (entrada == opcionesValidas.at(i))
                    esValida = true;
                i++;
            }
            if (!esValida)
            {

                cout << "Opcion invalida!" << endl
                     << endl;
            }

            i = 0;
        } while (!esValida);

        if (entrada == S_ESCOPETA)
            atacarEscopeta(juego);
        else if (entrada == S_AGUA_BENDITA)
            atacarAgua(juego, idxAgua);
        else
            atacarEstaca(juego);
    }
}

void Vanesa::atacarEscopeta(Juego *juego)
{
    int filaEnemigo, columnaEnemigo;
    bool puedeAtacar = false;
    cout << "Indique a que posicion quiere atacar" << endl;
    cout << "A su alrededor hay: " << endl;
    for (int i = (this->fila - 2); i <= (this->fila + 2); i++)
    {
        for (int j = (this->columna - 2); j <= (this->columna + 2); j++)
        {
            Objeto *objetoEncontrado = juego->tablero->getElementoEnPosicion(Posicion(i, j));
            if (objetoEncontrado)
            {
                if (objetoEncontrado->getCaracter() == C_ZOMBI || objetoEncontrado->getCaracter() == C_VAMPIRO && (objetoEncontrado != this))
                {
                    objetoEncontrado->mostrarInformacion();
                    puedeAtacar = true;
                    cout << "en la posicion: " << objetoEncontrado->getFila() << "," << objetoEncontrado->getColumna()
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
        int danio, escudo;
        escudo = enemigo->getEscudo();
        if (enemigo->getCaracter() == C_ZOMBI)
        {
            danio = ((this->getFuerza()) * 1.25);
            ajustarDanio(danio, escudo);
            enemigo->setVida(enemigo->getVida() - danio);
        }
        else if (enemigo->getCaracter() == C_VAMPIRO)
        {
            danio = (((this->getFuerza()) * 0.40));
            ajustarDanio(danio, escudo);
            enemigo->setVida(enemigo->getVida() - danio);
        }
        this->setEnergia((this->getEnergia()) - 8);
        /*i = 0;
        while (i < inventario.size()){
            if (inventario.at(i)->getCaracter() == C_BALAS){
                int balas = inventario.at(i)->getCantidad();
                balas = balas -2;
                inventario.at(i)->setBalas(balas);
            }
            i++;
        }*/
        cout << "Atacado! (☞ ﾟヮﾟ)☞" << endl;
        cout << "Tu enemigo tenia un escudo de " << enemigo->getEscudo() << " entonces tu daño fue de " << danio
             << endl;
        objeto = juego->tablero->getElementoEnPosicion(Posicion(filaEnemigo, columnaEnemigo));
        enemigo = dynamic_cast<Ser *>(objeto);
        enemigo->mostrarInformacion();
    }
}

void Vanesa::atacarAgua(Juego *juego, int idxAgua)
{
    int filaEnemigo, columnaEnemigo;
    bool puedeAtacar = false;
    cout << "Indique a que posicion quiere atacar" << endl;
    cout << "A su alrededor hay: " << endl;
    for (int i = (this->fila - 1); i <= (this->fila + 1); i++)
    {
        for (int j = (this->columna - 1); j <= (this->columna + 1); j++)
        {
            Objeto *objetoEncontrado = juego->tablero->getElementoEnPosicion(Posicion(i, j));
            if (objetoEncontrado)
            {
                int id = objetoEncontrado->getId();
                if (id >= ID_ZOMBIE && id < ID_AGUA_BENDITA)
                {
                    objetoEncontrado->mostrarInformacion();
                    puedeAtacar = true;
                    cout << "en la posicion: " << objetoEncontrado->getFila() << "," << objetoEncontrado->getColumna()
                         << "\n"
                         << endl;
                }
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
        int escudo = enemigo->getEscudo();
        int danio = 20;

        if (enemigo->getCaracter() == C_ZOMBI)
            cout << "Perdiste tu agua bendita ᕦ(ò_óˇ)ᕤ" << endl;
        else if (enemigo->getId() >= ID_ZOMBIE && enemigo->getId() < ID_AGUA_BENDITA)
        {
            ajustarDanio(danio, escudo);
            enemigo->setVida(enemigo->getVida() - danio);
            cout << "Atacado! (☞ ﾟヮﾟ)☞" << endl;
            if (enemigo->estaMuerto())
            {
                juego->tablero->matarPersonaje(Posicion(filaEnemigo, columnaEnemigo));
                cout << "El enemigo ha muerto." << endl;
            }
        }

        this->setEnergia((this->getEnergia()) - 8);

        Elemento *agua = inventario.at(idxAgua);
        agua->setCantidad(agua->getCantidad() - 1);

        cout << "Tu enemigo tenia un escudo de " << enemigo->getEscudo() << " entonces tu daño fue de " << danio
             << endl;
    }
}

void Vanesa::atacarEstaca(Juego *juego)
{
    int filaEnemigo, columnaEnemigo;
    bool puedeAtacar = false;

    cout << "Indique a que posicion quiere atacar" << endl;
    cout << "A su alrededor hay: " << endl;

    Posicion arriba((this->getFila() - 1), this->getColumna());
    Objeto *objetoEncontrado;
    if (juego->tablero->getMapa()->coordenadaValida(arriba))
    {

        objetoEncontrado = juego->tablero->getElementoEnPosicion(arriba);
        if (objetoEncontrado)
        {
            int id = objetoEncontrado->getId();
            if (id >= ID_ZOMBIE && id < ID_AGUA_BENDITA)
            {
                objetoEncontrado->mostrarInformacion();
                puedeAtacar = true;
                cout << "en la posicion: " << objetoEncontrado->getFila() << "," << objetoEncontrado->getColumna()
                     << "\n"
                     << endl;
            }
        }
    }

    if (juego->tablero->getMapa()->coordenadaValida(arriba))
    {
        Posicion abajo((this->getFila() + 1), this->getColumna());
        objetoEncontrado = juego->tablero->getElementoEnPosicion(abajo);
        if (objetoEncontrado)
        {
            int id = objetoEncontrado->getId();
            if (id >= ID_ZOMBIE && id < ID_AGUA_BENDITA)
            {
                objetoEncontrado->mostrarInformacion();
                puedeAtacar = true;
                cout << "en la posicion: " << objetoEncontrado->getFila() << "," << objetoEncontrado->getColumna()
                     << "\n"
                     << endl;
            }
        }
    }

    if (juego->tablero->getMapa()->coordenadaValida(arriba))
    {
        Posicion izquierda(this->getFila(), (this->getColumna() - 1));
        objetoEncontrado = juego->tablero->getElementoEnPosicion(izquierda);
        if (objetoEncontrado)
        {
            int id = objetoEncontrado->getId();
            if (id >= ID_ZOMBIE && id < ID_AGUA_BENDITA)
            {
                objetoEncontrado->mostrarInformacion();
                puedeAtacar = true;
                cout << "en la posicion: " << objetoEncontrado->getFila() << "," << objetoEncontrado->getColumna()
                     << "\n"
                     << endl;
            }
        }
    }

    if (juego->tablero->getMapa()->coordenadaValida(arriba))
    {
        Posicion derecha(this->getFila(), (this->getColumna() + 1));
        objetoEncontrado = juego->tablero->getElementoEnPosicion(derecha);
        if (objetoEncontrado)
        {
            int id = objetoEncontrado->getId();
            if (id >= ID_ZOMBIE && id < ID_AGUA_BENDITA)
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

        if (enemigo->getCaracter() == C_ZOMBI)
        {
            danio = ((this->getFuerza()) * 0.25);
            ajustarDanio(danio, escudo);
            enemigo->setVida(enemigo->getVida() - danio);
            cout << "Atacado! (☞ ﾟヮﾟ)☞" << endl;
            if (enemigo->estaMuerto())
            {
                cout << "Eliminaste a tu enemigo " << endl;
                juego->tablero->matarPersonaje(Posicion(filaEnemigo, columnaEnemigo));
            }
            else
            {
                cout << "Tu enemigo tenia un escudo de " << enemigo->getEscudo() << " entonces tu daño fue de " << danio
                     << endl;
            }
        }
        else if (enemigo->getId() >= ID_NOSFERATU && enemigo->getId() < ID_AGUA_BENDITA)
        {
            enemigo->setVida(0);
            juego->tablero->matarPersonaje(Posicion(filaEnemigo, columnaEnemigo));
            cout << "Atacado! (☞ ﾟヮﾟ)☞" << endl;
            cout << "Eliminaste a tu enemigo " << endl;
        }

        this->setEnergia((this->getEnergia()) - 8);
    }
}

void Vanesa::actualizar()
{
    int nuevaEnergia = this->energia + 10;

    if (nuevaEnergia > MAX_ENERGIA)
        this->energia = MAX_ENERGIA;
    else
        this->energia = nuevaEnergia;
}

Vanesa::~Vanesa()
{
    Vanesa::contador--;
}
