#include "vertice.h"

/* Pre: Terreno debe representar un tipo de terreno valido, fila y columna deben ser numeros positivos
 * Pos: Crea un objeto de tipo vertice, con terreno, fila y columna en sus atributos
 */
Vertice::Vertice(string terreno, int fila, int columna) {
    this->terreno = terreno;
    coordenadas.set_fila(fila);
    coordenadas.set_columna(columna);
    costo = 0;
}

/* Pos: Devuelve el valor del atributo costo
 */
int Vertice::get_costo() {
    return costo;
}

/* Pos: Devuelve la fila del vertice
 */
int Vertice::get_fila() {
    return (this->coordenadas.get_fila());
}

/* Pos: Devuelve la columna del vertice
 */
int Vertice::get_columna() {
    return (this->coordenadas.get_columna());
}

/* Pos: Devuelve el terreno
 */
string Vertice::get_terreno(){
    return terreno;
}

/* Pre: Recibe un string que debe representar algun personaje (humano, vampiro, zombi, etc)
 * Pos: De acuerdo al personaje y al tipo de terreno, ajusta el costo del vertice
 */
void Vertice::ajustar_costo(string tipo) {
    if(tipo == VANESA)
        tipo = CV;
    else if(tipo == NOSFERATU || tipo == VAMPIRELLA)
        tipo = VAMPIRO;

    if(tipo == HUMANO){
        if(terreno == MONTANIA || terreno == PRECIPICIO)
            costo = 2;
        else if(terreno == LAGO)
            costo = 0;
        else if(terreno == VOLCAN || terreno == CAMINO)
            costo = 1;
        else
            costo = 15;
    }
    else if(tipo == VAMPIRO){
        if(terreno == MONTANIA || terreno == LAGO || terreno == CAMINO)
            costo = 1;
        else if(terreno == PRECIPICIO)
            costo = 0;
        else if(terreno == VOLCAN)
            costo = 2;
        else
            costo = 15;
    }
    else if(tipo == ZOMBI){
        if(terreno == MONTANIA || terreno == PRECIPICIO || terreno == CAMINO)
            costo = 1;
        else if(terreno == LAGO)
            costo = 2;
        else if(terreno == VOLCAN)
            costo = 0;
        else
            costo = 15;
    }
    else if(tipo == CV){
        if(terreno == MONTANIA || terreno == LAGO)
            costo = 0;
        else if(terreno == PRECIPICIO)
            costo = 2;
        else if(terreno == VOLCAN || terreno == CAMINO)
            costo = 1;
        else
            costo = 15;
    }
}

