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

void Vanesa::atacar(Tablero *tablero) {
    size_t i = 0;
    if (this->getEnergia() < 8)
        cout << "No podes hacer eso, te falta energia ლ(ಠ_ಠლ)" << endl;
    while (i < inventario.size() && this->getEnergia() >= 8) {
        if (inventario.at(i)->getCaracter() == C_ESCOPETA)
            contieneEscopeta = true;
        else if (inventario.at(i)->getCaracter() == C_BALAS && inventario.at(i)->getCantidad() > 2)
            contieneBalas = true;
        else if (inventario.at(i)->getCaracter() == C_AGUA_BENDITA)
            contieneAguas = true;
        else if (inventario.at(i)->getCaracter() == C_ESTACA)
            contieneEstaca = true;
        i++;
    }
    if (!contieneBalas && contieneEscopeta && !contieneAguas && !contieneEstaca && this->getEnergia() >= 6)
        cout << "No podes hacer eso, te faltan balas ლ(ಠ_ಠლ)" << endl;
    else if ((!contieneEscopeta ||
              contieneEscopeta) && !contieneAguas && !contieneBalas && !contieneEstaca && this->getEnergia() >= 6)
        cout << "No tenes nada en tu inventario que te sirva ¯\\(°_o)/¯" << endl;
    else if ((contieneEscopeta && contieneBalas) || contieneAguas || contieneEstaca && this->getEnergia() >= 6) {
        int opcion, cant_armas = 0;
        cout << left << "Indique que quiere utilizar para atacar" << endl;
        if (contieneBalas) {
            cout << "1. " << setw(15) << S_ESCOPETA << endl;
            cant_armas++;
        }
        if (contieneAguas) {
            cout << "2. " << setw(15) << S_AGUA_BENDITA<< endl;
            cant_armas++;
        }
        if (contieneEstaca) {
            cout << "3. " << setw(15) << S_ESTACA<< endl;
            cant_armas++;
        }
        cout << "Elija una opcion: " << endl;
        do {
            cin >> opcion;
            if (opcion < 0 || opcion > cant_armas)
                cout << "Por favor, ingrese una opcion valida!! ("
                     << "0, " << cant_armas << ")" << endl;
        } while (opcion < 0 || opcion > cant_armas);
        switch (opcion) {
            case 1:
                atacarEscopeta(tablero);
                break;
            case 2:
                atacarAgua(tablero);
                break;
            case 3:
                atacarEstaca(tablero);
                break;
        }
    }
}

void Vanesa::atacarEscopeta(Tablero *tablero) {
    int fila_enemigo, columna_enemigo;
    bool puedeAtacar = false;
    cout << "Indique a que posicion quiere atacar" << endl;
    cout << "A su alrededor hay: " << endl;
    for (int i = (this->fila - 2); i <= (this->fila + 2); i++)
    {
        for (int j = (this->columna - 2); j <= (this->columna + 2); j++)
        {
            Objeto *objeto_encontrado = tablero->getElementoEnPosicion(Posicion(i, j));
            if (objeto_encontrado){
                if(objeto_encontrado->getCaracter() == C_ZOMBI || objeto_encontrado->getCaracter() == C_VAMPIRO && (objeto_encontrado!= this)) {
                    objeto_encontrado->mostrarInformacion();
                    puedeAtacar = true;
                    cout << "en la posicion: " << objeto_encontrado->getFila() << "," << objeto_encontrado->getColumna()
                         << "\n" << endl;
                }
            }
        }
    }
    if(!puedeAtacar)
        cout << "No tenes enemigos cerca para atacarlos" << endl;
    else if(puedeAtacar) {
        cout << "Ingrese la fila" << endl;
        cin >> fila_enemigo;
        cout << "Ingrese la columna" << endl;
        cin >> columna_enemigo;
        Objeto *objeto = tablero->getElementoEnPosicion(Posicion(fila_enemigo, columna_enemigo));
        Ser *enemigo = dynamic_cast<Ser *>(objeto);
        int danio, escudo;
        escudo = enemigo->getEscudo();
        if (enemigo->getCaracter() == C_ZOMBI) {
            danio = ((this->getFuerza()) * 1.25);
            ajustarDanio(danio, escudo);
            enemigo->setVida(enemigo->getVida() - danio);
        } else if (enemigo->getCaracter() == C_VAMPIRO) {
            danio = (((this->getFuerza()) * 0.40));
            ajustarDanio(danio, escudo);
            enemigo->setVida(enemigo->getVida() - danio);
        }
        this->setEnergia((this->getEnergia())-8);
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
        objeto = tablero->getElementoEnPosicion(Posicion(fila_enemigo, columna_enemigo));
        enemigo = dynamic_cast<Ser *>(objeto);
        enemigo->mostrarInformacion();
    }
}

