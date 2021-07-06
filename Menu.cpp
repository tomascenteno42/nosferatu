#include "Menu.h"


using namespace std;


Menu::Menu(string PATH_ARCHIVO_ESTADO){
    try{
        this->tablero = new Tablero(PATH_ARCHIVO_ESTADO);
        this->opcion_elegida = 0;
    } catch (const invalid_argument &e){
        cout << e.what() << endl;
        cout << "Buscando archivo... Intentando otra vez..." << endl;
        string nueva_dir = PATH_ARCHIVO_ESTADO;
        if(nueva_dir == "estado.txt"){
            nueva_dir = "../estado.txt";
        } else {
            nueva_dir = "estado.txt";
        }
        this->tablero = new Tablero(nueva_dir);
    } catch(...){
        throw;
    }
}

void Menu::acceder_a_opciones(){
    cout << "Ingrese una opcion" << endl
         << "1. Ingresar a las opciones" << endl
         << "0. Salir" << endl;
    string opcion;
    int numero_opcion;
    do{
        cin.clear();
        cin >> opcion;
        if(this->es_un_numero(opcion)){
            numero_opcion = stoi(opcion);
        } else {
            cout << "Porfavor ingrese un numero" << endl;
        }
        if(numero_opcion != 0 && numero_opcion != 1){
            cout << "Porfavor ingrese una de las opciones permitidas" << endl;
        }
    }while(numero_opcion != 0 && numero_opcion != 1);
    if(numero_opcion == 1){
        this->mostrar_opciones();
    } else {

    }
}

void Menu::mostrar_opciones() {

    cout << "Eliga una opcion ingresando el numero correspondiente: " << endl
         << MOSTRAR_TABLERO << ". " << "Mostrar tablero" << endl
         << MOSTRAR_RESUMEN << ". " << "Mostrar resumen del tablero" << endl
         << BUSCAR_POR_CUADRANTE << ". " << "Busqueda de un elemento por cuadrante" << endl
         << ALTA << ". " << "Dar de alta un elemento en el tablero" << endl
         << BAJA << ". " << "Dar de baja un elemento en el tablero" << endl
         << BUSCAR_POR_POSICION << ". " << "Buscar de un elemento por posicion en el tablero" << endl
         << "0. " << "Salir del juego" << endl;

}

void Menu::pedir_opcion() {
    bool opcion_valida = false;

    while(!opcion_valida){
        cin.clear();
        cin >> this->opcion_elegida;
        opcion_valida = this->verificar_opcion_valida();
        if(!opcion_valida) {
            cout << "Por favor, ingrese una opcion valida" << endl;
        }
    }
}


bool Menu::verificar_opcion_valida() {
    return (opcion_elegida >= 0 && opcion_elegida < MAX_OPCIONES);
}

void Menu::procesar_opcion() {

    switch(this->opcion_elegida){
        case(MOSTRAR_TABLERO):
            this->mostrar_tablero();
            break;
        case(MOSTRAR_RESUMEN):
            this->mostrar_resumen();
            break;
        case(BUSCAR_POR_CUADRANTE):
            this->buscar_por_cuadrante();
            break;
        case(ALTA):
            this->dar_de_alta();
            this->mostrar_tablero();
            break;
        case(BAJA):
            this->dar_de_baja();
            this->mostrar_tablero();
            break;
        case(BUSCAR_POR_POSICION):
            this->buscar_por_posicion();
            break;
        default:
            break;
    }
}

