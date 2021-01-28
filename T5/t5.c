#include <pthread.h>
#include "maleta.h"
#include <stdio.h>
#include <stdlib.h>

// Se crea la estructura
typedef struct nodo {
    double* w;
    double* v;
    int* z;
    int n;
    double maxW;
    int k;

    double best;
} Nodo;

// Función  void* f (void*) que recibe el thread
void* llenarMaletaThread (void* estructura) {
    Nodo* estructuraN = (Nodo*) estructura;
    estructuraN -> best = llenarMaletaSec(estructuraN -> w, estructuraN -> v, estructuraN -> z, estructuraN -> n,  estructuraN -> maxW, estructuraN -> k);
    return NULL;
}

// Función principal
double llenarMaletaPar (double w[], double v[], int z[], int n,  double maxW, int k) {
    pthread_t pth[8]; // 8 threads
    Nodo nodos[8]; // 8 estructuras
    
    // Resultado final, cualquiera es mayor a -1
    double mejor = -1;
    
    // Matriz de 8xn 
    int newZ[8][n];

    // Cada thread revisa un octavo (k/8)
    k = k/8;

    // Se crean 8 estructuras y se inician 8 threads
    for (int i = 0; i < 8; i++ ) {
        nodos[i].w = w;
        nodos[i].v = v;
        nodos[i].z = newZ[i];
        
        // Se reemplazan valores de z de la estructura
        for (int j = 0 ; j<n ; j++) {
                z[j] = nodos[i].z[j];
        }

        nodos[i].n = n;
        nodos[i].maxW = maxW;
        nodos[i].k = k;
        nodos[i].best = mejor;
        
        // Se lanza thread
        pthread_create(&pth[i], NULL, llenarMaletaThread, &nodos[i]);
    }

    // Se obtienen resultados para cada thread
    for (int i = 0; i < 8; i++ ) {
        // Se entierra el thread
        pthread_join(pth[i], NULL);

        // Si el resultado es mayor al actual, se actualiza el mayor y z
        if (mejor < nodos[i].best) {
            mejor = nodos[i].best;
            for (int j = 0 ; j<n ; j++) {
                z[j] = nodos[i].z[j];
            }
        }
    }
    // Se retorna el mejor
    return mejor;
}
