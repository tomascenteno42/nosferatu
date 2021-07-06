#include "Tablero.h"

using namespace std;

Tablero::Tablero(const std::string& dir) {
    fstream archivo(dir, ios::in);
    if(!archivo){
        throw invalid_argument("Error: no se puede abrir el archivo");
    } else {
        this->contador = new Contador();
        string linea, s_filas, s_columnas;
        getline(archivo, s_filas, ' ');
        getline(archivo, s_columnas);
        this->cant_filas = stoi(s_filas);
        this->cant_columnas = stoi(s_columnas);
        this->inicializar_matriz();
        while(getline(archivo, linea)){
            Parser texto(linea);
            int fila = texto.obtener_posicion()->obtener_fila()-1;
            int columna = texto.obtener_posicion()->obtener_columna()-1;
            this->objetos[fila][columna] = texto.obtener_objeto();
        }
    }
}

void Tablero::inicializar_matriz(){
    this->objetos = new Objeto**[this->cantidad_filas()];
    for(int i = 0; i < this->cantidad_filas(); i++){
        this->objetos[i] = new Objeto*[this->cantidad_columnas()];
        for(int j = 0; j < this->cantidad_columnas(); j++){
            this->objetos[i][j] = NULL;
        }
    }
}


bool Tablero::posicion_valida(int fila, int columna) {
    return (fila >= 0 && columna >= 0 && fila < this->cantidad_filas() && columna < this->cantidad_columnas());
}

void Tablero::dar_de_baja(int fila, int columna) {
    if(this->posicion_valida(fila, columna)){
        delete this->objetos[fila][columna];
        this->objetos[fila][columna] = NULL;
    }

}

Objeto *Tablero::obtener_elemento_en_posicion(int fila, int columna) {
    return this->objetos[fila][columna];
}


int Tablero::cantidad_filas() {
    return this->cant_filas;
}

int Tablero::cantidad_columnas() {
    return this->cant_columnas;
}

void Tablero::dar_de_alta(int fila, int columna, Objeto *nuevo_objeto) {
    if(this->objetos[fila][columna] == NULL){
        this->objetos[fila][columna] = nuevo_objeto;
    } else {
        delete this->objetos[fila][columna];
        this->objetos[fila][columna] = nuevo_objeto;
    }
}

int Tablero::obtener_existentes(const std::string& nombre) {
    return contador->obtener_cantidad_existentes(nombre);
}

float Tablero::obtener_porcentaje(const string &nombre) {
    return this->contador->obtener_porcentaje(nombre);
}

bool Tablero::existe_objeto_en_cuadrante(const string& buscado, Posicion pos_min, Posicion pos_max) {
    bool objeto_hallado = false;
    int i = pos_min.obtener_fila() - 1;
    int j = pos_min.obtener_columna() - 1;
    while(!objeto_hallado && i < pos_max.obtener_fila()){
        while(!objeto_hallado && j < pos_max.obtener_columna()){
            if(this->objetos[i][j] != NULL){
                objeto_hallado = this->comparar_objetos(buscado, this->objetos[i][j]->obtener_nombre());
            }
            j++;
        }
        i++;
    }
    return objeto_hallado;
}

bool Tablero::comparar_objetos(const string& buscado, const string& hallado){
    bool objeto_hallado = false;
    objeto_hallado = buscado == hallado;
    if(!objeto_hallado && buscado == S_VAMPIRO){
        objeto_hallado = hallado == S_VAMPIRO || hallado == S_NOSFERATU;
    } else if(!objeto_hallado && buscado == S_HUMANO){
        objeto_hallado = hallado == S_HUMANO_CV || hallado == S_VANESA;
    }
    return objeto_hallado;
}



Tablero::~Tablero() {
    for(int i = 0; i < this->cantidad_filas(); i++){
        for(int j = 0; j < this->cantidad_columnas(); j++){
            if(this->objetos[i][j] != NULL){
                delete this->objetos[i][j];
            }
        }
        delete[] objetos[i];
    }
    delete[] objetos;
    delete contador;
}


