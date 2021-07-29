#include "../../src/main.h"

bool contieneEscopeta = false;

Humano::Humano(int id, int fila, int columna) : Ser(S_HUMANO, C_HUMANO, id, fila, columna)
{
    this->contadorTransformacion = 0;
}

Humano::Humano(string nombre, char caracter, int id, int fila, int columna) : Ser(nombre, caracter, id, fila, columna)
{
}

void Humano::agarrarObjeto(Elemento *objeto)
{

    if (objeto->getCaracter() == C_ESCOPETA)
    {
        size_t i = 0;

        while (!contieneEscopeta && i < inventario.size())
        {
            if (inventario.at(i)->getCaracter() == C_ESCOPETA)
                contieneEscopeta = true;
            i++;
        }
    }

    if (!contieneEscopeta)
    {
        inventario.push_back(objeto);
    }
}

bool Humano::inventarioVacio()
{
    return ((int)inventario.size() == 0);
}

void Humano::mostrarInventario()
{

    int tamanio = (int)inventario.size();

    cout << "Inventario: " << endl;

    for (int i = 0; i < tamanio - 1; i++)
        cout << inventario.at(i)->getNombre() << "|";

    cout << inventario.at(tamanio - 1)->getNombre() << endl
    << endl;
}

void Humano::modificarTransformacion(bool estado)
{
    if (estado == false) // Detengo la transformacion
        contadorTransformacion = 0;
    transformando = estado;
}

void Humano::atacar(Juego *juego)
{
    bool contieneEscopeta = false, contieneBalas = false;
    size_t i = 0;
    int idxBalas = -1;
    if (this->getEnergia() < 5)
        cout << "No podes hacer eso, te falta energia ლ(ಠ_ಠლ)" << endl;
    while (i < inventario.size() && this->getEnergia() >= 5)
    {
        if (inventario.at(i)->getCaracter() == C_ESCOPETA)
            contieneEscopeta = true;
        else if (inventario.at(i)->getCaracter() == C_BALAS && inventario.at(i)->getCantidad() >= 2)
        {
            idxBalas = i;
            contieneBalas = true;
        }
        i++;
    }
    if (!contieneBalas && contieneEscopeta && this->getEnergia() >= 5)
        cout << "No podes hacer eso, te faltan balas ლ(ಠ_ಠლ)" << endl;
    else if (!contieneBalas && !contieneEscopeta && this->getEnergia() >= 5)
        cout << "No tenes nada en tu inventario que te sirva ¯\\(°_o)/¯" << endl;
    else if (contieneEscopeta && contieneBalas && this->getEnergia() >= 5)
    {
        atacarEscopeta(juego, idxBalas);
    }
}

void Humano::atacarEscopeta(Juego *juego, int idxBalas)
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
            danio = (this->getFuerza());
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
            danio = (((this->getFuerza()) * 0.20));
            ajustarDanio(danio, escudo);
            enemigo->setVida(enemigo->getVida() - danio);
            if (enemigo->estaMuerto())
            {
                juego->tablero->matarPersonaje(Posicion(filaEnemigo, columnaEnemigo));
                cout << "El enemigo ha muerto." << endl;
            }
        }
        this->setEnergia((this->getEnergia()) - 5);
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

bool Humano::seEstaTransformando()
{
    return transformando;
}

bool Humano::yaSeTransformo()
{
    return seTransformo;
}

void Humano::actualizar()
{
    int nuevaEnergia = this->energia + 5;

    if (nuevaEnergia > MAX_ENERGIA)
        this->energia = MAX_ENERGIA;
    else
        this->energia = nuevaEnergia;

    if (contadorTurnos == 1)
    {
        this->escudo--;
        this->seDefendio = false;
        this->contadorTurnos = 0;
    }

    if (contadorTransformacion == 2)
        this->seTransformo = true;

    if (seDefendio)
        this->contadorTurnos = 1;

    if (transformando)
        this->contadorTransformacion++;
}

bool Humano::defender(Juego *juego)
{
    int tamanio = (int)inventario.size();
    string leido;
    bool tieneAgua = false;
    int i = 0;
    Elemento *aux;

    while (!tieneAgua && i < tamanio)
    {
        leido = inventario.at(i)->getNombre();
        aux = inventario.at(i);
        if ((leido == S_AGUA_BENDITA) && (aux->getCantidad() > 0))
        {
            tieneAgua = true;
        }
        i++;
    }
    if (tieneAgua)
    {
        cout << "Tiene agua bendita en su inventario, desea usarla?" << endl;
        cout << "1 - Si" << endl;
        cout << "2 - No" << endl;
        leido = juego->solicitarOpcion();

        while (!esUnNumero(leido) || stoi(leido) < 1 || stoi(leido) > 2)
        {
            cout << "Por favor ingrese un numero valido" << endl;
            leido = juego->solicitarOpcion();
        }
        int respuesta = stoi(leido);

        if (respuesta == 2)
        {                   // Si tiene pero prefiere no usarla
            if (seDefendio) //Si ya se habia defendido, dejo el escudo como esta, pero por un turno mas
                contadorTurnos = 0;
            else if (this->escudo < MAX_ESCUDO)
            { // Solo se le aumenta el escudo si no tiene lo maximo posible
                int anterior = this->escudo;
                this->escudo++;
                this->seDefendio = true;
                cout << "Escudo:" << anterior << "--> " << this->escudo << endl;
            }
            else
            { //  Si ya no se puede agregar mas escudo
                int anterior = this->energia;
                this->energia += 3;
                cout << "Ya tenes el maximo escudo posible" << endl;
                cout << "Energia:" << anterior << "--> " << this->energia << endl;
            }
        }
        else if (respuesta == 1)
        { // Si quiere usar el agua
            int anterior = this->energia;
            this->energia = MAX_ENERGIA;
            aux->setCantidad(aux->getCantidad() - 1);
            cout << "Energia:" << anterior << "--> " << this->energia << endl;
        }
    }
    else
    { // Si no tiene agua
        if ((this->energia += 3) <= MAX_ENERGIA)
        {
            int anterior = this->energia;
            this->energia += 3;
            cout << "Energia:" << anterior << "--> " << this->energia << endl;
        }
        else
            this->energia = MAX_ENERGIA;
    }
    return true;
}

Humano::~Humano()
{
}
