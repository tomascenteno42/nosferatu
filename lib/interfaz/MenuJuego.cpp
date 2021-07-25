#include "../../src/main.h"

MenuJuego::MenuJuego(Juego *juego)
{
    salir = false;

    menues = new Lista<Menu *>;
    this->juego = juego;
    this->llenarMenues();

    setEntrada("Elija una opcion: ");
}

void MenuJuego::llenarMenues()
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

void MenuJuego::mostrarMenu()
{
    for (size_t i = 0; i < menuActual->getCantidad(); i++)
        cout << i + 1 << ") " + menuActual->getOpcion(i) << endl;

    cout << getEntrada();
}

void MenuJuego::renderizarOpcion(ABB<int, Objeto *> *diccionario)
{
    string eleccionUsuario = solicitarOpcion();

    if (!esValidaElIngresoDelUsuario(eleccionUsuario))
        setEntrada("Ingreso invalido, ingrese nuevamente: ");
    else
        procesarOpcion(stoi(eleccionUsuario), diccionario);
}

string MenuJuego::solicitarOpcion()
{
    string eleccionUsuario;

    cin >> eleccionUsuario;

    return eleccionUsuario;
}

void MenuJuego::procesarOpcion(int opcion, ABB<int, Objeto *> *diccionario)
{
    switch (getIdxMenuActual())
    {
    case menuMain:
        procesarOpcionMenuMain(opcion);
        break;
    case menuSimulacion:
        procesarOpcionMenuSimulacion(opcion);
        break;
    case menuComienzoDeTurno:
        procesarOpcionMenuComienzoTurno(opcion);
        break;
    case menuTurno:
        procesarOpcionMenuTurno(opcion);
        break;
    }
}

void MenuJuego::procesarOpcionMenuMain(int opcion)
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
        this->juego->tablero->getMapa()->mostrarMapa();
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

void MenuJuego::procesarOpcionMenuSimulacion(int opcion)
{
    switch (opcion)
    {
    case 1:
        procesarMostrarEstadisticasPorId(this);
        break;
    case 2:
        this->juego->tablero->getMapa()->mostrarMapa();
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

void MenuJuego::procesarOpcionMenuComienzoTurno(int opcion)
{
    switch (opcion)
    {
    case 1:
        procesarGuardarJuego();
        break;
    default:
        procesarOpcionMenuTurno(opcion);
        break;
    }
}

void MenuJuego::procesarOpcionMenuTurno(int opcion)
{
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

void MenuJuego::pedirPosicion(int &fila, int &columna)
{
    string strPosicion;
    cout << "Ingrese la posicion del objeto. MAX = " << this->juego->tablero->getMapa()->getFilas() << " "
         << this->juego->tablero->getMapa()->getColumnas() << endl;
    cout << "Ejemplo: 10 5  --> fila 10 columna 5" << endl;
    cin.clear();
    cin.ignore(256, '\n');
    getline(cin, strPosicion);

    //Valida y modifica la posicion acorde al tablero
    while (!posicionEstaEnTablero(strPosicion, fila, columna, this->juego->tablero))
    {
        cout << "Las coordenadas ingresadas no estan dentro del rango del tablero, pruebe otra vez" << endl;
        getline(cin, strPosicion);
    }
}

void MenuJuego::cambiarMenu(enumMenu menu)
{
    idxMenu = menu;
    menuActual = menues->get(idxMenu);
}

enumMenu MenuJuego::getIdxMenuActual()
{
    return idxMenu;
}

string MenuJuego::getEntrada()
{
    return entrada;
}

void MenuJuego::setEntrada(string newEntrada)
{
    entrada = newEntrada;
}

bool MenuJuego::esValidaElIngresoDelUsuario(string ingreso)
{
    return (ingreso != "" && esUnNumero(ingreso) &&
            stoi(ingreso) >= 1 && stoi(ingreso) <= menuActual->getCantidad());
}

bool MenuJuego::cerrarMenu()
{
    return salir;
}

MenuJuego::~MenuJuego()
{
    delete menues;
}