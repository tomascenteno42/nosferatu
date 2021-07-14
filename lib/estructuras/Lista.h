#include "Nodo.h"

template <class T>
class Nodo;

template <class T>
class Lista
{
private:
  //FIXME: no se sobre este nombre
  Nodo<T> *cabeza;
  Nodo<T> *cursor;
  Nodo<T> *cola;
  int cantidad;

public:
  Lista();
  int getCantidad();

  T obtener(int idx);

  void alta(T d);
  void alta(T d, int idx);

  void baja();
  void baja(int idx);

  bool estaVacia();
  bool haySiguienteNodo();

  virtual ~Lista();

  void reset();

  T getSiguiente();

private:
  Nodo<T> *getNodo(int idx);
};

//IMPLEMENTACION
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
    // delete obtener(idx);
    cabeza = nodoAux->getSiguienteNodo();
  }
  else
  {
    Nodo<T> *anterior = getNodo(idx - 1);

    nodoAux = anterior->getSiguienteNodo();
    //TODO: Checkear si es suficiente con eliminar el nodoAux que apunta ya a la posicion a eliminar
    //TODO: o si hace falta hacer un delete en esa posicion igual. No me queda claro que onda los punteros.
    // delete obtener(idx);
    Nodo<T> *siguiente = nodoAux->getSiguienteNodo();

    anterior->setSiguienteNodo(siguiente);
  }

  reset();
  cantidad--;
  delete nodoAux;
}

template <class T>
T Lista<T>::obtener(int idx)
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
