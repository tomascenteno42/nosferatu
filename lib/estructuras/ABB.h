#ifndef TP3_BST_H
#define TP3_BST_H

#include "../../src/main.h"

template <class K, class T>
class NodoABB;

template <class K, class T>
class ABB
{
private:
    int cantidad;

    NodoABB<K, T> *raiz;

    /**
     * @brief Busca de forma recursiva el nodo con el clave mas chica y retorna su clave.
     * 
     * @param nodo 
     * @return K clave
     */
    K buscarMinimo(NodoABB<K, T> *nodo);

    /**
     * @brief Busca de forma recursiva el nodo con el clave mas grande y retorna su clave.
     * 
     * @param nodo 
     * @return K clave
     */
    K buscarMaximo(NodoABB<K, T> *nodo);

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

    /**
     * @brief Elimina un nodo que tiene clave.
     * 
     * @param nodo 
     * @param clave 
     * @return NodoABB<K, T>* 
     */
    NodoABB<K, T> *eliminar(NodoABB<K, T> *nodo, K clave);

    /**
     * @brief Imprime todos los valores del ABB.
     * 
     * @param nodo 
     */
    void imprimirEnOrden(NodoABB<K, T> *nodo);

    /**
     * @brief Ordena las claves y las va colocando en un vector pasado por referencia.
     * 
     * @param nodo 
     * @param claves 
     */
    void idsEnOrden(NodoABB<K, T> *nodo, std::vector<K> &claves);

    /**
     * @brief Limpia el ABB.
     * 
     * @param nodo 
     */
    void eliminarTodo(NodoABB<K, T> *nodo);

public:
    /**
     * @brief Construye un arbol de busqueda binaria.
     * 
     */
    ABB();

    T getData(K clave);
    NodoABB<K, T> *getRaiz();

    /**
     * @brief Busca el minimo nodo y retorna su valor.
     * 
     * @return K clave
     */
    K buscarMinimo();

    /**
     * @brief Busca el maximo nodo y retorna su valor.
     * 
     * @return K clave
     */
    K buscarMaximo();

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
     * @brief Elimina un nodo del ABB.
     * 
     * @param clave
     */
    void eliminar(K clave);

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
     * @brief Imprime toda la data del ABB, desde el menor al mayor.
     * 
     */
    void imprimirEnOrden();

    /**
     * @brief Devuelve las claves del ABB en orden.
     * 
     * @return std::vector<K> 
     */
    std::vector<K> idsEnOrden();

    /**
     * @brief Elimina todos los nodos del ABB.
     */
    void eliminarTodo();

    /**
     * @brief Destruye el arbol.
     * 
     */
    ~ABB();
};

template <class K, class T>
ABB<K, T>::ABB()
{
    raiz = NULL;
    cantidad = 0;
}

template <class K, class T>
T ABB<K, T>::getData(K clave)
{
    NodoABB<K, T> *nodo = buscar(raiz, clave);
    return nodo->getData();
}

template <class K, class T>
NodoABB<K, T> *ABB<K, T>::getRaiz()
{
    return raiz;
}

template <class K, class T>
NodoABB<K, T> *ABB<K, T>::buscar(NodoABB<K, T> *nodo, K clave)
{
    if (nodo && clave < nodo->getId())
        nodo = buscar(nodo->getIzquierdo(), clave);

    if (nodo && clave > nodo->getId())
        nodo = buscar(nodo->getDerecho(), clave);

    return nodo;
}

template <class K, class T>
K ABB<K, T>::buscarMinimo()
{
    if (vacio())
    {
        return -1;
    }

    return buscarMinimo(raiz);
}

template <class K, class T>
K ABB<K, T>::buscarMinimo(NodoABB<K, T> *nodo)
{
    NodoABB<K, T> *nodoIzquierdo = nodo->getIzquierdo();

    if (nodoIzquierdo)
    {
        return buscarMinimo(nodoIzquierdo);
    }

    return nodo->getId();
}

template <class K, class T>
K ABB<K, T>::buscarMaximo()
{
    if (vacio())
    {
        return -1;
    }

    return buscarMaximo(raiz);
}

template <class K, class T>
K ABB<K, T>::buscarMaximo(NodoABB<K, T> *nodo)
{
    NodoABB<K, T> *nodoDerecho = nodo->getDerecho();

    if (nodoDerecho)
    {
        buscarMaximo(nodoDerecho);
    }

    return nodo->getId();
}

template <class K, class T>
K ABB<K, T>::predecesor(K clave)
{
    NodoABB<K, T> *nodo = buscar(this->raiz, clave);

    if (!nodo)
        return -1;

    return predecesor(nodo);
}

