#include <stdio.h>
#include <stdlib.h>

#include "t1.h"

unsigned long long dupMasLargo(unsigned long long n){
    unsigned long long mascara = n;
    unsigned long long filtrado = 0;
    unsigned long long cadenaLarga = 0;
    unsigned long long cadenaFinal = 0;
    unsigned long long tamanhoSecuencia = 0;

    int desplazamientos = 1;
    int limpiador = 0;

    /*Se crea la mascara*/
    mascara = n;
    while(desplazamientos != 33){

        /*Se desplaza 1 la mascara*/
        mascara = mascara >>1;

        /*Se aplica la mascara*/
        // Si coinciden da 0s, sino 1s
        filtrado = (n^mascara); 
        
        /*Se limpia la mascara y el valor actual*/
        // Eliminando valores que no importan (los de la izquierda)
        cadenaLarga = n;
        limpiador = 64-desplazamientos;
        filtrado = filtrado << limpiador;
        cadenaLarga = cadenaLarga <<limpiador;
        filtrado = filtrado  >> limpiador;
        cadenaLarga = cadenaLarga >> limpiador;
        
        /*Si el filtrado es 0, todos los numeros de la subcadena coincidian*/
        // Se reemplaza la cadena final por la actual (que debería ser más larga), 
        // también el tamanho de la secuencia
        if (filtrado==0){
            cadenaFinal = cadenaLarga;
            tamanhoSecuencia = desplazamientos;
        }

        /*Se avanza el contador de bits que se consideran para la subcadena*/
        desplazamientos = desplazamientos + 1;
    }

    /*Terminado el ciclo while*/
    // Se mueve a la izquierda 32 bits el tamanho de la secuencia
    tamanhoSecuencia = tamanhoSecuencia <<32;
    // Se agrega a la cadena final
    cadenaFinal = tamanhoSecuencia | cadenaFinal;
    return cadenaFinal;
}