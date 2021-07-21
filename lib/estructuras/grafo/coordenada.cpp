#include "coordenada.h"

Coordenada::Coordenada(){
    fila = 0;
    columna = 0;
}

int Coordenada::get_fila() {
    return fila;
}

int Coordenada::get_columna() {
    return columna;
}

void Coordenada::set_fila(int n) {
    fila = n;
}

void Coordenada::set_columna(int n) {
    columna = n;
}