template <class K, class T>
K ABB<K, T>::predecesor(NodoABB<K, T> *nodo)
{

    if (nodo->getId() == buscarMinimo())
        return -1;

    if (nodo->getIzquierdo())
        return buscarMaximo(nodo->getIzquierdo());

    K clave = nodo->getId();

    NodoABB<K, T> *ancestro = nodo->getPadre();

    while (clave <= ancestro->getId())
        ancestro = ancestro->getPadre();

    return ancestro->getId();
}

template <class K, class T>
K ABB<K, T>::sucesor(K clave)
{
    NodoABB<K, T> *nodo = buscar(this->raiz, clave);

    if (!nodo)
        return -1;

    return sucesor(nodo);
}

template <class K, class T>
K ABB<K, T>::sucesor(NodoABB<K, T> *nodo)
{
    if (nodo->getId() == buscarMaximo())
        return -1;

    if (nodo->getDerecho())
        return buscarMinimo(nodo->getDerecho());

    K clave = nodo->getId();

    NodoABB<K, T> *ancestro = nodo->getPadre();

    while (clave >= ancestro->getId())
        ancestro = ancestro->getPadre();

    return ancestro->getId();
}

template <class K, class T>
void ABB<K, T>::insertar(K clave, T data)
{
    if (!existe(clave))
    {
        raiz = insertar(clave, data, this->raiz);
        cantidad++;
    }
}

template <class K, class T>
NodoABB<K, T> *ABB<K, T>::insertar(K clave, T data, NodoABB<K, T> *nodo)
{
    if (!nodo)
    {
        nodo = new NodoABB<K, T>(clave, data);
    }
    else if (clave < nodo->getId())
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
void ABB<K, T>::eliminar(K clave)
{
    if (existe(clave))
    {
        raiz = eliminar(raiz, clave);
    }
}

template <class K, class T>
NodoABB<K, T> *ABB<K, T>::eliminar(NodoABB<K, T> *nodo, K clave)
{
    if (clave < nodo->getId())
    {
        nodo->setIzquierdo(eliminar(nodo->getIzquierdo(), clave));
        cantidad--;
    }
    else if (clave > nodo->getId())
    {
        nodo->setDerecho(eliminar(nodo->getDerecho(), clave));
        cantidad--;
    }
    else
    {
        if (nodo->esHoja())
        {
            delete nodo;
            nodo = NULL;
        }
        else if (nodo->tieneSoloHijoDerecho())
        {
            nodo->getDerecho()->setPadre(nodo->getPadre());
            NodoABB<K, T> *nodoAux = nodo->getDerecho();
            delete nodo;
            nodo = nodoAux;
        }
        else if (nodo->tieneSoloHijoIzquierdo())
        {
            nodo->getIzquierdo()->setPadre(nodo->getPadre());
            NodoABB<K, T> *nodoAux = nodo->getIzquierdo();
            delete nodo;
            nodo = nodoAux;
        }
        else
        {
            K remplazo;

            if (existe(sucesor(clave)))
            {
                remplazo = buscar(raiz, sucesor(clave))->getId();
            }
            else
            {
                remplazo = buscar(raiz, predecesor(clave))->getId();
            }

            T newData = getData(remplazo);
            raiz = eliminar(raiz, remplazo);
            nodo->setData(newData);
            nodo->setId(remplazo);
        }
        cantidad--;
    }
    return nodo;
}

template <class K, class T>
bool ABB<K, T>::existe(K clave)
{
    return buscar(raiz, clave) != NULL;
}

template <class K, class T>
bool ABB<K, T>::vacio()
{
    return cantidad == 0;
}

template <class K, class T>
void ABB<K, T>::imprimirEnOrden(NodoABB<K, T> *nodo)
{
    if (nodo != NULL)
    {
        imprimirEnOrden(nodo->getIzquierdo());
        cout << nodo->getId() << ' ';
        imprimirEnOrden(nodo->getDerecho());
    }
}

template <class K, class T>
void ABB<K, T>::imprimirEnOrden()
{
    imprimirEnOrden(raiz);
    cout << endl;
}

template <class K, class T>
std::vector<K> ABB<K, T>::idsEnOrden()
{
    std::vector<K> claves;

    idsEnOrden(raiz, claves);

    return claves;
}

template <class K, class T>
void ABB<K, T>::idsEnOrden(NodoABB<K, T> *nodo, std::vector<K> &claves)
{
    if (nodo != NULL)
    {
        idsEnOrden(nodo->getIzquierdo(), claves);

        claves.push_back(nodo->getId());

        idsEnOrden(nodo->getDerecho(), claves);
    }
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
