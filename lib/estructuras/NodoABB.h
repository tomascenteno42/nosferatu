#ifndef TP3_NodoABB_H
#define TP3_NodoABB_H

#include "../../src/main.h"

template <class K, class T>
class NodoABB
{

private:
    // Atributos
    K id;
    T data;
    NodoABB<K, T> *derecho;
    NodoABB<K, T> *izquierdo;
    NodoABB<K, T> *padre;

public:
    // Metodos
    NodoABB(K id, T data);

    void setData(T data);
    void setId(K id);
    T getData();
    K getId();

    void setDerecho(NodoABB<K, T> *derecho);
    NodoABB<K, T> *getDerecho();

    void setIzquierdo(NodoABB<K, T> *izquierdo);
    NodoABB<K, T> *getIzquierdo();

    void setPadre(NodoABB<K, T> *padre);
    NodoABB<K, T> *getPadre();

    bool esHoja();
    bool soloHijoDerecho();
    bool soloHijoIzquierdo();

    ~NodoABB();
};

// -------------- IMPLEMENTATION -----------------

template <class K, class T>
NodoABB<K, T>::NodoABB(K id, T data)
{
    this->data = data;
    this->id = id;
    this->derecho = 0;
    this->izquierdo = 0;
    this->padre = 0;
}

template <class K, class T>
void NodoABB<K, T>::setData(T data)
{
    this->data = data;
}

template <class K, class T>
void NodoABB<K, T>::setId(K id)
{
    this->id = id;
}

template <class K, class T>
T NodoABB<K, T>::getData()
{
    return data;
}

template <class K, class T>
K NodoABB<K, T>::getId()
{
    return id;
}

template <class K, class T>
void NodoABB<K, T>::setIzquierdo(NodoABB<K, T> *izquierdo)
{
    this->izquierdo = izquierdo;

    if (izquierdo)
        izquierdo->setPadre(this);
}

template <class K, class T>
NodoABB<K, T> *NodoABB<K, T>::getIzquierdo()
{
    return this->izquierdo;
}

template <class K, class T>
void NodoABB<K, T>::setDerecho(NodoABB<K, T> *derecho)
{
    this->derecho = derecho;

    if (derecho)
        derecho->setPadre(this);
}

template <class K, class T>
NodoABB<K, T> *NodoABB<K, T>::getDerecho()
{
    return derecho;
}

template <class K, class T>
void NodoABB<K, T>::setPadre(NodoABB<K, T> *padre)
{
    this->padre = padre;
}

template <class K, class T>
NodoABB<K, T> *NodoABB<K, T>::getPadre()
{
    return padre;
}

template <class K, class T>
bool NodoABB<K, T>::esHoja()
{
    return (getIzquierdo() == 0 && getDerecho() == 0);
}

template <class K, class T>
bool NodoABB<K, T>::soloHijoDerecho()
{
    return (getIzquierdo() == 0 && getDerecho() != 0);
}

template <class K, class T>
bool NodoABB<K, T>::soloHijoIzquierdo()
{
    return (getIzquierdo() != 0 && getDerecho() == 0);
}

template <class K, class T>
NodoABB<K, T>::~NodoABB()
{
    delete data;
}

#endif //TP3_NodoABB_H
