template <class T>
class Nodo
{
private:
  T data;
  Nodo<T> *siguienteNodo = 0;

public:
  Nodo(T d);

  void setData(T d);
  void setSiguienteNodo(Nodo<T> *nodo);

  T getData();
  Nodo<T> *getSiguienteNodo();
};

// IMPLEMENTATION
template <class T>
Nodo<T>::Nodo(T d)
{
  data = d;
}

template <class T>
T Nodo<T>::getData()
{
  return data;
}

template <class T>
Nodo<T> *Nodo<T>::getSiguienteNodo()
{
  return siguienteNodo;
}

template <class T>
void Nodo<T>::setData(T d)
{
  data = d;
}

template <class T>
void Nodo<T>::setSiguienteNodo(Nodo<T> *nodo)
{
  siguienteNodo = nodo;
}