#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "t1.h"

// ----------------------------------------------------
// Funcion que entrega el tiempo transcurrido desde el lanzamiento del
// programa en milisegundos

static int time0= 0;

static int getTime0() {
    struct timeval Timeval;
    gettimeofday(&Timeval, NULL);
    return Timeval.tv_sec*1000+Timeval.tv_usec/1000;
}

static void resetTime() {
  time0= getTime0();
}

static int getTime() {
  return getTime0()-time0;
}

// ----------------------------------------------------
// Funcion que entrega numero aleatorio de 64 bits

static unsigned long long randull() {
  unsigned long long x = rand();
  x = (x<<31) | rand();
  x= (x<<2) | (rand() & 3);
  return x;
}

// ----------------------------------------------------
// Funcion que calcula duplicado mas largo con
// divisiones y restos

static unsigned long long divDupMasLargo(unsigned long long x) {
  int tam= 0;
  unsigned sec= 0;
  unsigned long long dos_ala_t= 2;
  unsigned long long dos_ala_2t= 4;
  for (int t= 1; t<=32; t++) {
    unsigned long long x_2t_bits= x;
    if (t!=32)
      x_2t_bits= x % dos_ala_2t;
    unsigned long long x_t_bits_sup= x_2t_bits / dos_ala_t;
    unsigned long long x_t_bits_inf= x_2t_bits % dos_ala_t;
    if (x_t_bits_sup == x_t_bits_inf) {
      tam= t;
      sec= x_t_bits_inf;
    }
    dos_ala_t *= 2;
    dos_ala_2t *= 4;
  }
  return ((unsigned long long)tam<<32) | sec;
}

// ----------------------------------------------------
// Funcion que genera n numeros aleatorios

static void gen(unsigned long long vx[], int n) {
  for (int i= 0; i<n; i++) {
    unsigned long long x= randull();
    vx[i]= x;
  }
}

// ----------------------------------------------------
// Funcion que calcula duplicados mas largos de vx
// La funcion que hace el calculo es el parametro fun

static void ndup(unsigned long long vx[], unsigned vsec[], int vtam[], int n,
          unsigned long long (*fun)(unsigned long long x)) {
  for (int i= 0; i<n; i++) {
    unsigned long long res= (*fun)(vx[i]);
    vtam[i]= res>>32;
    vsec[i]= res;
  }
}

#define N 10000000
unsigned long long vx[N];
unsigned vsec[N], vsecref[N];
int vtam[N], vtamref[N];

