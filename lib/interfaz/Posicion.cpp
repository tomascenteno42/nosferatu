//
// Created by Lucas Williams on 13/06/2021.
//

#include "Posicion.h"

Posicion::Posicion(int fila, int columna) {
    this->fila = fila;
    this->columna = columna;
}

int Posicion::obtener_fila() {
    return this->fila;
}

int Posicion::obtener_columna() {
    return this->columna;
}

void Posicion::cambiar_fila(int nueva_fila) {
    this->fila = nueva_fila;
}

void Posicion::cambiar_columna(int nueva_columna) {
    this->columna = nueva_columna;
}

Posicion::Posicion() {
    this->columna = 0;
    this->fila = 0;
}
