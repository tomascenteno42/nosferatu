#include "../../src/main.h"

Menu::Menu(string PATH_ARCHIVO_ESTADO)
{
    try
    {
        this->tablero = new Tablero(PATH_ARCHIVO_ESTADO);
        this->opcionElegida = 0;
    }
    catch (const invalid_argument &e)
    {
        cout << e.what() << endl;
        cout << "Buscando archivo... Intentando otra vez..." << endl;
        string nueva_dir = PATH_ARCHIVO_ESTADO;
        if (nueva_dir == "estado.txt")
        {
            nueva_dir = "../estado.txt";
        }
        else
        {
            nueva_dir = "estado.txt";
        }
        this->tablero = new Tablero(nueva_dir);
    }
    catch (...)
    {
        throw;
    }
}

void Menu::accederAOpciones()
{
    cout << "Ingrese una opcion" << endl
         << "1. Ingresar a las opciones" << endl
         << "0. Salir" << endl;
    string opcion;
    int numero_opcion;
    do
    {
        cin.clear();
        cin >> opcion;
        if (this->esUnNumero(opcion))
        {
            numero_opcion = stoi(opcion);
        }
        else
        {
            cout << "Porfavor ingrese un numero" << endl;
        }
        if (numero_opcion != 0 && numero_opcion != 1)
        {
            cout << "Porfavor ingrese una de las opciones permitidas" << endl;
        }
    } while (numero_opcion != 0 && numero_opcion != 1);
    if (numero_opcion == 1)
    {
        this->mostrarOpciones();
    }
}

void Menu::mostrarOpciones()
{

    cout << "Eliga una opcion ingresando el numero correspondiente: " << endl
         << MOSTRAR_TABLERO << ". "
         << "Mostrar tablero" << endl
         << MOSTRAR_RESUMEN << ". "
         << "Mostrar resumen del tablero" << endl
         << BUSCAR_POR_CUADRANTE << ". "
         << "Busqueda de un elemento por cuadrante" << endl
         << ALTA << ". "
         << "Dar de alta un elemento en el tablero" << endl
         << BAJA << ". "
         << "Dar de baja un elemento en el tablero" << endl
         << BUSCAR_POR_POSICION << ". "
         << "Buscar de un elemento por posicion en el tablero" << endl
         << "0. "
         << "Salir del juego" << endl;
}

void Menu::pedirOpcion()
{
    bool opcion_valida = false;

    while (!opcion_valida)
    {
        cin.clear();
        cin >> this->opcionElegida;
        opcion_valida = this->verificarOpcionValida();
        if (!opcion_valida)
        {
            cout << "Por favor, ingrese una opcion valida" << endl;
        }
    }
}

bool Menu::verificarOpcionValida()
{
    return (opcionElegida >= 0 && opcionElegida < MAX_OPCIONES);
}

void Menu::procesarOpcion()
{

    switch (this->opcionElegida)
    {
    case (MOSTRAR_TABLERO):
        this->mostrarTablero();
        break;
    case (MOSTRAR_RESUMEN):
        this->mostrarResumen();
        break;
    case (BUSCAR_POR_CUADRANTE):
        this->buscarPorCuadrante();
        break;
    case (ALTA):
        this->darDeAlta();
        this->mostrarTablero();
        break;
    case (BAJA):
        this->darDeBaja();
        this->mostrarTablero();
        break;
    case (BUSCAR_POR_POSICION):
        this->buscarPorPosicion();
        break;
    default:
        break;
    }
}