int main() {
  { // Primera condicion de borde: no hay secuencia duplicada
    // int tam=dupMasLargo(0b1);
    // tam==0, sec==0
    printf("Verificando con x = 0b01\n");
    unsigned long long res=dupMasLargo(0x1);
    int tam= res >> 32;
    unsigned int sec= res;
    if (tam!=0) {
      fprintf(stderr, "Largo debe ser 0, no %d\n", tam);
      exit(1);
    }
    if (sec!=0x0) {
       fprintf(stderr, "sec debe ser 0x0, no %x\n", sec);
       exit(1);
    }
  }

  { // Segunda condicion de borde: la secuencia duplicada es de 32 bits
    // int tam=dupMasLargo(0b0);
    // x>>32 == 0b0
    // tam==32, sec==0b0
    printf("Verificando con x = 0b0\n");
    unsigned long long res=dupMasLargo(0x0);
    int tam= res >> 32;
    unsigned int sec= res;
    if (tam!=32) {
      fprintf(stderr, "Largo debe ser 32, no %d\n", tam);
      exit(1);
    }
    if (sec!=0x0) {
       fprintf(stderr, "sec debe ser 0x0, no %x\n", sec);
       exit(1);
    }
  }

  { // Secuencia duplicada de tamaño 1
    // int tam=dupMasLargo(0b11);
    // x>>1 == 0b1
    // tam==1, sec==0b1
    printf("Verificando con x = 0b11\n");
    unsigned long long res=dupMasLargo(0x3);
    int tam= res >> 32;
    unsigned int sec= res;
    if (tam!=1) {
      fprintf(stderr, "Largo debe ser 1, no %d\n", tam);
      exit(1);
    }
    if (sec!=0x1) {
       fprintf(stderr, "sec debe ser 0x1, no %x\n", sec);
       exit(1);
    }
  }

  {
    // int tam=dupMasLargo(0b1 0110 0100 1001 0010 0100);
    // x>>9 == 0b1011 0010 0100
    // tam==9, sec==0b1 0010 0100
    printf("Verificando con x = 0b1 0110 0100 1001 0010 0100\n");
    unsigned long long res=dupMasLargo(0x164924);
    int tam= res >> 32;
    unsigned int sec= res;
    if (tam!=9) {
      fprintf(stderr, "Largo debe ser 9, no %d\n", tam);
      exit(1);
    }
    if (sec!=0x124) {
       fprintf(stderr, "sec debe ser 0x128, no %x\n", sec);
       exit(1);
    }
  }

  { // Otra secuencia de largo 32
    // int tam=dupMasLargo(0x3af5c
    // x>>9 == 0b1011 0010 0100
    // tam==9, sec==0b1 0010 0100
    printf("Verificando con x = 0x3af13c80\n");
    unsigned long long xm= 0x3af13c80;
    unsigned long long res=dupMasLargo((xm<<32)|xm);
    int tam= res >> 32;
    unsigned int sec= res;
    if (tam!=32) {
      fprintf(stderr, "Largo debe ser 9, no %d\n", tam);
      exit(1);
    }
    if (sec!=xm) {
       fprintf(stderr, "sec debe ser %llx, no %x\n", xm, sec);
       exit(1);
    }
  }

  printf("\nVamos bien, paso los primeros tests\n\n");

  // Benchmark
  int n= N;
  printf("Benchmark: Se generan %d numeros aleatorios y se compara\n", n);
  printf("el tiempo de calculo del duplicado mas largo con su funcion vs.\n");
  printf("el tiempo del mismo calculo con divisiones y restos\n");
  printf("Los primeros numeros son:\n");
  gen(vx, n);
  for (int i= 0; i< (n>10 ? 10 : n); i++) {
    printf("%llx ", vx[i]);
    if ((i+1)%4==0)
      printf("\n");
  }
  printf("\n\n");
  ndup(vx, vsecref, vtamref, n>10 ? 10 : n, divDupMasLargo);
  printf("Calculando duplicado mas largo con divisiones y restos\n");
  resetTime();
  ndup(vx, vsecref, vtamref, n, divDupMasLargo);
  int timeref= getTime();
  printf("Con divisiones y restos tomo %d milisegundos\n", timeref);
  long long sumtam= 0;
  for (int i= 0; i<n; i++) {
    sumtam += vtamref[i];
  }
  printf("Promedio de los tamannos es %3.1f\n", (double)sumtam/n);
  ndup(vx, vsec, vtam, n>10 ? 10 : n, dupMasLargo);
  printf("\nCalculando duplicado mas largo con su funcion\n");
  resetTime();
  ndup(vx, vsec, vtam, n, dupMasLargo);
  int time= getTime();
  for (int i= 0; i<n; i++) {
    if (vsecref[i]!=vsec[i] || vtamref[i]!=vtam[i]) {
      fprintf(stderr, "Falla para %llx\n", vx[i]);
      fprintf(stderr, "Su funcion entrego tamanno= %d secuencia= %x\n",
              vtam[i], vsec[i]);
      fprintf(stderr, "Debio entregar     tamanno= %d secuencia= %x\n",
              vtamref[i], vsecref[i]);
      exit(1);
    }
  }
  printf("Su funcion tomo %d milisegundos\n", time);
  if (time > timeref) {
    fprintf(stderr, "Su funcion es demasiado ineficiente.  Tomo mas\n");
    fprintf(stderr, "tiempo que haciendolo con divisiones y restos.\n");
    exit(1);
  }
  if (time!=0)
    printf("El speed up es %3.1fx\n", (double)timeref/time);

  printf("Felicitaciones: funciona con los ejemplos del enunciado\n");
  return 0;
}
