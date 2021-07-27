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

    if(contadorTurnos == 1){
        this->seDefendio = false;
        this->contadorTurnos = 0;
    }
    if(seDefendio)
        contadorTurnos = 1;
}

bool Vanesa::posicionValida(vector <Posicion> posiciones, int fila, int columna) {
    bool valida = false;
    int i = 0;

    while(!valida && i < posiciones.size()){
        if(posiciones.at(i).getFila() == fila && posiciones.at(i).getColumna() == columna)
            valida = true;
        i++;
    }
    return valida;
}

void Vanesa::defenderConAgua(Juego *juego) {
    Objeto *objetoEncontrado;
    bool puedeCurar = false;
    vector<Posicion> posiciones;

    for (int i = (this->fila - 2); i <= (this->fila + 2); i++){
        for (int j = (this->columna - 2); j <= (this->columna + 2); j++){
            objetoEncontrado = juego->tablero->getElementoEnPosicion(Posicion(i, j));

            if (objetoEncontrado){
                string nombre = objetoEncontrado->getNombre();
                if (nombre == S_HUMANO || nombre == S_HUMANO_CV || nombre == S_VANESA){
                    Humano* humano;
                    humano = dynamic_cast<Humano*>(objetoEncontrado);

                    if(humano->seEstaTransformando()){
                        puedeCurar = true;
                        Posicion nueva(i, j);
                        posiciones.push_back(nueva);
                        humano->mostrarInformacion();
                        cout << "en la posicion: " << objetoEncontrado->getFila() << "," << objetoEncontrado->getColumna()
                             << endl
                             << endl;
                    }
                }
            }
        }
    }
    if(!puedeCurar)
        cout << "Nadie a tu alrededor esta siendo tranformado :o" << endl;

    else{
        int filaAliado, columnaAliado;
        juego->pedirPosicion(filaAliado, columnaAliado);

        while(!posicionValida(posiciones, filaAliado, columnaAliado)){
            cout << "Ingrese una posicion valida" << endl;
            juego->pedirPosicion(filaAliado, columnaAliado);
        }
        Objeto* objeto = juego->tablero->getElementoEnPosicion(Posicion(filaAliado, columnaAliado));
        Humano* humano;
        humano = dynamic_cast<Humano*>(objeto);

        humano->modificarTransformacion(false);
    }

}

void Vanesa::defender(Juego *juego)
{
    if(this->energia >= 10){
        bool tieneAgua = false;
        bool tieneCruz = false;
        int tamanio = (int)inventario.size();
        Elemento* agua;
        string nombre;

        for(int i = 0; i < tamanio; i++){
            nombre = inventario.at(i)->getNombre();
            if(nombre == S_AGUA_BENDITA) {
                tieneAgua = true;
                agua = inventario.at(i);
            }
            else if(nombre == S_CRUZ)
                tieneCruz = true;
        }
        if(!tieneAgua && !tieneCruz) {
            if(this->vida + 10 > MAX_VIDA)
                this->vida = MAX_VIDA;
            else
                this->vida += 10;
        }
        else if (!tieneAgua && tieneCruz)
            this->seDefendio = true;

        else if(tieneAgua && !tieneCruz){
            defenderConAgua(juego);
            agua->setCantidad(agua->getCantidad() - 1);
        }
        else if(tieneAgua && tieneCruz){
            string ingreso;
            cout << "Ingrese con que desearia defender:" << endl;
            cout << "1 - Agua bendita" << endl;
            cout << "2 - Cruz" << endl;
            ingreso = juego->solicitarOpcion();

            while (!esUnNumero(ingreso) || stoi(ingreso) > 2 || stoi(ingreso) < 1){
                cout << "Ingrese una opcion valida" << endl;
                ingreso = juego->solicitarOpcion();
            }
            int respuesta = stoi(ingreso);

            if(respuesta == 1) {
                this->defenderConAgua(juego);
                agua->setCantidad(agua->getCantidad() - 1);
            }
            else
                this->seDefendio = true;
        }
        this->energia -= 10;
    }
    else
        cout << "No tiene energia suficiente :(" << endl;
}

Vanesa::~Vanesa()
{
    Vanesa::contador--;
}
