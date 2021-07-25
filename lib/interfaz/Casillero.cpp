#include "../../src/main.h"

/* Construye un objeto de tipo Casillero, asignando los valores pasados por parametros a sus atributos
 * Tanto fila como columna debenser numeros positivos
 */
Casillero::Casillero(std::string tipo, std::string color, int fila, int columna)
{
    this->tipo = tipo;
    this->color = color;
    this->costo = 0;
    this->ocupado = false;
    this->coordenadas.cambiarFila(fila);
    this->coordenadas.cambiarColumna(columna);
    this->objeto = NULL;
}


/* Pos: Devuelve el color del casillero
 */
string Casillero::obtenerColor()
{
    return (this->color);
}

/* Pos: Devuelve de que tipo de terreno es el casillero
 */
string Casillero::obtenerTipo()
{
    return (this->tipo);
}

/* Devuelve el costo de pasar por el casillero, inicialmente es 0
 */
int Casillero::obtenerCosto()
{
    return (this->costo);
}


/* Pos: Devuelve la fila del casillero
 */
int Casillero::obtenerFila()
{
    return (this->coordenadas.getFila());
}


/* Pos: Devuelve la columna del casillero
 */
int Casillero::obtenerColumna()
{
    return (this->coordenadas.getColumna());
}

/* Pre: el nuevoObjeto no debe ser nullptr
 * Pos: Dado un puntero a objeto, asigna el mismo al puntero que el casillero tiene como atributo,
 * ademas, si el puntero es de algun Ser, marca el casillero como ocupado
 */
void Casillero::agregarObjeto(Objeto *nuevoObjeto) {
    this->objeto = nuevoObjeto;
    ID idObjeto = parseId(nuevoObjeto->getId());

    if(idObjeto == ID_HUMANO || idObjeto == ID_HUMANO_CV || idObjeto == ID_VANESA || idObjeto == ID_NOSFERATU || idObjeto == ID_VAMPIRELLA
    || idObjeto == ID_VAMPIRO || idObjeto == ID_ZOMBIE)
        this->ocupado = true;
}


/* Pos: Devuelve true si el casillero esta ocupado por un Ser o false si no lo esta
 * */
bool Casillero::estaOcupado()
{
    return ocupado;
}

/* Pos: Cambia el valor de ocupado por true
 */
void Casillero::ocupar()
{
    this->ocupado = true;
}

/* Pos: Cambia el valor de ocupado por false
 */
void Casillero::desocupar()
{
    this->ocupado = false;
}