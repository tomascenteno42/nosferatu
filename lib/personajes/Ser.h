#ifndef NOSFERATUV2_SER_H
#define NOSFERATUV2_SER_H

#include "../../src/main.h"

class Ser : public Objeto
{
protected:
    int energia;
    int vida;
    int escudo;
    int fuerza;

public:
    /*
     * Post: Se crea el npc con la posicion Pos
     */
    explicit Ser(std::string nombre, char caracter);

    int getEnergia();
    int getVida();
    int getEscudo();
    int getFuerza();

    void setEnergia(int e);
    void setVida(int v);
    void setEscudo(int e);
    void setFuerza(int f);

    // virtual void atacar(Tablero *tablero);
    // virtual void defender(Tablero *tablero);
    // virtual void mover(Tablero *tablero);

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
    void mostrar_informacion() override;
};

#endif
