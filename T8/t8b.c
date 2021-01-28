/**
 * Podría pasar que se entre a la condición if(d<min), 
 * donde luego de reemplazar el valor min se entra a un for,
 * si dentro de este for se apreta CTRL-C se hace el longjmp, 
 * se habrá reemplazado el min pero puede que no todos los 
 * valores de Z  se hayan actualizado y desde ahi se pasa al else,
 * asi podria la distancia no corresponder a los valores de Z.
 **/

#define _XOPEN_SOURCE 500

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <setjmp.h>

#include "viajante.h"

static jmp_buf excp;

void ring() {
  longjmp(excp,1);
}

double viajante(int z[], int n, double **m, int nperm) {
  double min= DBL_MAX; // la distancia mas corta hasta el momento
  void (*hdlr)() = signal(SIGINT,ring); 
  if (setjmp(excp) == 0) {
    for (int i= 1; i<=nperm; i++) {
      int x[n+1];          // almacenara una ruta aleatoria
      gen_ruta_alea(x, n); // genera ruta x[0]=0, x[1], x[2], ..., x[n], x[0]=0
      // calcula la distancia al recorrer 0, x[1], ..., x[n], 0
      double d= dist(x, n, m);
      if (d<min) {    // si distancia es menor a la mas corta hasta el momento
        min= d;       // d es la nueva distancia mas corta
        for (int j= 0; j<=n; j++)
          z[j]= x[j]; // guarda ruta mas corta en parametro z
      }
    }
  }
  else {
  }
  signal(SIGINT,hdlr); 
  return min;
}
