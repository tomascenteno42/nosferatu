#ifndef MENU_H_
#define MENU_H_

#include "../../src/main.h"

class Menu
{
private:
    string *opciones;
    int index = 0;
    int cantidad = 0;

public:
    Menu(int cantidad);

    Menu(const Menu &L);            // copy constructor
    Menu &operator=(const Menu &L); // assignment

    string getOpcion(int idx);
    int getCantidad();

    /**
     * @brief Agrega una opcion al menu.
     * 
     * @param opcion 
     */
    void alta(string opcion);

    ~Menu();
};

#endif