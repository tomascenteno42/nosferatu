// #include "../../../src/main.h"

// Grafo::Grafo()
// {
//     filas = 0;
//     columnas = 0;
//     matriz_adyacencia = nullptr;
// }

// void Grafo::agregar_vertice(string terreno, int fila, int columna)
// {
//     agrandar_matriz();
//     Vertice *nuevo = new Vertice(terreno, fila, columna);
//     vertices.push_back(nuevo);
// }

// Grafo::~Grafo()
// {
//     liberar_matriz_adyacencia();
//     int tamanio = (int)vertices.size();
//     for (int i = 0; i < tamanio; i++)
//     {
//         delete vertices[i];
//     }
//     vertices.clear();
// }

// void Grafo::set_fila(int n)
// {
//     filas = n;
// }

// void Grafo::set_columna(int n)
// {
//     columnas = n;
// }

// void Grafo::agrandar_matriz()
// {
//     int **aux;
//     int nueva_cantidad = (int)vertices.size() + 1;

//     aux = new int *[nueva_cantidad];
//     for (int i = 0; i < nueva_cantidad; i++)
//     {
//         aux[i] = new int[nueva_cantidad];
//     }
//     copiar_matriz(aux);
//     inicializar_nuevo(aux);
//     liberar_matriz_adyacencia();
//     matriz_adyacencia = aux;
// }

// void Grafo::copiar_matriz(int **nueva_matriz)
// {
//     int tamanio = (int)vertices.size();
//     for (int i = 0; i < tamanio; i++)
//     {
//         for (int j = 0; j < tamanio; j++)
//             nueva_matriz[i][j] = matriz_adyacencia[i][j];
//     }
// }

// void Grafo::inicializar_nuevo(int **nueva_matriz)
// {
//     int cantidad_vertices = (int)vertices.size();
//     for (int i = 0; i < cantidad_vertices; i++)
//     {
//         nueva_matriz[cantidad_vertices][i] = INF;
//         nueva_matriz[i][cantidad_vertices] = INF;
//     }
//     nueva_matriz[cantidad_vertices][cantidad_vertices] = 0;
// }

// void Grafo::liberar_matriz_adyacencia()
// {
//     int tamanio = (int)vertices.size();
//     for (int i = 0; i < tamanio; i++)
//     {
//         delete[] matriz_adyacencia[i];
//     }
//     delete[] matriz_adyacencia;
// }

// void Grafo::mostrar_grafo()
// {
//     mostrar_vertices();
//     mostrar_matriz();
// }

// void Grafo::mostrar_vertices()
// {
//     int tamanio = (int)vertices.size();
//     for (int i = 0; i < tamanio; i++)
//     {
//         cout << vertices[i]->get_terreno() << "|";
//     }
//     cout << endl;
//     cout << endl;
// }

// void Grafo::mostrar_matriz()
// {
//     int tamanio = (int)vertices.size();
//     for (int i = 0; i < tamanio; i++)
//     {
//         for (int j = 0; j < tamanio * 2; j++)
//         {
//             if (j == ((tamanio * 2) - 1))
//                 cout << endl;
//             else if (j % 2 == 0)
//             {
//                 if (matriz_adyacencia[i][j / 2] == INF)
//                     cout << "∞";
//                 else
//                     cout << matriz_adyacencia[i][j / 2];
//             }
//             else
//                 cout << "|";
//         }
//     }
//     cout << endl;
// }

// bool Grafo::comprobar_coordenada(Coordenada coordenada)
// {
//     bool cumple_filas = ((coordenada.get_fila() <= filas) && (coordenada.get_fila() > 0));
//     bool cumple_columnas = ((coordenada.get_columna() <= columnas) && (coordenada.get_columna() > 0));
//     if (cumple_filas && cumple_columnas)
//         return true;
//     return false;
// }

// int Grafo::buscar_indice(Coordenada coordenada)
// {
//     int i = 0;
//     int indice = NO_ENCONTRADO;
//     int tamanio = (int)vertices.size();
//     int fila = coordenada.get_fila();
//     int columna = coordenada.get_columna();
//     bool fue_encontrado = false;
//     while (!fue_encontrado && (i < tamanio))
//     {
//         if ((vertices[i]->get_fila() == fila) && (vertices[i]->get_columna() == columna))
//         {
//             fue_encontrado = true;
//             indice = i;
//         }
//         i++;
//     }
//     return indice;
// }

// void Grafo::agregar_camino(int origen, int destino, int costo)
// {
//     matriz_adyacencia[origen][destino] = costo;
// }

// void Grafo::establecer_caminos(string personaje)
// {
//     int tamanio = (int)vertices.size();
//     for (int i = 0; i < tamanio; i++)
//     {
//         vertices[i]->ajustar_costo(personaje);
//         if ((i + columnas) < tamanio) //ajusto el de abajo
//             agregar_camino(i, i + columnas, vertices[i]->get_costo());
//         if ((i - columnas) >= 0) //ajusto el de arriba
//             agregar_camino(i, i - columnas, vertices[i]->get_costo());
//         if ((i + 1) < tamanio)
//         {
//             if (vertices[i]->get_fila() == vertices[i + 1]->get_fila()) //ajusto el de la derecha
//                 agregar_camino(i, i + 1, vertices[i]->get_costo());
//         }
//         if ((i - 1) >= 0)
//         {
//             if (vertices[i]->get_fila() == vertices[i - 1]->get_fila()) //ajusto el de la izquierda
//                 agregar_camino(i, i - 1, vertices[i]->get_costo());
//         }
//     }
// }

// int Grafo::indice_minimo(int distancias[], bool visitados[])
// {
//     int minimo = INF;
//     int indice = 0;
//     int tamanio = (int)vertices.size();

//     for (int i = 0; i < tamanio; i++)
//     {
//         if (!visitados[i] && distancias[i] < minimo)
//         {
//             minimo = distancias[i];
//             indice = i;
//         }
//     }
//     return indice;
// }

// int Grafo::camino_minimo(Coordenada origen, Coordenada destino)
// {
//     bool origen_valido = comprobar_coordenada(origen);
//     bool destino_valido = comprobar_coordenada(destino);
//     if (origen_valido && destino_valido)
//     {
//         int indice_origen = buscar_indice(origen);
//         int indice_destino = buscar_indice(destino);
//         int tamanio = (int)vertices.size();

//         int distancias[tamanio];
//         bool visitados[tamanio];

//         for (int i = 0; i < tamanio; i++)
//         {
//             distancias[i] = INF;
//             visitados[i] = false;
//         }
//         distancias[indice_origen] = 0;
//         for (int i = 0; i < tamanio - 1; i++)
//         {
//             int minimo = indice_minimo(distancias, visitados);
//             visitados[minimo] = true;

//             for (int j = 0; j < tamanio; j++)
//             {
//                 if (!visitados[j] && (distancias[minimo] + matriz_adyacencia[minimo][j] < distancias[j]))
//                     distancias[j] = distancias[minimo] + matriz_adyacencia[minimo][j];
//             }
//         }
//         return distancias[indice_destino];
//     }
//     return NO_ENCONTRADO;
// }
