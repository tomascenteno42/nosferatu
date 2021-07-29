#ifndef TP3_ABB_H
#define TP3_ABB_H

#include "../../src/main.h"

template <class K, class T>
class ABB
{
private:
    NodoABB<K, T> *raiz;
    int cantidad;

    NodoABB<K, T> *insertar(K id, T data, NodoABB<K, T> *nodo);
    NodoABB<K, T> *buscar(K id, NodoABB<K, T> *nodo);
    NodoABB<K, T> *eliminar(K id, NodoABB<K, T> *nodo);

    K buscarMinimo(NodoABB<K, T> *nodo);
    K buscarMaximo(NodoABB<K, T> *nodo);
    K sucesor(NodoABB<K, T> *nodo);
    K predecesor(NodoABB<K, T> *nodo);

    void imprimirEnOrden(NodoABB<K, T> *nodo);
    void clavesEnOrden(NodoABB<K, T> *nodo, std::vector<K> &claves);

    void eliminarTodo(NodoABB<K, T> *nodo);

public:
    ABB();

    // Inserts element in tree (id, data)
    void insertar(K id, T data);
    bool buscar(K id);
    void eliminar(K id);

    int getCantidad();
    K buscarMinimo();
    K buscarMaximo();
    K sucesor(K id);
    K predecesor(K id);

    T getData(K id);
    NodoABB<K, T> *getRaiz();

    void imprimirEnOrden();
    std::vector<K> clavesEnOrden();

    void eliminarTodo();

    bool existe(K id);

    ~ABB();
};

template <class K, class T>
ABB<K, T>::ABB()
{
    raiz = 0;
    cantidad = 0;
}
template <class K, class T>
bool ABB<K, T>::existe(K id)
{
    return buscar(id, this->raiz) != NULL;
}

template <class K, class T>
NodoABB<K, T> *ABB<K, T>::insertar(K id, T data, NodoABB<K, T> *nodo)
{
    if (nodo == 0)
        nodo = new NodoABB<K, T>(id, data);
    else if (id < nodo->getId())
        nodo->setIzquierdo(insertar(id, data, nodo->getIzquierdo()));
    else
        nodo->setDerecho(insertar(id, data, nodo->getDerecho()));

    return nodo;
}

template <class K, class T>
void ABB<K, T>::insertar(K id, T data)
{
    if (!buscar(id))
    {
        raiz = insertar(id, data, raiz);
        cantidad++;
    }
}

template <class K, class T>
NodoABB<K, T> *ABB<K, T>::buscar(K id, NodoABB<K, T> *nodo)
{
    if (nodo && id < nodo->getId())
        nodo = buscar(id, nodo->getIzquierdo());
    if (nodo && id > nodo->getId())
        nodo = buscar(id, nodo->getDerecho());

    return nodo;
}

template <class K, class T>
bool ABB<K, T>::buscar(K id)
{
    return (buscar(id, raiz) != 0);
}

template <class K, class T>
NodoABB<K, T> *ABB<K, T>::eliminar(K id, NodoABB<K, T> *nodo)
{
    if (!nodo)
    {
    }

    else if (id < nodo->getId())
    {
        nodo->setIzquierdo(eliminar(id, nodo->getIzquierdo()));
        cantidad--;
    }
    else if (id > nodo->getId())
    {
        nodo->setDerecho(eliminar(id, nodo->getDerecho()));
        cantidad--;
    }
    else
    {
        if (nodo->esHoja())
        {
            delete nodo;
            nodo = 0;
        }
        else if (nodo->soloHijoDerecho())
        {
            nodo->getDerecho()->setPadre(nodo->getPadre());
            NodoABB<K, T> *aux = nodo->getDerecho();
            delete nodo;
            nodo = aux;
        }
        else if (nodo->soloHijoIzquierdo())
        {
            nodo->getIzquierdo()->setPadre(nodo->getPadre());
            NodoABB<K, T> *aux = nodo->getIzquierdo();
            delete nodo;
            nodo = aux;
        }
        else
        {
            K replacement;
            if (buscar(sucesor(id)))
                replacement = buscar(sucesor(id), raiz)->getId();
            else
                replacement = buscar(predecesor(id), raiz)->getId();
            T newData = getData(replacement);
            raiz = eliminar(replacement, raiz);
            nodo->setData(newData);
            nodo->setId(replacement);
        }
        cantidad--;
    }
    return nodo;
}

