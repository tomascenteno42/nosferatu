#ifndef TP3_BST_H
#define TP3_BST_H

#include <iostream>

#include "NodoABB.h"

template <class K, class T>
class NodoABB;

template <class K, class T>
class ABB
{
private:
    int cantidad;

    NodoABB<K, T> *raiz;

    /**
     * @brief Busca de forma recursiva el nodo con el valor mas chico y retorna su valor.
     * 
     * @param nodo 
     * @return T 
     */
    T buscarMinimo(NodoABB<K, T> *nodo);

    /**
     * @brief Busca de forma recursiva el nodo con el valor mas grande y retorna su valor.
     * 
     * @param nodo 
     * @return T 
     */
    T buscarMaximo(NodoABB<K, T> *nodo);

    /**
     * @brief 
     * 
     * @param nodo 
     * @return K 
     */
    K sucesor(NodoABB<K, T> *nodo);
    /**
     * @brief 
     * 
     * @param nodo 
     * @return K
     */
    K predecesor(NodoABB<K, T> *nodo);

    /**
     * @brief Busca el nodo por la clave de forma recursiva.
     * 
     * @param nodo 
     * @param clave 
     * @return NodoABB<K, T>* 
     */
    NodoABB<K, T> *buscar(NodoABB<K, T> *nodo, K clave);

    /**
     * @brief Inserta el nodo en su respectivo lugar con su clave y data.
     * 
     * @param nodo 
     * @param clave 
     * @param data 
     * @return NodoABB<K, T>* 
     */
    NodoABB<K, T> *insertar(K clave, T data, NodoABB<K, T> *nodo);

    void print_in_order(NodoABB<K, T> *node);
    NodoABB<K, T> *remove(NodoABB<K, T> *node, T data);

    void delete_all(NodoABB<K, T> *node);

public:
    /**
     * @brief Construye un arbol de busqueda binaria.
     * 
     */
    ABB();

    /**
     * @brief Busca el minimo nodo y retorna su valor.
     * 
     * @return T 
     */
    T buscarMinimo();

    /**
     * @brief Busca el maximo nodo y retorna su valor.
     * 
     * @return T 
     */
    T buscarMaximo();

    /**
     * @brief Busca el nodo por la clave. 
     * 
     * @param clave 
     * @return NodoABB<K, T>* 
     */
    NodoABB<K, T> *buscar(K clave);

    /**
     * @brief Busca el sucesor de un nodo dado un valor.
     * 
     * @param clave 
     * @return K 
     */
    K sucesor(K clave);

    /**
     * @brief Busca el predecesor de un nodo dado un valor.
     * 
     * @param clave
     * @return K
     */
    K predecesor(K clave);

    /**
     * @brief Crea un nuevo nodo con clave y data.
     * 
     * @param clave 
     * @param data 
     */
    void insertar(K clave, T data);

    /**
     * @brief Determinar si un nodo existe en el ABB. 
     * 
     * @param clave 
     * @return true 
     * @return false 
     */
    bool existe(K clave);

    /**
     * @brief Comprueba que el nodo raiz es null.
     */
    bool vacio();

    /**
     * @brief Destruye el arbol.
     * 
     */
    ~ABB();

    // Prints all the data stored in the BST, sorted from the
    // smallest value to the greatest value.
    void print_in_order();

    // Removes a given data from the BST
    void remove(T data);

    NodoABB<K, T> *get_raiz();

    // Deletes all the nodes in the BST
    void delete_all();
    ~BST<T>();
};

template <class K, class T>
ABB<K, T>::ABB()
{
    this->raiz = NULL;
    this->cantidad = 0;
}

template <class K, class T>
NodoABB<K, T> *ABB<K, T>::buscar(K clave)
{
    if (vacio())
        return NULL;

    return buscar(this->raiz, clave);
}

template <class K, class T>
NodoABB<K, T> *ABB<K, T>::buscar(NodoABB<K, T> *nodo, K clave)
{
    K claveAux = nodo->getClave();

    if (nodo && clave < claveAux)
    {
        buscar(nodo->getIzquierdo(), clave);
    }

    if (nodo && clave > claveAux)
    {
        buscar(nodo->getDerecho(), clave);
    }

    return nodo;
}

template <class K, class T>
T ABB<K, T>::buscarMinimo()
{
    if (vacio())
    {
        return -1;
    }

    return buscarMinimo(this->raiz);
}

template <class K, class T>
T ABB<K, T>::buscarMinimo(NodoABB<K, T> *nodo)
{
    NodoABB<K, T> *nodoIzquierdo = nodo->getIzquierdo();

    if (nodoIzquierdo)
    {
        buscarMinimo(nodoIzquierdo);
    }

    return nodo->getData();
}

template <class K, class T>
T ABB<K, T>::buscarMaximo()
{
    if (vacio())
    {
        return -1;
    }

    return buscarMaximo(this->raiz);
}

