#include <stdlib.h>
#include "t3.h"

void desbalancear(Nodo **pa, Nodo **pult){
    Nodo* actual = *pa; 

    //Caso base
    if (actual == NULL){
      *pult = *pa;
    }

    else {
      Nodo* hIzq = (*actual).izq;
      Nodo* hDer = (*actual).der;
      
      desbalancear(&hDer,pult);
      if (*pult == NULL){
        *pult = actual;  
      }
      else {
        (*pa)->izq = NULL;
        (*pa)->der = hDer;
      }

      desbalancear(&hIzq,pa);
      if (*pa == NULL){
        *pa = actual;
      }
      else{
      (*pa)->izq = NULL;
      (*pa)->der = actual;
      *pa = hIzq;
      (*actual).izq = NULL;
      }   
  }
}

Nodo *desbalanceado(Nodo *a, Nodo **pult){
  if (a == NULL) {
    *pult = NULL;
    return NULL;
  }

  Nodo* actual = malloc(sizeof(Nodo));
  actual->id = (*a).id;
  actual->hash = (*a).hash;
  actual->der = NULL;
  actual->izq = NULL;

  Nodo* derecho = desbalanceado((*a).der,pult);  
  if (*pult == NULL){
    *pult = actual;
  }
  actual->der = derecho;

  Nodo* izquierdo = desbalanceado((*a).izq,&a);
  if (izquierdo != NULL) {
    a->der = actual;
    return izquierdo;
  }
  else {
    return actual;
  }
}