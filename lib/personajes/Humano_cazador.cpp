#include "../../src/main.h"
#include "math.h"

Humano_cazador::Humano_cazador(int id, int fila, int columna) : Humano(S_HUMANO_CV, C_HUMANO_CV, id, fila, columna)
{
}

Humano_cazador::Humano_cazador(string nombre, char caracter, int id, int fila, int columna) : Humano(nombre, caracter, id, fila, columna)
{
}

void Humano_cazador::atacar(Juego *juego)
{
    bool contieneEscopeta = false, contieneAguas = false, contieneBalas = false, contieneEstaca = false;
    size_t i = 0;
    int idxAgua = -1;
    int idxBalas = -1;
    if (this->getEnergia() < 6)
        cout << "No podes hacer eso, te falta energia ლ(ಠ_ಠლ)" << endl;
    while (i < inventario.size() && this->getEnergia() >= 6)
    {
        if (inventario.at(i)->getCaracter() == C_ESCOPETA)
            contieneEscopeta = true;
        else if (inventario.at(i)->getCaracter() == C_BALAS && inventario.at(i)->getCantidad() >= 2){
            idxBalas = i;
            contieneBalas = true;
        }
        else if (inventario.at(i)->getCaracter() == C_AGUA_BENDITA)
        {
            idxAgua = i;
            contieneAguas = true;
        }
        else if (inventario.at(i)->getCaracter() == C_ESTACA)
            contieneEstaca = true;
        i++;
    }
    if (!contieneBalas && contieneEscopeta && !contieneAguas && !contieneEstaca && this->getEnergia() >= 6)
        cout << "No podes hacer eso, te faltan balas ლ(ಠ_ಠლ)" << endl;
    else if (!contieneAguas && !contieneBalas && !contieneEstaca && this->getEnergia() >= 6)
        cout << "No tenes nada en tu inventario que te sirva ¯\\(°_o)/¯" << endl;
    else if ((contieneEscopeta && contieneBalas) || contieneAguas || contieneEstaca && this->getEnergia() >= 6)
    {
        vector<string> opcionesValidas;
        string entrada;
        int i = 0;
        bool esValida = false;
        cout << left << "Indique que quiere utilizar para atacar:" << endl;

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
            atacarEscopeta(juego, idxBalas);
        else if (entrada == S_AGUA_BENDITA)
            atacarAgua(juego, idxAgua);
        else
            atacarEstaca(juego);
    }
}

void Humano_cazador::atacarEscopeta(Juego *juego, int idxBalas)
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
            Ser *serEncontrado = dynamic_cast<Ser *>(objetoEncontrado);
            if (serEncontrado)
            {
                int id = serEncontrado->getId();
                if (id >= ID_ZOMBIE && id < ID_AGUA_BENDITA && (serEncontrado != this))
                {
                    if ((serEncontrado->seEstaDefendiendo()) && serEncontrado->getCaracter() == C_ZOMBI){
                        cout << "Hay un zombi escondido, no podes atacarlo esta vez ¯\\_(⊙︿⊙)_/¯\n" << endl;
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
        }
    }
    if (!puedeAtacar)
        cout << "No tenes enemigos cerca para atacarlos" << endl;
    else if (puedeAtacar)
    {
        juego->pedirPosicion(filaEnemigo, columnaEnemigo);
        Objeto *objeto = juego->tablero->getElementoEnPosicion(Posicion(filaEnemigo, columnaEnemigo));
        Ser *enemigo = dynamic_cast<Ser *>(objeto);
        int danio, escudo;
        escudo = enemigo->getEscudo();
        if (enemigo->getId() >= ID_ZOMBIE && enemigo->getId() < ID_NOSFERATU)
        {
            danio = ((this->getFuerza()) * 1.05);
            ajustarDanio(danio, escudo);
            enemigo->setVida(enemigo->getVida() - danio);
            if (enemigo->estaMuerto())
            {
                juego->tablero->matarPersonaje(Posicion(filaEnemigo, columnaEnemigo));
                cout << "El enemigo ha muerto." << endl;
            }
        }
        else if (enemigo->getId() >= ID_NOSFERATU && enemigo->getId() < ID_AGUA_BENDITA)
        {
            danio = (((this->getFuerza()) * 0.30));
            ajustarDanio(danio, escudo);
            enemigo->setVida(enemigo->getVida() - danio);
            if (enemigo->estaMuerto())
            {
                juego->tablero->matarPersonaje(Posicion(filaEnemigo, columnaEnemigo));
                cout << "El enemigo ha muerto." << endl;
            }
        }
        this->setEnergia((this->getEnergia()) - 6);
        Elemento *balas = inventario.at(idxBalas);
        balas->setCantidad(balas->getCantidad() - 2);
        if(balas->getCantidad() == 0)
            inventario.erase(inventario.begin() + idxBalas);
        cout << "Atacado! (☞ ﾟヮﾟ)☞" << endl;
        cout << "Tu enemigo tenia un escudo de " << enemigo->getEscudo() << " entonces tu daño fue de " << danio
        << endl;
        objeto = juego->tablero->getElementoEnPosicion(Posicion(filaEnemigo, columnaEnemigo));
        enemigo = dynamic_cast<Ser *>(objeto);
        enemigo->mostrarInformacion();
    }
}

