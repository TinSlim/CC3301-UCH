#include<stdlib.h>
#include "t2.h"

void reducir(char *s){
    char *p = s;
    char *q = p;
    while(*q != 0){
        q++;
        if ( (*p != ' ') || (*q != ' ')){
            p++;
            *p = *q;
        }
    }
}

char *reduccion(char *s) { 
    char *p = s;  
    char *q = p;
    int len = 1;

   while(*p!= 0){
        if ( (*p == ' ') && (*q == ' ')){
        q++;}

        else if ( (*p != ' ') && (*q != ' ')){
        q++;
        p++;
        len++;  
        }
        else{
            p=q;
            len++;
        }
    }

    char* salida = malloc(len);
    q = salida;
    p = s;
    *q = *p;
    
    while(*q){
        p++;
        if ( (*p != ' ') || (*q != ' ') ){
            q++;
            *q = *p;
        }
    }    
    return salida;   
}
