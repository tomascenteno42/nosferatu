#include "main.h"

/* IMPORTANTE: MIGRAR A OTRO LADO */
bool buscarObjetoEnCuadrante(const string &nombreObjeto, CUADRANTE zona, Tablero *tablero)
{
    Posicion minPos;
    Posicion maxPos;
    bool encontrado;

    int filas = tablero->getMapa()->getFilas();
    int columnas = tablero->getMapa()->getColumnas();

    switch (zona)
    {
    case (NOROESTE):
        minPos = Posicion(1, 1);
        maxPos = Posicion(filas / 2, columnas / 2);
        break;
    case (NORESTE):
        minPos = Posicion((filas / 2) + 1, 1);
        maxPos = Posicion(filas, columnas / 2);
        break;
    case (SUROESTE):
        minPos = Posicion(1, (columnas / 2) + 1);
        maxPos = Posicion(filas / 2, columnas);
        break;
    case (SURESTE):
        minPos = Posicion((filas / 2) + 1, (columnas / 2) + 1);
        maxPos = Posicion(filas, columnas);
        break;
    default:
        throw Excepcion_error("Error, no se pudo encontrar un cuadrante valido!!");
    }

    return tablero->existeObjetoEnCuadrante(nombreObjeto, minPos, maxPos);
}

void llenarMenu(Menu *menu, const char *nombre)
{
    ifstream archivo;
    string opcion;

    archivo.open(nombre);

    if (archivo.is_open())
    {
        while (getline(archivo, opcion, '\n'))
            menu->alta(opcion);

        archivo.close();
    }
}

int getCantidadOpcionesMenu(const char *nombre)
{
    fstream archivo;

    archivo.open(nombre);

    string opcion;
    int cantidad = 0;

    if (archivo.is_open())
        while (getline(archivo, opcion, '\n'))
            cantidad++;
    else
        cout << "ERROR" << endl;

    archivo.close();

    return cantidad;
}

int pedirId(ENUM_OBJETOS objeto)
{

    string texto;
    int clave = -1;

    do
    {
        cout << "Ingrese una clave identificadora del objeto" << endl;

        cin.clear();
        cin >> texto;

        if (esUnNumero(texto))
            clave = stoi(texto);
        else
            cout << "Solo ingrese numeros porfavor." << endl;

        if (esUnNumero(texto) && !esIdValido(clave, objeto))
            cout << "Clave invalida, ingrese nuevamente. " << endl
                 << "Puede ser porque la clave no pertenece a el objeto en cuestion o la clave esta fuera de los limites"
                 << "(" << ID_VANESA << " - " << ID_NO_VALIDO - 1 << ")" << endl;

    } while (!esIdValido(clave, objeto));

    return clave;
}

BANDO pedirBando()
{
    string texto;

    do
    {
        cout << "Seleccione un bando(Humanos o Monstruos): " << endl;

        cin.clear();
        cin >> texto;

        if (texto != "Humanos" && texto != "humanos" && texto != "Monstruos" && texto != "monstruos")
            cout << "Bando invalido!" << endl;

    } while (texto != "Humanos" && texto != "humanos" && texto != "Monstruos" && texto != "monstruos");

    return parseBando(texto);
}

BANDO parseBando(string texto)
{
    if (texto == "Humanos" || texto == "humanos")
        return HUMANOS;
    else if (texto == "Monstruos" || texto == "monstruos")
        return MONSTRUOS;
    else
        return OBJETO;
}

int pedirCantidad()
{

    string texto;
    int cantidad = 0;
    do
    {
        cout << "Ingrese la cantidad deseada" << endl;
        cin.clear();
        cin >> texto;
        if (esUnNumero(texto))
        {
            cantidad = stoi(texto);
        }
        else
        {
            cout << "Solo reingrese numeros" << endl;
        }
        if (cantidad <= 0)
        {
            cout << "No se puede ingresar una cantidad menor a 1, ingrese denuevo la cantidad" << endl;
        }
    } while (cantidad <= 0);

    return cantidad;
}

string pedirTipoObjeto()
{

    string objeto;
    cout << left << "En el mapa se hallan estas cosas: elija una " << endl
         << HUMANO << ". " << setw(15) << S_HUMANO
         << HUMANO_CV << ". " << setw(15) << S_HUMANO_CV
         << ZOMBIE << ". " << setw(15) << S_ZOMBI << endl
         << VAMPIRO << ". " << setw(15) << S_VAMPIRO
         << VAMPIRELLA << ". " << setw(15) << S_VAMPIRELLA
         << NOSFERATU << ". " << setw(15) << S_NOSFERATU << endl
         << VANESA << ". " << setw(15) << S_VANESA
         << AGUA_BENDITA << ". " << setw(15) << S_AGUA_BENDITA
         << CRUZ << ". " << setw(15) << S_CRUZ << endl
         << ESTACA << ". " << setw(15) << S_ESTACA
         << ESCOPETA << ". " << setw(15) << S_ESCOPETA
         << BALAS << ". " << setw(15) << S_BALA << endl;
    cout << 0 << ". " << setw(15) << "Salir" << endl;
    cout << "Elija una opcion: " << endl;

    int opcion;

    do
    {
        cin >> opcion;

        if (opcion < 0 || opcion > MAX_OBJETOS)
            cout << "Por favor, ingrese una opcion valida!! ("
                 << "0, " << MAX_OBJETOS << ")" << endl;

    } while (opcion < 0 || opcion > MAX_OBJETOS);

    if (opcion != 0)
        objeto = Parser(ENUM_OBJETOS(opcion)).getNombre();

    return objeto;
}

