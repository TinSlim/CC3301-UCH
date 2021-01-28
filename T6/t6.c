#include <pthread.h>

#include "t6.h"


pthread_mutex_t m= PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t q = PTHREAD_COND_INITIALIZER;

int numeroObtencion = 0;
int numeroPantalla = 0;

void ocupar() {
  pthread_mutex_lock(&m);
  
  // Se obtiene número para esta persona
  int numeroPersona = numeroObtencion;
  numeroObtencion++;

  // Si no es su turno se queda en espera
  while (numeroPantalla != numeroPersona) {
    pthread_cond_wait(&q, &m);
  }
  pthread_mutex_unlock(&m);
}

void desocupar() {
  pthread_mutex_lock(&m);
  
  // Avanza número la pantalla
  numeroPantalla++;

  // Gente revisa la pantalla
  pthread_cond_broadcast(&q);
  pthread_mutex_unlock(&m);
}
