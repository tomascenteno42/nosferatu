#ifndef NOSFERATUV2_SER_H
#define NOSFERATUV2_SER_H

#include "../../src/main.h"

class Grafo;
class Tablero;
class Juego;

class Ser : public Objeto
{
private:
    /* Pre: mapa no debe ser nullptr, origen y destino deben ser coordenadas validas
     * Pos: actualiza el mapa, dando de alta el objeto movido en el destino y dandolo de baja en el origen
     */
    void actualizarMapa(Grafo *mapa, Posicion origen, Posicion destino);

    /* Pre: mapa y camino no deben ser nullptr, nombre debe ser un nombre valido
     * Pos: Dado un camino, analiza casillero por casillero que hacer con el objeto que habia alli, dependiendo del personaje
     */
    void chequearCamino(Grafo *mapa, vector<int> *camino, string nombre);

    /* Pre: mapa, posiciones y ser no deben ser nullptr
     * Pos: Imprime por pantalla el camino tomado por el personaje
     * */
    void imprimirCamino(Grafo *mapa, vector<Posicion> *posiciones, Ser *ser);

protected:
    int energia;
    int vida;
    int escudo;
    int fuerza;
    int contadorTurnos;

    bool seDefendio;

public:
    Ser() : Objeto(){};
    /*
     * Post: Se crea el npc con la posicion Pos
     */
    explicit Ser(string nombre, char caracter, int id, int fila, int columna);

    /* Pos: Devuelve la energia
     */
    int getEnergia();

    /* Pos: Devuelve la vida
     */
    int getVida();

    /* Pos: Devuelve el escudo
     */
    int getEscudo();

    /* Pos: Devuelve la fuerza
     */
    int getFuerza();

    /* Pre: e debe ser un numero positivo dentro del rango
     * Pos: establece la energia como e
     */
    void setEnergia(int e);

    /* Pre: v debe ser un numero positivo dentro del rango
     * Pos: establece la vida como v
     */
    void setVida(int v);

    /* Pre: e debe ser un numero positivo dentro del rango
     * Pos: establece el escudo como e
     */
    void setEscudo(int e);

    /* Pre: f debe ser un numero positivo dentro del rango
     * Pos: establece la fuerza como f
     */
    void setFuerza(int f);

    //virtual void atacar(Tablero *tablero) = 0;

    virtual bool defender(Juego *juego) = 0;

    virtual void actualizar() = 0;

    virtual void atacar(Juego *juego) = 0;

    /*Pre: destino debe ser una coordenada valida y ademas, estar desocupada. mapa no debe ser nullptr
     * Pos: mueve el ser desde su posicion actual hasta el destino si es posible, yendo por el camino
     * que consuma menos energia. La posicion actual la deja como desocupada y el destino como ocupado.
     * Devuelve true si el ser se movio y false si no.
     */
    bool mover(Grafo *mapa, Posicion destino);

    /**
     * @brief Ajusta el danio pasado por referencia segun la cantidad de escudo del ser.
     * 
     * @param danio 
     */
    void ajustarDanio(int &danio, int escudo);

    /**
     * @brief Retorna true si el ser tiene 0 de vida.
     */
    bool estaMuerto();


    /* Pre: Devuelve true si el ser se esta defendiendo o false si no lo esta
     * */
    bool seEstaDefendiendo();

    /*
     * Post: Se muestra por pantalla la informacion del objeto: nombre
     */
    void mostrarInformacion() override;
};

#endif