CUADRANTE pedirCuadrante()
{
    cout << "Elija la zona donde quiere buscar cierto objeto" << endl
         << NOROESTE << " Zona Noroeste (NO)" << endl
         << NORESTE << " Zona Noreste (NE)" << endl
         << SUROESTE << " Zona Suroeste (SO)" << endl
         << SURESTE << " Zona Sureste (SE)" << endl;

    int opcion;

    do
    {
        cin.clear();
        cin >> opcion;

        if (opcion < 1 || opcion > 4)
            cout << "Ingrese una opcion valida!" << endl;

    } while (opcion < 1 || opcion > 4);

    CUADRANTE elegido = CUADRANTE(opcion);

    return elegido;
}

/* MENU MAIN */
void procesarAgregarObjeto(Juego *juego)
{
    int fila, columna;
    bool opcionAceptada = false;

    // Pedimos y modificamos fila/columna
    juego->pedirPosicion(fila, columna);

    while (!opcionAceptada)
    {
        try
        {
            string nombre = pedirTipoObjeto();
            if (!nombre.empty())
            {
                int cantidad = 1;

                if (nombre == S_BALA || nombre == S_AGUA_BENDITA)
                    cantidad = pedirCantidad();

                int clave = pedirId(parsearTextoAObjeto(nombre));

                if (juego->tablero->getDiccionario()->existe(clave))
                {
                    cout << "La clave ya existe, intente de nuevo luego." << endl;
                }
                else
                {
                    Objeto *objeto = Parser(nombre, cantidad, fila, columna).getObjeto();

                    juego->tablero->darDeAlta(Posicion(fila, columna), objeto);
                    juego->tablero->getDiccionario()->insertar(clave, objeto);
                }
            }
            opcionAceptada = true;
        }
        catch (Excepcion_error &e)
        {
            cout << e.obtenerDescripcion() << endl;
            opcionAceptada = false;
        }
    }
}
void procesarEliminarObjeto(Juego *juego)
{
    int fila, columna;

    juego->pedirPosicion(fila, columna);

    Objeto *objeto = juego->tablero->getElementoEnPosicion(Posicion(fila, columna));

    if (objeto != NULL)
    {
        objeto->mostrarInformacion();
        int id = objeto->getId();
        juego->tablero->getDiccionario()->eliminar(id);
        juego->tablero->darDeBaja(Posicion(fila, columna));
    }
    else
    {
        cout << "No habia ningun elemento en la posicion ingresada" << endl;
    }
}
void procesarBuscarPorCuadrante(Juego *juego)
{
    string nombreObjeto = pedirTipoObjeto();

    if (!nombreObjeto.empty())
    {
        juego->tablero->getMapa()->mostrarMapa();

        CUADRANTE zona = pedirCuadrante();

        bool encontrado = buscarObjetoEnCuadrante(nombreObjeto, zona, juego->tablero);

        if (!encontrado)
            cout << "El objeto no se encontro en el cuadrante" << endl;
        else
            cout << "<<<<Objeto hallado>>>>" << endl;
    }
}

void procesarMostrarEstadisticasPorId(Juego *juego)
{
    int id = pedirId(parsearTextoAObjeto(pedirTipoObjeto()));

    if (juego->tablero->getDiccionario()->existe(id))
        juego->tablero->getDiccionario()->getData(id)->mostrarInformacion();
    else
        cout << "El id no existe, intente de nuevo luego." << endl;
}

void procesarComenzarSimulacion(Juego *juego)
{
    juego->cambiarMenu(menuSimulacion);
}

/* MENU SIMULACION */
void mostrarCantidadPersonajesPorBando(Juego *juego)
{
    BANDO bando = pedirBando();
    vector<int> ids = juego->tablero->getDiccionario()->idsEnOrden();
    int contador = 0;

    if (bando == HUMANOS)
    {
        for (size_t i = 0; i < ids.size(); i++)
            if (ids.at(i) < ID_ZOMBIE)
                contador++;
    }
    else
    {
        for (size_t i = 0; i < ids.size(); i++)
            if (ids.at(i) >= ID_ZOMBIE && ids.at(i) < ID_AGUA_BENDITA)
                contador++;
    }

    cout << "La cantidad de personajes en el bando es: " << contador << endl;
}
void procesarSeleccionBando(Juego *juego)
{
    BANDO bando = pedirBando();

    // Establecemos el jugador que arranca la partida de forma aleatoria
    juego->tablero->idxJugadorActual = rand() % 2;

    clearTerminal();

    juego->tablero->getMapa()->mostrarMapa();
    juego->cambiarMenu(menuComienzoDeTurno);
}

/* MENU TURNO */
void procesarOpcionDefenderse(Juego *juego)
{
}
void procesarOpcionAtacar(Juego *juego)
{
}
void procesarOpcionMoverse(Juego *juego)
{
    int fila, columna;
    juego->pedirPosicion(fila, columna);
    juego->personajeActual->mover(juego->tablero->getMapa(), Posicion(fila, columna));
}
void procesarOpcionPasarTurno(Juego *juego)
{
}

/* MENU COMIENZO DE TURNO */
void procesarGuardarJuego(Juego *juego)
{
}