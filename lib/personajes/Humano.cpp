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
            if (inventario.at(i)->getCaracter() == C_ESCOPETA)
                contieneEscopeta = true;
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

void Humano::modificarTransformacion(bool estado) {
    if(estado == false) // Detengo la transformacion
        contadorTransformacion = 0;
    transformando = estado;
}

void Humano::atacar(Juego *juego)
{
    int filaEnemigo, columnaEnemigo, posBalas;
    size_t i = 0;
    bool puedeAtacar = false;

    if (this->getEnergia() < 5)
    {
        cout << "No podes hacer eso, te falta energia ლ(ಠ_ಠლ)" << endl;
    }
    while (i < inventario.size() && this->getEnergia() >= 5)
    {
        if (inventario.at(i)->getCaracter() == C_ESCOPETA)
            contieneEscopeta = true;
        else if (inventario.at(i)->getCaracter() == C_BALAS && inventario.at(i)->getCantidad() >= 2)
        {
            contieneBalas = true;
            posBalas = i;
        }
        i++;
    }
    if (!contieneBalas && contieneEscopeta && this->getEnergia() >= 5)
        cout << "No podes hacer eso, te faltan balas ლ(ಠ_ಠლ)" << endl;

    else if (contieneEscopeta && contieneBalas && this->getEnergia() >= 6)
    {
        Ser *personaje = dynamic_cast<Ser *>(juego->tablero->getElementoEnPosicion(Posicion(fila, columna)));
        cout << "Indique a que posicion quiere atacar" << endl;
        cout << "A su alrededor hay los siguiente personajes: " << endl;
        for (int i = (this->fila - 1); i <= (this->fila + 1); i++)
        {
            for (int j = (this->columna - 1); j <= (this->columna + 1); j++)
            {
                Objeto *objetoEncontrado = juego->tablero->getElementoEnPosicion(Posicion(i, j));
                if (objetoEncontrado)
                {
                    if (objetoEncontrado->getCaracter() == C_ZOMBI || objetoEncontrado->getCaracter() == C_VAMPIRO && (objetoEncontrado != this))
                    {
                        objetoEncontrado->mostrarInformacion();
                        puedeAtacar = true;
                        cout << "En la posicion: " << objetoEncontrado->getFila() << "," << objetoEncontrado->getColumna();
                        cout << endl
                             << endl;
                    }
                }
            }
        }
        if (!puedeAtacar)
            cout << "No tenes enemigos cerca para atacarlos" << endl;
        else
        {
            cout << "Ingrese la fila" << endl;
            cin >> filaEnemigo;
            cout << "Ingrese la columna" << endl;
            cin >> columnaEnemigo;

            Objeto *objeto = juego->tablero->getElementoEnPosicion(Posicion(filaEnemigo, columnaEnemigo));
            Ser *enemigo = dynamic_cast<Ser *>(objeto);

            int danio;
            int escudo = enemigo->getEscudo();

            if (enemigo->getCaracter() == C_ZOMBI)
            {
                danio = (this->getFuerza());
                ajustarDanio(danio, escudo);
                enemigo->setVida(enemigo->getVida() - danio);
            }
            else if (enemigo->getCaracter() == C_VAMPIRO)
            {
                danio = (((this->getFuerza()) * 0.20));
                ajustarDanio(danio, escudo);
                enemigo->setVida(enemigo->getVida() - danio);
            }
            this->setEnergia((this->getEnergia()) - 5);
            //this->inventario.at(posBalas)->setCantidad() -= 2;
            cout << "Atacado! (☞ ﾟヮﾟ)☞" << endl;
            cout << "Tu enemigo tenia un escudo de " << enemigo->getEscudo() << " entonces tu daño fue de " << danio
                 << endl;
            objeto = juego->tablero->getElementoEnPosicion(Posicion(filaEnemigo, columnaEnemigo));
            enemigo = dynamic_cast<Ser *>(objeto);
            enemigo->mostrarInformacion();
        }
    }
}

bool Humano::seEstaTransformando() {
    return transformando;
}

void Humano::actualizar()
{
    int nuevaEnergia = this->energia + 5;

    if (nuevaEnergia > MAX_ENERGIA)
        this->energia = MAX_ENERGIA;
    else
        this->energia = nuevaEnergia;

    if(contadorTurnos == 1) {
        this->escudo--;
        seDefendio = false;
        contadorTurnos = 0;
    }

    if(seDefendio){
        contadorTurnos = 1;
    }
}

void Humano::defender(Juego *juego) {
    int tamanio = (int) inventario.size();
    string leido;
    bool tieneAgua = false;
    int i = 0;
    Elemento *aux;

    while (!tieneAgua && i < tamanio) {
        leido = inventario.at(i)->getNombre();
        aux = inventario.at(i);
        if ((leido == S_AGUA_BENDITA) && (aux->getCantidad() > 0)) {
            tieneAgua = true;
        }
        i++;
    }
    if (tieneAgua) {
        cout << "Tiene agua bendita en su inventario, desea usarla?" << endl;
        cout << "1 - Si" << endl;
        cout << "2 - No" << endl;
        leido = juego->solicitarOpcion();

        while (!esUnNumero(leido) || stoi(leido) < 1 || stoi(leido) > 2) {
            cout << "Por favor ingrese un numero valido" << endl;
            leido = juego->solicitarOpcion();
        }
        int respuesta = stoi(leido);

        if (respuesta == 2) { // Si tiene pero prefiere no usarla
            if (this->escudo < MAX_ESCUDO){         // Solo se le aumenta el escudo si no tiene lo maximo posible
                if(seDefendio){                     //Si ya se habia defendido, dejo el escudo como esta, pero por un turno mas
                    contadorTurnos = 0;
                }
                else {
                    int anterior = this->escudo;
                    this->escudo++;
                    this->seDefendio = true;
                    cout << "Escudo:" << anterior << "--> " << this->escudo << endl;
                }
            }
            else {                      //  Si ya no se puede agregar mas escudo
                int anterior = this->energia;
                this->energia += 3;
                cout << "Ya tenes el maximo escudo posible" << endl;
                cout << "Energia:" << anterior << "--> " << this->energia << endl;
            }
        }
        else if(respuesta == 1){ // Si quiere usar el agua
            int anterior = this->energia;
            this->energia = MAX_ENERGIA;
            aux->setCantidad(aux->getCantidad() - 1);
            cout << "Energia:" << anterior << "--> " << this->energia << endl;
        }
    }
    else { // Si no tiene agua
        if((this->energia += 3) <= MAX_ENERGIA) {
            int anterior = this->energia;
            this->energia += 3;
            cout << "Energia:" << anterior << "--> " << this->energia << endl;
        }
        else
            this->energia = MAX_ENERGIA;
    }
}

Humano::~Humano()
{
}