template <class K, class T>
T ABB<K, T>::buscarMaximo(NodoABB<K, T> *nodo)
{
    NodoABB<K, T> *nodoDerecho = nodo->getDerecho();

    if (nodoDerecho)
    {
        buscarMaximo(nodoDerecho);
    }

    return nodo->getData();
}

template <class K, class T>
K ABB<K, T>::predecesor(K clave)
{
    if (vacio())
        return NULL;

    return predecesor(buscar(this->raiz, clave));
}

template <class K, class T>
K ABB<K, T>::predecesor(NodoABB<K, T> *nodo)
{

    if (!nodo || nodo->getClave() == buscarMinimo())
        return NULL;

    if (nodo->getIzquierdo())
        return buscarMaximo(nodo->getIzquierdo());

    K clave = nodo->getClave();

    NodoABB<K, T> *ancestro = nodo->getPadre();

    while (clave <= ancestro->getClave())
        ancestro = ancestro->getPadre();

    return ancestro->getClave();
}

template <class K, class T>
K ABB<K, T>::sucesor(K clave)
{
    if (vacio())
        return NULL;

    return sucesor(buscar(clave, this->raiz));
}

template <class K, class T>
K ABB<K, T>::sucesor(NodoABB<K, T> *nodo)
{
    if (!nodo || nodo->getClave() == buscarMaximo())
        return NULL;

    if (nodo->getDerecho())
        return buscarMinimo(nodo->getDerecho());

    K clave = nodo->getClave();

    NodoABB<K, T> *ancestro = nodo->getPadre();

    while (clave >= ancestro->getClave())
        ancestro = ancestro->getPadre();

    return ancestro->getClave();
}

template <class K, class T>
void ABB<K, T>::insertar(K clave, T data)
{
    //TODO: CHECK THIS (vacio())
    if (vacio() || !existe(clave))
    {
        this->raiz = insertar(clave, data, this->raiz);
        this->cantidad++;
    }
}

template <class K, class T>
NodoABB<K, T> *ABB<K, T>::insertar(K clave, T data, NodoABB<K, T> *nodo)
{
    if (!nodo)
    {
        nodo = new NodoABB<K, T>(clave, data);
    }
    else if (clave < nodo->getClave())
    {
        nodo->setIzquierdo(insertar(clave, data, nodo->getIzquierdo()));
    }
    else
    {
        nodo->setDerecho(insertar(clave, data, nodo->getDerecho()));
    }

    return nodo;
}

template <class K, class T>
bool ABB<K, T>::existe(K clave)
{
    return buscar(clave) != NULL;
}

template <class K, class T>
bool ABB<K, T>::vacio()
{
    return this->cantidad == 0;
}

template <class K, class T>
ABB<K, T>::~ABB()
{
}

template <class T>
void BST<T>::print_in_order(NodoABB<K, T> *node)
{
    if (node != NULL)
    {
        print_in_order(node->get_left());
        std::cout << node->get_data() << ' ';
        print_in_order(node->get_right());
    }
}

template <class T>
void BST<T>::print_in_order()
{
    this->print_in_order(this->raiz);
}

template <class T>
NodoABB<K, T> *BST<T>::remove(NodoABB<K, T> *node, T data)
{
    // The given node is not found in BST
    if (node == NULL)
        return NULL;

    if (node->get_data() == data)
    {
        if (node->isLeaf())
            delete node;
        else if (node->rightChildOnly())
        {
            // The only child will be connected to the parent's of node directly
            node->get_right()->set_parent(node->get_parent());
            // Bypass node
            NodoABB<K, T> *aux = node;
            node = node->get_right();
            delete aux;
        }
        else if (node->leftChildOnly())
        {
            // The only child will be connected to the parent's of node directly
            node->get_left()->set_parent(node->get_parent());
            // Bypass node
            NodoABB<K, T> *aux = node;
            node = node->get_left();
            delete aux;
        }

        // The node has two children (left and right)
        else
        {
            // Find successor or predecessor to avoid quarrel
            T successor_data = this->successor(data);

            // Replace node's key with successor's key
            node->set_data(successor_data);

            // Delete the old successor's key
            node->set_right(remove(node->get_right(), successor_data));
        }
    }

    else if (node->get_data() < data)
        node->set_right(remove(node->get_right(), data));

    else
        node->set_left(remove(node->get_left(), data));

    return node;
}

template <class T>
void BST<T>::remove(T data)
{
    this->raiz = remove(this->raiz, data);
}

template <class T>
void BST<T>::delete_all(NodoABB<K, T> *node)
{
    if (node == NULL)
        return;
    this->delete_all(node->get_left());
    this->delete_all(node->get_right());
    delete node;
}

template <class T>
void BST<T>::delete_all()
{
    this->delete_all(this->raiz);
}

template <class T>
BST<T>::~BST<T>()
{
    this->delete_all();
}

#endif //TP3_BST_H
