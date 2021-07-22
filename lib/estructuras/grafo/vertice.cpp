// #include "../../../src/main.h"

// Vertice::Vertice(string terreno, int fila, int columna)
// {
//     this->terreno = terreno;
//     coordenadas.set_fila(fila);
//     coordenadas.set_columna(columna);
// }

// int Vertice::get_costo()
// {
//     return costo;
// }

// int Vertice::get_fila()
// {
//     return (this->coordenadas.get_fila());
// }

// int Vertice::get_columna()
// {
//     return (this->coordenadas.get_columna());
// }

// string Vertice::get_terreno()
// {
//     return terreno;
// }

// void Vertice::ajustar_costo(string tipo)
// {
//     if (tipo == VANESA)
//         tipo = HUMANO_CV;
//     else if (tipo == NOSFERATU || tipo == VAMPIRELLA)
//         tipo = VAMPIRO;

//     if (tipo == HUMANO)
//     {
//         if (terreno == montan || terreno == PRECIPICIO)
//             costo = 2;
//         else if (terreno == LAGO)
//             costo = 0;
//         else if (terreno == VOLCAN || terreno == CAMINO)
//             costo = 1;
//         else
//             costo = 15;
//     }
//     else if (tipo == VAMPIRO)
//     {
//         if (terreno == MONTANIA || terreno == LAGO || terreno == CAMINO)
//             costo = 1;
//         else if (terreno == PRECIPICIO)
//             costo = 0;
//         else if (terreno == VOLCAN)
//             costo = 2;
//         else
//             costo = 15;
//     }
//     else if (tipo == ZOMBI)
//     {
//         if (terreno == MONTANIA || terreno == PRECIPICIO || terreno == CAMINO)
//             costo = 1;
//         else if (terreno == LAGO)
//             costo = 2;
//         else if (terreno == VOLCAN)
//             costo = 0;
//         else
//             costo = 15;
//     }
//     else if (tipo == CV)
//     {
//         if (terreno == MONTANIA || terreno == LAGO)
//             costo = 0;
//         else if (terreno == PRECIPICIO)
//             costo = 2;
//         else if (terreno == VOLCAN || terreno == CAMINO)
//             costo = 1;
//         else
//             costo = 15;
//     }
// }