template <class K, class T>
void ABB<K, T>::eliminar(K id)
{
    if (buscar(id))
        raiz = eliminar(id, raiz);
    else
        std::cout << "The tree does not contain specified data" << endl;
}

template <class K, class T>
int ABB<K, T>::getCantidad()
{
    return cantidad;
}

template <class K, class T>
K ABB<K, T>::buscarMinimo(NodoABB<K, T> *nodo)
{
    if (nodo->getIzquierdo())
        return buscarMinimo(nodo->getIzquierdo());
    else
        return nodo->getId();
}

template <class K, class T>
K ABB<K, T>::buscarMinimo()
{
    if (raiz)
        return buscarMinimo(raiz);
    else
        return -1;
}

template <class K, class T>
K ABB<K, T>::buscarMaximo(NodoABB<K, T> *nodo)
{
    if (nodo->getDerecho())
        return buscarMaximo(nodo->getDerecho());
    else
        return nodo->getId();
}

template <class K, class T>
K ABB<K, T>::buscarMaximo()
{
    if (raiz)
        return buscarMaximo(raiz);
    else
        return -1;
}

template <class K, class T>
K ABB<K, T>::sucesor(NodoABB<K, T> *nodo)
{
    K outcome;

    if (nodo->getId() == buscarMaximo()) // nodo has no sucesor
        outcome = -1;
    else if (nodo->getDerecho())
        outcome = buscarMinimo(nodo->getDerecho());
    else
    {
        T data = nodo->getData();
        NodoABB<K, T> *ancestor = nodo->getPadre();
        while (data >= ancestor->getData())
            ancestor = ancestor->getPadre();
        outcome = ancestor->getId();
    }
    return outcome;
}

template <class K, class T>
K ABB<K, T>::sucesor(K id)
{
    NodoABB<K, T> *nodo = buscar(id, raiz);

    if (nodo)
        return sucesor(nodo);
    else
        return -1;
}

template <class K, class T>
K ABB<K, T>::predecesor(NodoABB<K, T> *nodo)
{
    K outcome;
    if (nodo->getId() == buscarMinimo()) // nodo has no predecesor
        outcome = -1;
    else if (nodo->getIzquierdo())
        outcome = buscarMaximo(nodo->getIzquierdo());
    else
    {
        T data = nodo->getData();
        NodoABB<K, T> *ancestor = nodo->getPadre();
        while (data <= ancestor->getData())
            ancestor = ancestor->getPadre();
        outcome = ancestor->getId();
    }
    return outcome;
}

template <class K, class T>
K ABB<K, T>::predecesor(K id)
{
    NodoABB<K, T> *nodo = buscar(id, raiz);

    if (nodo)
        return predecesor(nodo);
    else
        return -1;
}

template <class K, class T>
T ABB<K, T>::getData(K id)
{
    NodoABB<K, T> *nodo = buscar(id, raiz);
    T data = nodo->getData();
    return data;
}

template <class K, class T>
NodoABB<K, T> *ABB<K, T>::getRaiz()
{
    return raiz;
}

template <class K, class T>
void ABB<K, T>::imprimirEnOrden(NodoABB<K, T> *nodo)
{
    if (nodo != 0)
    {
        imprimirEnOrden(nodo->getIzquierdo());
        std::cout << nodo->getId() << " ";
        imprimirEnOrden(nodo->getDerecho());
    }
}

template <class K, class T>
void ABB<K, T>::imprimirEnOrden()
{
    imprimirEnOrden(raiz);
    std::cout << endl;
}

template <class K, class T>
void ABB<K, T>::clavesEnOrden(NodoABB<K, T> *nodo, std::vector<K> &claves)
{
    if (nodo != 0)
    {
        clavesEnOrden(nodo->getIzquierdo(), claves);
        claves.push_back(nodo->getId());
        clavesEnOrden(nodo->getDerecho(), claves);
    }
}

template <class K, class T>
std::vector<K> ABB<K, T>::clavesEnOrden()
{
    std::vector<K> claves;
    clavesEnOrden(raiz, claves);
    return claves;
}

template <class K, class T>
void ABB<K, T>::eliminarTodo(NodoABB<K, T> *nodo)
{
    if (nodo)
    {
        eliminarTodo(nodo->getIzquierdo());
        eliminarTodo(nodo->getDerecho());
        delete nodo;
    }
}

template <class K, class T>
void ABB<K, T>::eliminarTodo()
{
    eliminarTodo(raiz);
}

template <class K, class T>
ABB<K, T>::~ABB()
{
    eliminarTodo();
}

#endif
