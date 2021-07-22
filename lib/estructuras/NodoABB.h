#ifndef TP3_NodoABB_H
#define TP3_NodoABB_H

#include "../../src/main.h"

template <class K, class T>
class NodoABB
{
private:
    K clave;
    T data;
    NodoABB<K, T> *padre;
    NodoABB<K, T> *izquierdo;
    NodoABB<K, T> *derecho;

public:
    /**
     * @brief Construye un nuevo nodo.
     * 
     * @param k clave
     * @param d dato
     */
    NodoABB(K k, T d);

    /**
    * @brief Devuelve la data del nodo.
    * 
    * @return T 
    */
    T getData();

    /**
    * @brief Devuelve la clave del nodo.
    * 
    * @return K
    */
    K getClave();

    /**
     * @brief Devuelve el nodo derecho
     * 
     * @return NodoABB<K, T>* 
     */
    NodoABB<K, T> *getDerecho();

    /**
     * @brief Devuelve el nodo izquierdo
     * 
     * @return NodoABB<K, T>* 
     */
    NodoABB<K, T> *getIzquierdo();

    /**
     * @brief Devuelve el nodo padre
     * 
     * @return NodoABB<K, T>* 
     */
    NodoABB<K, T> *getPadre();

    /**
     * @brief Establece la data del nodo.
     * 
     * @param data 
     */
    void setData(T data);

    /**
     * @brief Establece la clave del nodo.
     * 
     * @param clave 
     */
    void setClave(K clave);

    /**
     * @brief Establece el nodo izquierdo
     * 
     * @param nodoIzquierdo 
     */
    void setIzquierdo(NodoABB<K, T> *nodoIzquierdo);

    /**
     * @brief Establece el nodo izquierdo y el nodo padre.
     * 
     * @param nodoIzquierdo 
     * @param nodoPadre 
     */
    void setIzquierdo(NodoABB<K, T> *nodoIzquierdo, NodoABB<K, T> *nodoPadre);

    /**
     * @brief Establece el nodo derecho
     * 
     * @param nodoDerecho 
     */
    void setDerecho(NodoABB<K, T> *nodoDerecho);

    /**
     * @brief Establece el nodo derecho y el nodo padre.
     * 
     * @param nodoDerecho 
     * @param nodoPadre 
     */
    void setDerecho(NodoABB<K, T> *nodoDerecho, NodoABB<K, T> *nodoPadre);

    /**
     * @brief Establece el nodo padre
     * 
     * @param nodoPadre 
     */
    void setPadre(NodoABB<K, T> *nodoPadre);

    /**
     * @brief Evalua si el hijo izquierdo y el derecho existen.
     * 
     * @return true si el hijo izquierdo y el derecho apunta a null. 
     */
    bool esHoja();

    /**
     * @brief Evalua si el nodo solo tiene un hijo derecho.
     * 
     * @return true si el hijo izquierdo apunta a null y el derecho no. 
     */
    bool tieneSoloHijoDerecho();

    /**
     * @brief Evalua si el nodo solo tiene un hijo izquierdo.
     * 
     * @return true si el hijo derecho apunta a null y el izquierdo no. 
     */
    bool tieneSoloHijoIzquierdo();

    /**
     * @brief Destructor del nodo ABB
     * 
     */
    ~NodoABB();
};

template <class K, class T>
NodoABB<K, T>::NodoABB(K k, T d)
{
    this->clave = k;
    this->data = d;
    this->left = NULL;
    this->right = NULL;
    this->parent = NULL;
}

template <class K, class T>
T NodoABB<K, T>::getData()
{
    return this->data;
}

template <class K, class T>
K NodoABB<K, T>::getClave()
{
    return this->clave;
}

template <class K, class T>
NodoABB<K, T> *NodoABB<K, T>::getDerecho()
{
    return this->derecho;
}

template <class K, class T>
NodoABB<K, T> *NodoABB<K, T>::getIzquierdo()
{
    return this->izquierdo;
}

template <class K, class T>
NodoABB<K, T> *NodoABB<K, T>::getPadre()
{
    return this->padre;
}

template <class K, class T>
void NodoABB<K, T>::setData(T data)
{
    this->data = data;
}

template <class K, class T>
void NodoABB<K, T>::setClave(K clave)
{
    this->clave = clave;
}

template <class K, class T>
void NodoABB<K, T>::setDerecho(NodoABB<K, T> *nodoDerecho)
{
    this->derecho = nodoDerecho;
}

template <class K, class T>
void NodoABB<K, T>::setDerecho(NodoABB<K, T> *nodoDerecho, NodoABB<K, T> *nodoPadre)
{
    this->derecho = nodoDerecho;
    this->padre = nodoPadre;
}

template <class K, class T>
void NodoABB<K, T>::setIzquierdo(NodoABB<K, T> *nodoIzquierdo)
{
    this->izquierdo = nodoIzquierdo;
}

template <class K, class T>
void NodoABB<K, T>::setIzquierdo(NodoABB<K, T> *nodoIzquierdo, NodoABB<K, T> *nodoPadre)
{
    this->izquierdo = izquierdo;
    this->padre = nodoPadre;
}

template <class K, class T>
void NodoABB<K, T>::setPadre(NodoABB<K, T> *nodoPadre)
{
    this->padre = nodoPadre;
}

template <class K, class T>
bool NodoABB<K, T>::esHoja()
{

    return (this->izquierdo == 0 && this->derecho == 0);
}

template <class K, class T>
bool NodoABB<K, T>::tieneSoloHijoDerecho()
{

    return (this->izquierdo == 0 && this->derecho != 0);
}

template <class K, class T>
bool NodoABB<K, T>::tieneSoloHijoIzquierdo()
{

    return (this->izquierdo != 0 && this->derecho == 0);
}

template <class K, class T>
NodoABB<K, T>::~NodoABB()
{
    delete data;
}

#endif //TP3_NodoABB_H