void Menu::mostrar_tablero() {
    int espaciado = 3;
    cout << setfill(' ') << setw(espaciado) << "";
    for(int k = 0; k < this->tablero->cantidad_columnas(); k++){
        cout << setw(espaciado) << k+1;
    }
    cout << endl;
    for(int i = 0; i < this->tablero->cantidad_filas(); i++){
        cout << setw(espaciado) << i+1;
        for(int j = 0; j < this->tablero->cantidad_columnas(); j++){
            Objeto* objeto_obtenido = this->tablero->obtener_elemento_en_posicion(i, j);
            if(objeto_obtenido != NULL){
                cout << setw(espaciado) << objeto_obtenido->obtener_caracter();
            } else{
                cout << setw(espaciado) << "*";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void Menu::mostrar_resumen() {
    cout << endl <<  setw(20) << " " << "Actual informacion del mundo" << endl;
    cout << setfill('~') << setw(70) << "" << setfill(' ') << endl;
    cout << "|" << setw(15) << " Objeto" << setw(4) << "|" << setw(15) << " Cantidad"
         << setw(4) << "|" << setw(27) << " Porcentaje sobre el total" << setw(4) << "|" << endl;
    cout << setfill('~') << setw(70) << "" << setfill(' ') << endl;

    string nombres[8] = {S_HUMANO, S_VAMPIRO, S_ZOMBI, S_CRUZ, S_ESTACA, S_AGUA_BENDITA,
                         S_BALA , S_ESCOPETA};

    for (auto & nombre : nombres) {
        cout << "|" << setw(15) << nombre << setw(4) << "|" << setw(15);
        cout << this->tablero->obtener_existentes(nombre);
        cout << setw(4) << "|" << setw(20)
             << this->tablero->obtener_porcentaje(nombre)
             << setw(11) << "|" << endl;
        cout << setfill('~') << setw(70) << "" << setfill(' ') << endl;
    }
}


int Menu::obtener_opcion_elegida() {
    return this->opcion_elegida;
}

void Menu::buscar_por_cuadrante() {
    string nombre_objeto = this->usuario_pedir_objeto();
    if(!nombre_objeto.empty()){
        this->mostrar_tablero();
        CUADRANTE zona = this->usuario_pedir_cuadrante();
        bool objeto_encontrado = this->buscar_objeto_en_cuadrante(nombre_objeto, zona);
        if(!objeto_encontrado){
            cout << "El objeto no se encontro en el cuadrante" << endl;
        } else {
            cout << "<<<<Objeto hallado>>>>" << endl;
        }
    }

}

bool Menu::buscar_objeto_en_cuadrante(const string& nombre_objeto, CUADRANTE zona){
    Posicion pos_min;
    Posicion pos_max;
    bool encontrado;
    switch (zona) {
        case (NOROESTE):
            pos_min = Posicion(1, 1);
            pos_max = Posicion(this->tablero->cantidad_filas() / 2, this->tablero->cantidad_columnas() / 2);
            break;
        case (NORESTE):
            pos_min = Posicion((this->tablero->cantidad_filas() / 2) + 1, 1);
            pos_max = Posicion(this->tablero->cantidad_filas(), this->tablero->cantidad_columnas() / 2);
            break;
        case (SUROESTE):
            pos_min = Posicion(1, (this->tablero->cantidad_columnas() / 2) + 1);
            pos_max = Posicion(this->tablero->cantidad_filas() / 2, this->tablero->cantidad_columnas());
            break;
        case (SURESTE):
            pos_min = Posicion((this->tablero->cantidad_filas() / 2) + 1, (this->tablero->cantidad_columnas() / 2) + 1);
            pos_max = Posicion(this->tablero->cantidad_filas(), this->tablero->cantidad_columnas());
            break;
        default: throw Excepcion_error("Error, no se pudo encontrar un cuadrante valido!!");
    }
    encontrado = this->tablero->existe_objeto_en_cuadrante(nombre_objeto, pos_min, pos_max);
    return encontrado;
}


void Menu::dar_de_alta() {
    int fila, columna;
    this->pedir_posicion(fila, columna);
    bool opcion_aceptada = false;
    while(!opcion_aceptada){
        try {
            string nombre_obtenido = this->usuario_pedir_objeto();
            if(!nombre_obtenido.empty()){
                int cantidad = 1;
                if(nombre_obtenido == S_BALA || nombre_obtenido == S_AGUA_BENDITA){
                    cantidad = this->usuario_pedir_cantidad();
                }
                Objeto* nuevo_objeto = Parser(nombre_obtenido, cantidad).obtener_objeto();
                tablero->dar_de_alta(fila, columna, nuevo_objeto);
            }
            opcion_aceptada = true;
        } catch (Excepcion_error& e){
            cout << e.obtenerDescripcion() << endl;
            opcion_aceptada = false;
        }
    }
}

void Menu::dar_de_baja() {
    int fila, columna;
    this->pedir_posicion(fila, columna);
    Objeto* objeto_a_borrar = this->tablero->obtener_elemento_en_posicion(fila, columna);
    if(objeto_a_borrar != NULL){
        this->tablero->dar_de_baja(fila, columna);
    } else {
        cout << "No habia ningun elemento en la posicion ingresada" << endl;
    }
}

void Menu::buscar_por_posicion() {
    int fila, columna;
    this->pedir_posicion(fila, columna);

    Objeto* objeto_buscado = this->tablero->obtener_elemento_en_posicion(fila, columna);
    if(objeto_buscado){
        cout << "En la posicion se encontro: ";
        objeto_buscado->mostrar_informacion();
        cout << endl;
    } else {
        cout << "No hay nada en esta posicion" << endl;
    }
}

bool Menu::rango_valido(const std::string& texto_ingresado, int& fila, int& columna) {
    bool rango_es_valido = false;
    string primer_numero, segundo_numero;
    istringstream input(texto_ingresado);
    getline(input, primer_numero, ' ');
    getline(input, segundo_numero, ' ');

    if(es_un_numero(primer_numero) && es_un_numero(segundo_numero)){
        fila = stoi(primer_numero) - 1;
        columna = stoi(segundo_numero) - 1;
        rango_es_valido = this->tablero->posicion_valida(fila, columna);

    }
    return rango_es_valido;
}

bool Menu::es_un_numero(std::string texto) {
    bool es_un_numero = true;
    long unsigned i = 0;
    while(es_un_numero && i < texto.length()){
        es_un_numero = isdigit(texto[i]);
        i++;
    }
    return es_un_numero;
}

void Menu::pedir_posicion(int& fila, int& columna) {
    string texto_ingresado;
    cout << "Ingrese la posicion del objeto. MAX = " << this->tablero->cantidad_filas() << " "
                                                     << this->tablero->cantidad_columnas() << endl;
    cout << "Ejemplo: 10 5  --> fila 10 columna 5" << endl;
    cin.clear();
    cin.ignore(256, '\n');
    getline(cin, texto_ingresado);

    while(!this->rango_valido(texto_ingresado, fila, columna)){
        cout << "Las coordenadas ingresadas no estan dentro del rango del tablero, pruebe otra vez" << endl;
        getline(cin, texto_ingresado);
    }
}

Menu::~Menu() {
    delete this->tablero;
}

string Menu::usuario_pedir_objeto() {
    string objeto_elegido;
    cout << left <<  "En el mapa se hallan estas cosas: elija una " << endl
         << HUMANO  << ". " << setw(15) << S_HUMANO
         << HUMANO_CV << ". " << setw(15) << S_HUMANO_CV
         << ZOMBIE << ". " << setw(15) << S_ZOMBI << endl
         << VAMPIRO << ". " << setw(15) <<  S_VAMPIRO
         << VAMPIRELLA << ". " << setw(15) <<  S_VAMPIRELLA
         << NOSFERATU << ". " << setw(15) << S_NOSFERATU << endl
         << VANESA << ". " << setw(15)  << S_VANESA
         << AGUA_BENDITA << ". " << setw(15) << S_AGUA_BENDITA
         << CRUZ << ". " << setw(15) << S_CRUZ << endl
         << ESTACA << ". " << setw(15) << S_ESTACA
         << ESCOPETA << ". " << setw(15) << S_ESCOPETA
         << BALAS << ". " << setw(15) << S_BALA << endl;
    cout << 0 << ". " << setw(15) << "Salir" << endl;
    cout << "Elija una opcion: " << endl;

    int opcion_usuario;
    do {
        cin >> opcion_usuario;
        if(opcion_usuario < 0 || opcion_usuario > MAX_OBJETOS){
            cout << "Por favor, ingrese una opcion valida!! (" << "0, " << MAX_OBJETOS << ")" << endl;
        }
    } while (opcion_usuario < 0 || opcion_usuario > MAX_OBJETOS);
    if(opcion_usuario != 0){
        objeto_elegido = Parser(ENUM_OBJETOS(opcion_usuario)).obtener_nombre();
    }
    return objeto_elegido;
}

int Menu::usuario_pedir_cantidad() {
    string texto;
    int cantidad = 0;
    do{
        cout << "Ingrese la cantidad deseada" << endl;
        cin.clear();
        cin >> texto;
        if(this->es_un_numero(texto)){
            cantidad = stoi(texto);
        } else {
            cout << "Solo reingrese numeros" << endl;
        }
        if(cantidad <= 0){
            cout << "No se puede ingresar una cantidad menor a 1, ingrese denuevo la cantidad" << endl;
        }
    }while(cantidad <= 0);

    return cantidad;
}

CUADRANTE Menu::usuario_pedir_cuadrante() {
    cout << "Elija la zona donde quiere buscar cierto objeto" << endl
         << NOROESTE << " Zona Noroeste (NO)" << endl
         << NORESTE << " Zona Noreste (NE)" << endl
         << SUROESTE <<" Zona Suroeste (SO)" << endl
         << SURESTE <<" Zona Sureste (SE)" << endl;
    int opcion_ingresada;
    do {
        cin.clear();
        cin >> opcion_ingresada;
        if (opcion_ingresada < 1 || opcion_ingresada > 4) {
            cout << "Ingrese una opcion valida!" << endl;
        }
    } while (opcion_ingresada < 1 || opcion_ingresada > 4);
    CUADRANTE elegido = CUADRANTE(opcion_ingresada);
    return elegido;
}