void Humano_cazador::atacarAgua(Juego *juego, int idxAgua)
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
            Ser *serEncontrado = dynamic_cast<Ser *>(objetoEncontrado);
            if (serEncontrado)
            {
                int id = serEncontrado->getId();
                if (id >= ID_ZOMBIE && id < ID_AGUA_BENDITA && (!serEncontrado->seEstaDefendiendo()))
                {
                    serEncontrado->mostrarInformacion();
                    puedeAtacar = true;
                    cout << "en la posicion: " << serEncontrado->getFila() << "," << serEncontrado->getColumna()
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
        int danio = 10;

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

        this->setEnergia((this->getEnergia()) - 6);

        Elemento *agua = inventario.at(idxAgua);
        agua->setCantidad(agua->getCantidad() - 1);
        if(agua->getCantidad() == 0)
            inventario.erase(inventario.begin() + idxAgua);
        cout << "Tu enemigo tenia un escudo de " << enemigo->getEscudo() << " entonces tu daño fue de " << danio
        << endl;
    }
}

void Humano_cazador::atacarEstaca(Juego *juego)
{
    int filaEnemigo, columnaEnemigo;
    bool puedeAtacar = false;

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
    /*Posicion arriba((this->getFila() - 1), this->getColumna());
    Objeto *objetoEncontrado;
    if (juego->tablero->getMapa()->coordenadaValida(arriba))
    {

        objetoEncontrado = juego->tablero->getElementoEnPosicion(arriba);
        Ser *serEncontrado = dynamic_cast<Ser *>(objetoEncontrado);
        if (serEncontrado)
        {
            int id = serEncontrado->getId();
            if (id >= ID_ZOMBIE && id < ID_AGUA_BENDITA && (!serEncontrado->seEstaDefendiendo()))
            {
                serEncontrado->mostrarInformacion();
                puedeAtacar = true;
                cout << "en la posicion: " << serEncontrado->getFila() << "," << serEncontrado->getColumna()
                     << "\n"
                     << endl;
            }
        }
    }
    Posicion abajo((this->getFila() + 1), this->getColumna());
    if (juego->tablero->getMapa()->coordenadaValida(abajo))
    {
        objetoEncontrado = juego->tablero->getElementoEnPosicion(arriba);
        Ser *serEncontrado = dynamic_cast<Ser *>(objetoEncontrado);
        if (serEncontrado)
        {
            int id = serEncontrado->getId();
            if (id >= ID_ZOMBIE && id < ID_AGUA_BENDITA && (!serEncontrado->seEstaDefendiendo()))
            {
                serEncontrado->mostrarInformacion();
                puedeAtacar = true;
                cout << "en la posicion: " << serEncontrado->getFila() << "," << serEncontrado->getColumna()
                     << "\n"
                     << endl;
            }
        }
    }
    Posicion izquierda(this->getFila(), (this->getColumna() - 1));
    if (juego->tablero->getMapa()->coordenadaValida(izquierda))
    {
        objetoEncontrado = juego->tablero->getElementoEnPosicion(arriba);
        Ser *serEncontrado = dynamic_cast<Ser *>(objetoEncontrado);
        if (serEncontrado)
        {
            int id = serEncontrado->getId();
            if (id >= ID_ZOMBIE && id < ID_AGUA_BENDITA && (!serEncontrado->seEstaDefendiendo()))
            {
                serEncontrado->mostrarInformacion();
                puedeAtacar = true;
                cout << "en la posicion: " << serEncontrado->getFila() << "," << serEncontrado->getColumna()
                     << "\n"
                     << endl;
            }
        }
    }
    Posicion derecha(this->getFila(), (this->getColumna() + 1));
    if (juego->tablero->getMapa()->coordenadaValida(derecha))
    {
        objetoEncontrado = juego->tablero->getElementoEnPosicion(arriba);
        Ser *serEncontrado = dynamic_cast<Ser *>(objetoEncontrado);
        if (serEncontrado)
        {
            int id = serEncontrado->getId();
            if (id >= ID_ZOMBIE && id < ID_AGUA_BENDITA && (!serEncontrado->seEstaDefendiendo()))
            {
                serEncontrado->mostrarInformacion();
                puedeAtacar = true;
                cout << "en la posicion: " << serEncontrado->getFila() << "," << serEncontrado->getColumna()
                     << "\n"
                     << endl;
            }
        }
    }*/

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
            danio = ((this->getFuerza()) * 0.20);
            ajustarDanio(danio, escudo);
            enemigo->setVida(enemigo->getVida() - danio);
            cout << "Atacado! (☞ ﾟヮﾟ)☞" << endl;
            if (enemigo->estaMuerto())
            {
                cout << "Eliminaste a tu enemigo " << endl;
                juego->tablero->matarPersonaje(Posicion(filaEnemigo, columnaEnemigo));
            }
        }
        else if (enemigo->getId() >= ID_NOSFERATU && enemigo->getId() < ID_AGUA_BENDITA)
        {
            danio = 60;
            ajustarDanio(danio, escudo);
            enemigo->setVida(enemigo->getVida() - danio);
            cout << "Atacado! (☞ ﾟヮﾟ)☞" << endl;
            if (enemigo->estaMuerto())
            {
                cout << "Eliminaste a tu enemigo " << endl;
                juego->tablero->matarPersonaje(Posicion(filaEnemigo, columnaEnemigo));
            }
        }
        cout << "Tu enemigo tenia un escudo de " << enemigo->getEscudo() << " entonces tu daño fue de " << danio
        << endl;
        this->setEnergia((this->getEnergia()) - 6);
    }
}

