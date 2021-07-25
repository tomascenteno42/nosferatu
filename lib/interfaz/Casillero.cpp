#include "../../src/main.h"

Casillero::Casillero(std::string tipo, std::string color, int fila, int columna)
{
    this->tipo = tipo;
    this->color = color;
    this->costo = 0;
    this->ocupado = false;
    this->coordenadas.cambiar_fila(fila);
    this->coordenadas.cambiar_columna(columna);
}

string Casillero::obtenerColor()
{
    return (this->color);
}

string Casillero::obtenerTipo()
{
    return (this->tipo);
}

int Casillero::obtenerCosto() {
    return (this->costo);
}

int Casillero::obtenerFila() {
    return (this->coordenadas.obtener_fila());
}

int Casillero::obtenerColumna() {
    return (this->coordenadas.obtener_columna());
}

bool Casillero::estaOcupado(){
    return ocupado;
}

void Casillero::ocupar(){
    this->ocupado = true;
}

void Casillero::desocupar(){
    this->ocupado = false;
}