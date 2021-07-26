#ifndef NOSFERATUV2_SER_H
#define NOSFERATUV2_SER_H

#include "../estructuras/grafo/grafo.h"

class Ser : public Objeto
{
private:
    /* Pre: camino no debe ser nullptr
    * Pos: Muestra por pantalla la secuencia de casilleros recorridos para llegar al destino
    */
    void mostrarCamino(vector<int>* camino);

    /* Pre: mapa no debe ser nullptr, origen y destino deben ser coordenadas validas
     * Pos: actualiza el mapa, dando de alta el objeto movido en el destino y dandolo de baja en el origen
     */
    void actualizarMapa(Grafo* mapa, Posicion origen, Posicion destino);
protected:
    int energia;
    int vida;
    int escudo;
    int fuerza;

public:
    /*
     * Post: Se crea el npc con la posicion Pos
     */
    explicit Ser(string nombre, char caracter, int id, int fila, int columna);

    int getEnergia();
    int getVida();
    int getEscudo();
    int getFuerza();

    void setEnergia(int e);
    void setVida(int v);
    void setEscudo(int e);
    void setFuerza(int f);

    //virtual void atacar(Tablero *tablero) = 0;
    // virtual void defender(Tablero *tablero);

    /*Pre: destino debe ser una coordenada valida y ademas, estar desocupada. mapa no debe ser nullptr
     * Pos: mueve el ser desde su posicion actual hasta el destino si es posible, yendo por el camino
     * que consuma menos energia. La posicion actual la deja como desocupada y el destino como ocupado.
     */
    void mover(Grafo *mapa, Posicion destino);

    /**
     * @brief Ajusta el danio pasado por referencia segun la cantidad de escudo del ser.
     * 
     * @param danio 
     */
    void ajustarDanio(int &danio);

    /**
     * @brief Retorna true si el ser tiene 0 de vida.
     */
    bool estaMuerto();

    /*
     * Post: Se muestra por pantalla la informacion del objeto: nombre
     */
    void mostrarInformacion() override;
};

#endif
