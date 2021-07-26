#include "../../src/main.h"

Juego::Juego()
{
    salir = false;

    menues = new Lista<Menu *>;
    tablero = new Tablero(PATH_ARCHIVO_ESTADO);
    this->llenarMenues();
}

void Juego::llenarMenues()
{
    const char *archivos[CANTIDAD_MENUES] =
        {OPCIONES_MENU_MAIN,
         OPCIONES_MENU_SIMULACION,
         OPCIONES_MENU_COMIENZO_TURNO,
         OPCIONES_MENU_TURNO};

    int longitudMenu = 0;

    Menu *menu = 0;

    for (size_t i = 0; i < CANTIDAD_MENUES; i++)
    {
        // Buscamos la cantidad de lineas/opciones que contiene el archivo
        longitudMenu = getCantidadOpcionesMenu(archivos[i]);

        // Instanciamos un menu con esa cantidad de opciones
        menu = new Menu(longitudMenu);

        // Llenamos las opciones del menu con las opciones del archivo
        llenarMenu(menu, archivos[i]);

        // Agregamos el menu a la lista de menues
        menues->alta(menu, i + 1);
    }

    cambiarMenu(menuMain);
}

void Juego::mostrarMenu()
{

    for (size_t i = 0; i < menuActual->getCantidad(); i++)
        cout << i + 1 << ") " + menuActual->getOpcion(i) << endl;

    cout << "Ingrese una opcion: " << endl;
}

void Juego::renderizarOpcion(ABB<int, Objeto *> *diccionario)
{
    string eleccionUsuario = solicitarOpcion();

    if (!esValidaElIngresoDelUsuario(eleccionUsuario))
        cout << "Ingreso invalido, ingrese nuevamente: ";
    else
        procesarOpcion(stoi(eleccionUsuario), diccionario);
}

string Juego::solicitarOpcion()
{
    string eleccionUsuario;

    cin >> eleccionUsuario;

    return eleccionUsuario;
}

void Juego::procesarOpcion(int opcion, ABB<int, Objeto *> *diccionario)
{

    // clearTerminal();
    switch (getIdxMenuActual())
    {
    case menuMain:
        procesarOpcionMenuMain(opcion);
        break;
    case menuSimulacion:
        procesarOpcionMenuSimulacion(opcion);
        break;

    //TODO: MIGRAR ESTE COUT HORRIBLE
    case menuComienzoDeTurno:
        cout << parsearBandoATexto(this->tablero->getJugadorActual()->getBando()) << endl
             << endl;
        procesarOpcionMenuComienzoTurno(opcion);
        avanzar();

        break;
    case menuTurno:
        cout << parsearBandoATexto(this->tablero->getJugadorActual()->getBando()) << endl
             << endl;
        procesarOpcionMenuTurno(opcion);
        avanzar();
        break;
    }
}

void Juego::procesarOpcionMenuMain(int opcion)
{
    switch (opcion)
    {
    case 1:
        procesarAgregarObjeto(this);
        break;
    case 2:
        procesarEliminarObjeto(this);
        break;
    case 3:
        this->tablero->getMapa()->mostrarMapa();
        break;
    case 4:
        procesarBuscarPorCuadrante(this);
        break;
    case 5:
        procesarMostrarEstadisticasPorId(this);
        break;
    case 6:
        procesarComenzarSimulacion(this);
        break;
    case 7:
        salir = true;
        break;
    default:
        break;
    }
}

void Juego::procesarOpcionMenuSimulacion(int opcion)
{
    switch (opcion)
    {
    case 1:
        procesarMostrarEstadisticasPorId(this);
        break;
    case 2:
        this->tablero->getMapa()->mostrarMapa();
        break;
    case 3:
        mostrarCantidadPersonajesPorBando(this);
        break;
    case 4:
        procesarSeleccionBando(this);
        break;
    case 5:
        cambiarMenu(menuMain);
        break;
    default:
        break;
    }
}

void Juego::procesarOpcionMenuComienzoTurno(int opcion)
{
    switch (opcion)
    {
    case 1:
        this->tablero->getMapa()->mostrarMapa();
        procesarGuardarJuego();
        break;
    default:
        procesarOpcionMenuTurno(opcion);
        break;
    }

    cambiarMenu(menuTurno);
}

void Juego::procesarOpcionMenuTurno(int opcion)
{
    this->tablero->getMapa()->mostrarMapa();

    switch (opcion)
    {
    case 1:
        procesarOpcionDefenderse(this);
        break;
    case 2:
        procesarOpcionAtacar(this);
        break;
    case 3:
        procesarOpcionMoverse(this);
        break;
    case 4:
        procesarOpcionPasarTurno(this);
    default:
        break;
    }
}

void Juego::pedirPosicion(int &fila, int &columna)
{
    string strPosicion;
    cout << "Ingrese la posicion del objeto. MAX = " << this->tablero->getMapa()->getFilas() << " "
         << this->tablero->getMapa()->getColumnas() << endl;
    cout << "Ejemplo: 10 5  --> fila 10 columna 5" << endl;
    cin.clear();
    cin.ignore(256, '\n');
    getline(cin, strPosicion);

    //Valida y modifica la posicion acorde al tablero
    while (!posicionEstaEnTablero(strPosicion, fila, columna, this->tablero))
    {
        cout << "Las coordenadas ingresadas no estan dentro del rango del tablero, pruebe otra vez" << endl;
        getline(cin, strPosicion);
    }
}

void Juego::cambiarMenu(enumMenu menu)
{
    idxMenu = menu;
    menuActual = menues->get(idxMenu);
}

enumMenu Juego::getIdxMenuActual()
{
    return idxMenu;
}

void Juego::avanzar()
{
    personajesJugados++;

    cout << "personajesJugados: " << personajesJugados;
    cout << "cantidad: " << this->tablero->getJugadorActual()->getCantidadPersonajes();

    // Termino el turno
    if (personajesJugados == this->tablero->getJugadorActual()->getCantidadPersonajes())
    {
        //TODO: DONT KNOW IF I HAVE TO CHECK FOR GAMEOVER?
        personajesJugados = 0;
        this->tablero->idxJugadorActual = (this->tablero->idxJugadorActual + 1) % 2;
        cambiarMenu(menuComienzoDeTurno);
    }

    personajeActual = this->tablero->getJugadorActual()->getPersonajes().at(personajesJugados);

    if (personajeActual->estaMuerto())
        avanzar();
}

bool Juego::esValidaElIngresoDelUsuario(string ingreso)
{
    return (ingreso != "" && esUnNumero(ingreso) &&
            stoi(ingreso) >= 1 && stoi(ingreso) <= menuActual->getCantidad());
}

bool Juego::cerrarMenu()
{
    return salir;
}

bool Juego::gameOver()
{
    return this->tablero->getJugador(0)->perdio() ||
           this->tablero->getJugador(1)->perdio();
}

Juego::~Juego()
{
    delete menues;
    delete tablero;
}