void Vanesa::atacarAgua(Tablero *tablero) {
    int fila_enemigo, columna_enemigo;
    bool puedeAtacar = false;
    cout << "Indique a que posicion quiere atacar" << endl;
    cout << "A su alrededor hay: " << endl;
    for (int i = (this->fila - 1); i <= (this->fila + 1); i++)
    {
        for (int j = (this->columna - 1); j <= (this->columna + 1); j++)
        {
            Objeto *objeto_encontrado = tablero->getElementoEnPosicion(Posicion(i, j));
            if (objeto_encontrado){
                if(objeto_encontrado->getCaracter() == C_ZOMBI || objeto_encontrado->getCaracter() == C_VAMPIRO && (objeto_encontrado!= this)) {
                    objeto_encontrado->mostrarInformacion();
                    puedeAtacar = true;
                    cout << "en la posicion: " << objeto_encontrado->getFila() << "," << objeto_encontrado->getColumna()
                         << "\n" << endl;
                }
            }
        }
    }
    if(!puedeAtacar)
        cout << "No tenes enemigos cerca para atacarlos" << endl;
    else if(puedeAtacar) {
        cout << "Ingrese la fila" << endl;
        cin >> fila_enemigo;
        cout << "Ingrese la columna" << endl;
        cin >> columna_enemigo;
        Objeto *objeto = tablero->getElementoEnPosicion(Posicion(fila_enemigo, columna_enemigo));
        Ser *enemigo = dynamic_cast<Ser *>(objeto);
        int escudo = enemigo->getEscudo();
        int danio = 20;
        if (enemigo->getCaracter() == C_ZOMBI) {
            cout << "Perdiste tu agua bendita ᕦ(ò_óˇ)ᕤ" << endl;
            //ELIMINAR AGUA BENDITA DEL INVENTARIO
        } else if (enemigo->getCaracter() == C_VAMPIRO) {
            ajustarDanio(danio, escudo);
            enemigo->setVida(enemigo->getVida() - danio);
            cout << "Atacado! (☞ ﾟヮﾟ)☞" << endl;
        }
        this->setEnergia((this->getEnergia())-8);
        cout << "Tu enemigo tenia un escudo de " << enemigo->getEscudo() << " entonces tu daño fue de " << danio
             << endl;
        objeto = tablero->getElementoEnPosicion(Posicion(fila_enemigo, columna_enemigo));
        enemigo = dynamic_cast<Ser *>(objeto);
        enemigo->mostrarInformacion();
    }
}