void Menu::mostrarTablero()
{
    int espaciado = 3;
    cout << setfill(' ') << setw(espaciado) << "";
    for (int k = 0; k < this->tablero->cantidadColumnas(); k++)
    {
        cout << setw(espaciado) << k + 1;
    }
    cout << endl;
    for (int i = 0; i < this->tablero->cantidadFilas(); i++)
    {
        cout << setw(espaciado) << i + 1;
        for (int j = 0; j < this->tablero->cantidadColumnas(); j++)
        {
            Objeto *objeto_obtenido = this->tablero->getElementoEnPosicion(i, j);
            if (objeto_obtenido != NULL)
            {
                cout << setw(espaciado) << objeto_obtenido->getCaracter();
            }
            else
            {
                cout << setw(espaciado) << "*";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void Menu::mostrarResumen()
{
    cout << endl
         << setw(20) << " "
         << "Actual informacion del mundo" << endl;
    cout << setfill('~') << setw(70) << "" << setfill(' ') << endl;
    cout << "|" << setw(15) << " Objeto" << setw(4) << "|" << setw(15) << " Cantidad"
         << setw(4) << "|" << setw(27) << " Porcentaje sobre el total" << setw(4) << "|" << endl;
    cout << setfill('~') << setw(70) << "" << setfill(' ') << endl;

    string nombres[8] = {S_HUMANO, S_VAMPIRO, S_ZOMBI, S_CRUZ, S_ESTACA, S_AGUA_BENDITA,
                         S_BALA, S_ESCOPETA};

    for (auto &nombre : nombres)
    {
        cout << "|" << setw(15) << nombre << setw(4) << "|" << setw(15);
        cout << this->tablero->getExistentes(nombre);
        cout << setw(4) << "|" << setw(20)
             << this->tablero->getPorcentaje(nombre)
             << setw(11) << "|" << endl;
        cout << setfill('~') << setw(70) << "" << setfill(' ') << endl;
    }
}

int Menu::getOpcionElegida()
{
    return this->opcionElegida;
}

void Menu::buscarPorCuadrante()
{
    string nombre_objeto = this->usuarioPedirObjeto();
    if (!nombre_objeto.empty())
    {
        this->mostrarTablero();
        CUADRANTE zona = this->usuarioPedirCuadrante();
        bool objeto_encontrado = this->buscarObjetoEnCuadrante(nombre_objeto, zona);
        if (!objeto_encontrado)
        {
            cout << "El objeto no se encontro en el cuadrante" << endl;
        }
        else
        {
            cout << "<<<<Objeto hallado>>>>" << endl;
        }
    }
}

bool Menu::buscarObjetoEnCuadrante(const string &nombre_objeto, CUADRANTE zona)
{
    Posicion pos_min;
    Posicion pos_max;
    bool encontrado;
    switch (zona)
    {
    case (NOROESTE):
        pos_min = Posicion(1, 1);
        pos_max = Posicion(this->tablero->cantidadFilas() / 2, this->tablero->cantidadColumnas() / 2);
        break;
    case (NORESTE):
        pos_min = Posicion((this->tablero->cantidadFilas() / 2) + 1, 1);
        pos_max = Posicion(this->tablero->cantidadFilas(), this->tablero->cantidadColumnas() / 2);
        break;
    case (SUROESTE):
        pos_min = Posicion(1, (this->tablero->cantidadColumnas() / 2) + 1);
        pos_max = Posicion(this->tablero->cantidadFilas() / 2, this->tablero->cantidadColumnas());
        break;
    case (SURESTE):
        pos_min = Posicion((this->tablero->cantidadFilas() / 2) + 1, (this->tablero->cantidadColumnas() / 2) + 1);
        pos_max = Posicion(this->tablero->cantidadFilas(), this->tablero->cantidadColumnas());
        break;
    default:
        throw Excepcion_error("Error, no se pudo encontrar un cuadrante valido!!");
    }
    encontrado = this->tablero->existeObjetoEnCuadrante(nombre_objeto, pos_min, pos_max);
    return encontrado;
}

void Menu::darDeAlta()
{
    int fila, columna;
    this->pedirPosicion(fila, columna);
    bool opcion_aceptada = false;
    while (!opcion_aceptada)
    {
        try
        {
            string nombre_obtenido = this->usuarioPedirObjeto();
            if (!nombre_obtenido.empty())
            {
                int cantidad = 1;
                if (nombre_obtenido == S_BALA || nombre_obtenido == S_AGUA_BENDITA)
                {
                    cantidad = this->usuarioPedirCantidad();
                }

                int clave = this->usuarioPedirClave(parsearTextoAObjeto(nombre_obtenido));

                Objeto *nuevo_objeto = Parser(nombre_obtenido, cantidad).obtener_objeto();

                tablero->darDeAlta(fila, columna, nuevo_objeto);
                tablero->getDiccionario()->insertar(clave, nuevo_objeto);
            }
            opcion_aceptada = true;
        }
        catch (Excepcion_error &e)
        {
            cout << e.obtenerDescripcion() << endl;
            opcion_aceptada = false;
        }
    }
}

void Menu::darDeBaja()
{
    int fila, columna;

    this->pedirPosicion(fila, columna);

    Objeto *objeto = this->tablero->getElementoEnPosicion(fila, columna);

    if (objeto != NULL)
    {
        this->tablero->getDiccionario()->eliminar(objeto->getId());
        this->tablero->darDeBaja(fila, columna);
    }
    else
    {
        cout << "No habia ningun elemento en la posicion ingresada" << endl;
    }
}

void Menu::buscarPorPosicion()
{
    int fila, columna;
    this->pedirPosicion(fila, columna);

    Objeto *objeto_buscado = this->tablero->getElementoEnPosicion(fila, columna);
    if (objeto_buscado)
    {
        cout << "En la posicion se encontro: ";
        objeto_buscado->mostrarInformacion();
        cout << endl;
    }
    else
    {
        cout << "No hay nada en esta posicion" << endl;
    }
}

bool Menu::rangoValido(const std::string &texto_ingresado, int &fila, int &columna)
{
    bool rango_es_valido = false;
    string primer_numero, segundo_numero;
    istringstream input(texto_ingresado);
    getline(input, primer_numero, ' ');
    getline(input, segundo_numero, ' ');

    if (esUnNumero(primer_numero) && esUnNumero(segundo_numero))
    {
        fila = stoi(primer_numero) - 1;
        columna = stoi(segundo_numero) - 1;
        rango_es_valido = this->tablero->posicionValida(fila, columna);
    }
    return rango_es_valido;
}

bool Menu::esUnNumero(std::string texto)
{
    bool esUnNumero = true;
    long unsigned i = 0;
    while (esUnNumero && i < texto.length())
    {
        esUnNumero = isdigit(texto[i]);
        i++;
    }
    return esUnNumero;
}

void Menu::pedirPosicion(int &fila, int &columna)
{
    string texto_ingresado;
    cout << "Ingrese la posicion del objeto. MAX = " << this->tablero->cantidadFilas() << " "
         << this->tablero->cantidadColumnas() << endl;
    cout << "Ejemplo: 10 5  --> fila 10 columna 5" << endl;
    cin.clear();
    cin.ignore(256, '\n');
    getline(cin, texto_ingresado);

    while (!this->rangoValido(texto_ingresado, fila, columna))
    {
        cout << "Las coordenadas ingresadas no estan dentro del rango del tablero, pruebe otra vez" << endl;
        getline(cin, texto_ingresado);
    }
}

Menu::~Menu()
{
    delete this->tablero;
}

string Menu::usuarioPedirObjeto()
{
    string objeto_elegido;
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

    int opcion_usuario;
    do
    {
        cin >> opcion_usuario;
        if (opcion_usuario < 0 || opcion_usuario > MAX_OBJETOS)
        {
            cout << "Por favor, ingrese una opcion valida!! ("
                 << "0, " << MAX_OBJETOS << ")" << endl;
        }
    } while (opcion_usuario < 0 || opcion_usuario > MAX_OBJETOS);
    if (opcion_usuario != 0)
    {
        objeto_elegido = Parser(ENUM_OBJETOS(opcion_usuario)).obtener_nombre();
    }
    return objeto_elegido;
}

int Menu::usuarioPedirCantidad()
{
    string texto;
    int cantidad = 0;
    do
    {
        cout << "Ingrese la cantidad deseada" << endl;
        cin.clear();
        cin >> texto;
        if (this->esUnNumero(texto))
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

int Menu::usuarioPedirClave(ENUM_OBJETOS objeto)
{
    string texto;
    int clave = -1;
    // bool claveValida = false;

    // cout << "Ingrese una clave identificadora del objeto" << endl;
    // cin >> texto;

    // while (!claveValida)
    // {
    //     cout << "Clave invalida, ingrese nuevamente. " << endl
    //          << "Puede ser porque la clave no pertenece a el objeto en cuestion o la clave esta fuera de los limites"
    //          << "(" << ID_VANESA << " - " << ID_NO_VALIDO - 1 << ")" << endl;
    //     cin >> texto;

    //     if (this->esUnNumero(texto))
    //     {
    //         clave = stoi(texto);
    //         if (esIdValido(clave, objeto))
    //             claveValida = true;
    //     }
    // }

    do
    {
        cout << "Ingrese una clave identificadora del objeto" << endl;

        cin.clear();
        cin >> texto;

        if (this->esUnNumero(texto))
            clave = stoi(texto);
        else
            cout << "Solo ingrese numeros porfavor." << endl;

        if (!esIdValido(clave, objeto))
            cout << "Clave invalida, ingrese nuevamente. " << endl
                 << "Puede ser porque la clave no pertenece a el objeto en cuestion o la clave esta fuera de los limites"
                 << "(" << ID_VANESA << " - " << ID_NO_VALIDO - 1 << ")" << endl;

    } while (!esIdValido(clave, objeto));

    return clave;
}

CUADRANTE Menu::usuarioPedirCuadrante()
{
    cout << "Elija la zona donde quiere buscar cierto objeto" << endl
         << NOROESTE << " Zona Noroeste (NO)" << endl
         << NORESTE << " Zona Noreste (NE)" << endl
         << SUROESTE << " Zona Suroeste (SO)" << endl
         << SURESTE << " Zona Sureste (SE)" << endl;
    int opcion_ingresada;
    do
    {
        cin.clear();
        cin >> opcion_ingresada;
        if (opcion_ingresada < 1 || opcion_ingresada > 4)
        {
            cout << "Ingrese una opcion valida!" << endl;
        }
    } while (opcion_ingresada < 1 || opcion_ingresada > 4);
    CUADRANTE elegido = CUADRANTE(opcion_ingresada);
    return elegido;
}

Tablero *Menu::getTablero()
{
    return tablero;
}