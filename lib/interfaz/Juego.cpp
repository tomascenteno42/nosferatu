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

void Juego::mostrarOpciones()
{

    for (size_t i = 0; i < menuActual->getCantidad(); i++)
        cout << i + 1 << ") " + menuActual->getOpcion(i) << endl;

    cout << "Ingrese una opcion: " << endl;
}

void Juego::mostrar()
{
    clearTerminal();

    this->tablero->getMapa()->mostrarMapa();

    if (idxMenu >= menuComienzoDeTurno)
    {
        mostrarBando(this->tablero->getJugadorActual()->getBando());
        this->personajeActual->mostrarInformacion();
        cout << "Posicion: "
             << "(" << this->personajeActual->getFila() << "," << this->personajeActual->getColumna() << ")";
        cout << endl;
        cout << endl;

        string nombre = this->personajeActual->getNombre();
        if (nombre == S_HUMANO_CV || nombre == S_VANESA || nombre == S_HUMANO)
        {
            Ser *ser = this->personajeActual;
            Humano *humano = dynamic_cast<Humano *>(ser);

            if (!humano->inventarioVacio())
            {
                humano->mostrarInventario();
                cout << endl;
            }
        }
    }

    mostrarOpciones();

    renderizarOpcion(this->tablero->getDiccionario());

    cout << "Presione enter para continuar..." << endl;

    getchar();
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
        procesarOpcionMenuComienzoTurno(opcion);
        break;
    case menuTurno:
        procesarOpcionMenuTurno(opcion);
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
        procesarBuscarPorCuadrante(this);
        break;
    case 4:
        procesarMostrarEstadisticasPorId(this);
        break;
    case 5:
        procesarComenzarSimulacion(this);
        break;
    case 6:
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
        mostrarCantidadPersonajesPorBando(this);
        break;
    case 3:
        procesarSeleccionBando(this);
        break;
    case 4:
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
        procesarGuardarJuego(this);
        break;
    case 2:
        procesarOpcionDefenderse(this);
        break;
    case 3:
        procesarOpcionAtacar(this);
        break;
    case 4:
        procesarOpcionMoverse(this);
        break;
    case 5:
        procesarOpcionPasarTurno(this);
    default:
        break;
    }

    cambiarMenu(menuTurno);
    avanzar();
}

void Juego::procesarOpcionMenuTurno(int opcion)
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

    avanzar();
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
    cout << "AVANZAR" << endl;
    personajesJugados++;

    // Termino el turno
    if (personajesJugados == this->tablero->getJugadorActual()->getCantidadPersonajes())
    {
        cout << "TERMINO EL TURNO" << endl;
        //TODO: DONT KNOW IF I HAVE TO CHECK FOR GAMEOVER?
        personajesJugados = 0;
        this->tablero->idxJugadorActual = (this->tablero->idxJugadorActual + 1) % 2;
        cambiarMenu(menuComienzoDeTurno);

        vector<Ser *> personajes = this->tablero->getJugadorActual()->getPersonajes();
        int cantidadPersonajes = this->tablero->getJugadorActual()->personajesVivos();

        for (int i = 0; i < cantidadPersonajes; i++)
            personajes.at(i)->actualizar();
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