void Vanesa::atacarEstaca(Tablero *tablero) {
    int fila_enemigo, columna_enemigo;
    bool puedeAtacar = false;
    cout << "Indique a que posicion quiere atacar" << endl;
    cout << "A su alrededor hay: " << endl;
    Posicion arriba((this->getFila()-1),this->getColumna());
    Objeto *objeto_encontrado = tablero->getElementoEnPosicion(arriba);
    if (objeto_encontrado){
        if(objeto_encontrado->getCaracter() == C_ZOMBI || objeto_encontrado->getCaracter() == C_VAMPIRO){
            objeto_encontrado->mostrarInformacion();
            puedeAtacar = true;
            cout << "en la posicion: " << objeto_encontrado->getFila() << "," << objeto_encontrado->getColumna()
                 << "\n" << endl;
        }
    }

    Posicion abajo((this->getFila()+1),this->getColumna());
    objeto_encontrado = tablero->getElementoEnPosicion(abajo);
    if (objeto_encontrado){
        if(objeto_encontrado->getCaracter() == C_ZOMBI || objeto_encontrado->getCaracter() == C_VAMPIRO){
            objeto_encontrado->mostrarInformacion();
            puedeAtacar = true;
            cout << "en la posicion: " << objeto_encontrado->getFila() << "," << objeto_encontrado->getColumna()
                 << "\n" << endl;
        }
    }

    Posicion izquierda(this->getFila(),(this->getColumna()-1));
    objeto_encontrado = tablero->getElementoEnPosicion(izquierda);
    if (objeto_encontrado){
        if(objeto_encontrado->getCaracter() == C_ZOMBI || objeto_encontrado->getCaracter() == C_VAMPIRO){
            objeto_encontrado->mostrarInformacion();
            puedeAtacar = true;
            cout << "en la posicion: " << objeto_encontrado->getFila() << "," << objeto_encontrado->getColumna()
                 << "\n" << endl;
        }
    }

    Posicion derecha(this->getFila(),(this->getColumna()+1));
    objeto_encontrado = tablero->getElementoEnPosicion(derecha);
    if (objeto_encontrado){
        if(objeto_encontrado->getCaracter() == C_ZOMBI || objeto_encontrado->getCaracter() == C_VAMPIRO){
            objeto_encontrado->mostrarInformacion();
            puedeAtacar = true;
            cout << "en la posicion: " << objeto_encontrado->getFila() << "," << objeto_encontrado->getColumna()
                 << "\n" << endl;
        }
    }
    if(!puedeAtacar)
        cout << "No tenes enemigos cerca para atacarlos" << endl;
    else if(puedeAtacar) {
        cout << "Ingrese la fila" << endl;
        cin >> fila_enemigo;
        cout << "Ingrese la columna" << endl;
        cin >> columna_enemigo;
        Objeto *objeto = tablero->getElementoEnPosicion(Posicion(fila_enemigo, columna_enemigo));
        Ser *enemigo = dynamic_cast<Ser *>(objeto);
        int danio, escudo;
        escudo = enemigo->getEscudo();
        if (enemigo->getCaracter() == C_ZOMBI) {
            danio = ((this->getFuerza()) * 0.25);
            ajustarDanio(danio, escudo);
            enemigo->setVida(enemigo->getVida() - danio);
            cout << "Atacado! (☞ ﾟヮﾟ)☞" << endl;
            cout << "Tu enemigo tenia un escudo de " << enemigo->getEscudo() << " entonces tu daño fue de " << danio
                 << endl;
        } else if (enemigo->getCaracter() == C_VAMPIRO) {
            enemigo->setVida(0);
            enemigo->estaMuerto();
            tablero->darDeBaja(Posicion(fila_enemigo, columna_enemigo));
            cout << "Atacado! (☞ ﾟヮﾟ)☞" << endl;
            cout << "Eliminaste a tu enemigo " << endl;
        }
        this->setEnergia((this->getEnergia())-8);
        /*i = 0;
        while (i < inventario.size()){
            if (inventario.at(i)->getCaracter() == C_BALAS){
                int balas = inventario.at(i)->getCantidad();
                balas = balas -2;
                inventario.at(i)->setBalas(balas);
            }
            i++;
        }*/

        objeto = tablero->getElementoEnPosicion(Posicion(fila_enemigo, columna_enemigo));
        enemigo = dynamic_cast<Ser *>(objeto);
        enemigo->mostrarInformacion();
    }
}

void Vanesa::actualizar()
{
    int nuevaEnergia = this->energia + 10;

    if(nuevaEnergia > MAX_ENERGIA)
        this->energia = MAX_ENERGIA;
    else
        this->energia = nuevaEnergia;
}


Vanesa::~Vanesa()
{
    Vanesa::contador--;
}
