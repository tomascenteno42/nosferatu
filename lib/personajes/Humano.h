#ifndef NOSFERATUV2_HUMANO_H
#define NOSFERATUV2_HUMANO_H

#include "../../src/main.h"

class Juego;
class Tablero;

class Humano : public Ser
{
private:
    static int contador;
    int contadorTransformacion;

protected:
    bool contieneEscopeta = false;
    bool contieneAguas = false;
    bool contieneBalas = false;
    bool contieneEstaca = false;
    bool transformando = false;
    vector<Elemento *> inventario;

public:
    /*
     * Post: Se crea el humano con nombre = S_HUMANO y caracter C_HUMANO
     *       Aumenta en 1 la cantidad de humanos existentes
     */
    Humano(int id, int fila, int columna);

    /*
     * Post: Se crea un un humano con nombre = "nombre" y caracter "caracter"
     *       Aumenta en 1 la cantidad de humanos existentes
     */
    Humano(string nombre, char caracter, int id, int fila, int columna);

    /**
     * @brief Agrega el objeto pasado por parametro a el inventario.
     * 
     * @param objeto 
     */
    void agarrarObjeto(Elemento *objeto);

    void atacar(Juego *juego) override;

    bool enUnNumero(std::string texto);

    void pedirPosicion(int &fila, int &columna);

    /* Pos: Devuelve true si el inventario esta vacio o false si no lo esta
     */
    bool inventarioVacio();

    /* Pos: Muestra por pantalla el inventario del humano
     */
    void mostrarInventario();


    bool defender(Juego* juego) override;

    void modificarTransformacion(bool estado);

    bool seEstaTransformando();

    void actualizar() override;

    /*
     * Post: decrece en 1 la cantidad existentes de humanos
     */
    ~Humano() override;
};

#endif
