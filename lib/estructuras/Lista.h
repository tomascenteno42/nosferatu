#include "../../src/main.h"

template <class T>
class Nodo;

template <class T>
class Lista
{
private:
    int cantidad;

    Nodo<T> *cabeza;
    Nodo<T> *cursor;
    Nodo<T> *cola;

public:
    /**
       Inicializa todos los atributos.
    */
    Lista();

    /**
     * @return La cantidad de elementos que contiene la lista.
    */
    int getCantidad();

    /**
     * Consulta el elemento de la lista en la posicion idx Consultate element in position pos of GenericList.
     * @param idx Posicion de la lista donde se desea obtener data. Debe ser igual o mayor que 1.
     * @return T Tipo de dato generico.
    */
    T get(int idx);

    /**
     * Inserta d al final de la lista e incrementa la cantidad 1.
     * @param d Data a agregar a la lista.
    */
    void alta(T d);

    /**
     * Inserta d en la posicion idx e incrementa la cantidad 1.
     * @param d Data a agregar a la lista.
     * @param idx Posicion donde d sera agregada. Debe ser igual o mayor que 1.
    */
    void alta(T d, int idx);

    /**
     * Elimina el ultimo elemento de la lista.
    */
    void baja();

    /**
     * Elimina el elemento de la lista en la posicion idx.
     * @param idx Posicion donde se eliminar el elemento de la lista. Debe ser igual o mayor que 1.
    */
    void baja(int idx);

    /**
     * Corrobora si la lista esta vacia, es decir si la cantidad de elementos es 0.
    */
    bool estaVacia();

    /**
     * Corrobora si existe un nodo siguiente a el nodo cursor.
    */
    bool haySiguienteNodo();

    /**
     * Limpia la lista.
    */
    virtual ~Lista();

    /**
     * Resetea el nodo cursor a la primera posicion, null en el caso de una lista vacia.
    */
    void reset();

    /**
     * Busca y retorna el nodo al que apunta el cursor.
     * @return Nodo cursor.
    */
    T getSiguiente();

private:
    /**
     * Busca un nodo en la posicion idx.
     * @param idx Posicion donde debe buscar el nodo.
     * @return Nodo en la posicion idx.
    */
    Nodo<T> *getNodo(int idx);
};

/* IMPLEMENTACION */

template <class T>
Lista<T>::Lista()
{
    cabeza = 0;
    cursor = 0;
    cola = 0;
    cantidad = 0;
}

template <class T>
void Lista<T>::alta(T d)
{
    Nodo<T> *nuevoNodo = new Nodo<T>(d);

    if (estaVacia())
    {
        nuevoNodo->setSiguienteNodo(cabeza);
        cabeza = nuevoNodo;
        cola = nuevoNodo;
    }
    else
    {
        cola->setSiguienteNodo(nuevoNodo);
        cola = nuevoNodo;
    }

    cantidad++;
}

template <class T>
void Lista<T>::alta(T d, int idx)
{
    Nodo<T> *nuevoNodo = new Nodo<T>(d);

    if (idx == 1)
    {
        nuevoNodo->setSiguienteNodo(cabeza);
        cabeza = nuevoNodo;
        cola = nuevoNodo;
    }
    else
    {
        Nodo<T> *anterior = getNodo(idx - 1);
        Nodo<T> *siguiente = anterior->getSiguienteNodo();

        nuevoNodo->setSiguienteNodo(siguiente);
        anterior->setSiguienteNodo(nuevoNodo);

        cola = nuevoNodo;
    }

    reset();

    cantidad++;
}

template <class T>
void Lista<T>::baja()
{

    if (!estaVacia())
    {
        Nodo<T> *anteriorACola = getNodo(cantidad - 1);

        cola = anteriorACola;

        delete anteriorACola->getSiguienteNodo();
        cantidad--;
    }

    reset();
}

template <class T>
void Lista<T>::baja(int idx)
{
    Nodo<T> *nodoAux;

    if (idx == 1)
    {
        nodoAux = cabeza;
        delete get(idx);

        cabeza = nodoAux->getSiguienteNodo();
    }
    else
    {
        Nodo<T> *anterior = getNodo(idx - 1);
        nodoAux = anterior->getSiguienteNodo();

        delete get(idx);

        Nodo<T> *siguiente = nodoAux->getSiguienteNodo();
        anterior->setSiguienteNodo(siguiente);
    }

    reset();
    cantidad--;
    delete nodoAux;
}

template <class T>
T Lista<T>::get(int idx)
{
    return getNodo(idx)->getData();
}

template <class T>
Nodo<T> *Lista<T>::getNodo(int idx)
{
    Nodo<T> *cursor = cabeza;
    for (int i = 1; i < idx; i++)
        cursor = cursor->getSiguienteNodo();

    return cursor;
}

template <class T>
bool Lista<T>::estaVacia()
{
    return cantidad == 0;
}

template <class T>
int Lista<T>::getCantidad()
{
    return cantidad;
}

template <class T>
Lista<T>::~Lista()
{
    while (!estaVacia())
    {
        baja(1);
    }
}

template <class T>
void Lista<T>::reset()
{
    cursor = cabeza;
}

template <class T>
bool Lista<T>::haySiguienteNodo()
{
    return cursor != 0;
}

template <class T>
T Lista<T>::getSiguiente()
{
    Nodo<T> *aux = cursor;
    cursor = cursor->getNextNode();
    return aux->getData();
}
