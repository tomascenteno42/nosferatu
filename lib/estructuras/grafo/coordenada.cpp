#include "coordenada.h"

/* Crea un objeto de tipo Coordenada
 * */
Coordenada::Coordenada(){
    fila = 0;
    columna = 0;
}

/* Pos: Devuelve la fila
 */
int Coordenada::get_fila() {
    return fila;
}

/* Pos: Devuelve la columna
 */
int Coordenada::get_columna() {
    return columna;
}

/* Pre: n debe ser un numero positivo
 * Pos: Asigna n al atributo fila
 */
void Coordenada::set_fila(int n) {
    fila = n;
}

/* Pre: n debe ser un numero positivo
 * Pos: Asigna n al atributo columna
 */
void Coordenada::set_columna(int n) {
    columna = n;
}