bool Humano_cazador::buscarAlrededor(Juego *juego, Posicion posicion, bool puedeAtacar){
    Objeto *objetoEncontrado = juego->tablero->getElementoEnPosicion(posicion);;
    Ser *serEncontrado = dynamic_cast<Ser *>(objetoEncontrado);
    if (serEncontrado) {
        int id = serEncontrado->getId();
        if (id >= ID_ZOMBIE && id < ID_AGUA_BENDITA) {
            if(serEncontrado->seEstaDefendiendo() && id >= ID_VAMPIRELLA && id < ID_AGUA_BENDITA){
                cout << "Hay un personaje en modo de defensa, no podes atacarlo esta vez ¯\\_(⊙︿⊙)_/¯\n" << endl;
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

void Humano_cazador::actualizar()
{
    int nuevaEnergia = this->energia + 8;

    if (nuevaEnergia > MAX_ENERGIA)
        this->energia = MAX_ENERGIA;
    else
        this->energia = nuevaEnergia;
}

bool Humano_cazador::defender(Juego *juego){
    bool puedeDefender = false;

    if(this->energia >= 5){
        string leido;

        cout << "Ingrese la opcion deseada:" << endl;
        cout << "1 - Curarse 50 puntos de vida" << endl;
        cout << "2 - Curar a todos los aliados 20 puntos de vida" << endl;
        leido = juego->solicitarOpcion();

        while(!esUnNumero(leido) || stoi(leido) < 1 || stoi(leido) > 2){
            cout << "Ingrese un numero valido" << endl;
            leido = juego->solicitarOpcion();
        }

        int respuesta = stoi(leido);

        if(respuesta == 1){
            if((this->vida + 50) > MAX_VIDA)
                this->vida = MAX_VIDA;
            else
                this->vida += 50;
        }
        else if(respuesta == 2) {
            int personajesVivos = juego->tablero->getJugadorActual()->personajesVivos();
            vector<Ser *> personajes = juego->tablero->getJugadorActual()->getPersonajes();

            for(int i = 0; i < personajesVivos; i++){
                if((personajes.at(i)->getVida() + 20) > MAX_VIDA)
                    personajes.at(i)->setVida(MAX_VIDA);
                else{
                    int nuevaVida = personajes.at(i)->getVida() + 20;
                    personajes.at(i)->setVida(nuevaVida);
                    this->vida -= 20;
                }
            }
        }
        this->energia -= 5;
        puedeDefender = true;
    }
    return puedeDefender;
}

Humano_cazador::~Humano_cazador()
{
}
