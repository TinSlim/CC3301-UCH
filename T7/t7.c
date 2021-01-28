#define _XOPEN_SOURCE 500

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <sys/types.h>
#include <sys/wait.h>


#include "viajante.h"

int leer(int fd, void *vbuf, int n) {
  char *buf= vbuf;
  do {
    int rc= read(fd, buf, n);
    if (rc<=0)
      return 1; /* fracaso: error o fin del archivo/pipe/socket */
    n-= rc; /* descontamos los bytes leídos */
    buf+= rc; /* avanzamos el buffer para no reescribir lo leido previamente */
  } while (n>0); /* mientras no leamos todo lo que esperamos */
  return 0; /* exito */
}


double viajante_par(int z[], int n, double **m, int nperm, int p) {
    // Lista de p procesos
    int pids[p]; 
    
    // Para guardar pipes
    int fds_z_aux[p];
    
    // La nueva cantidad de permutaciones
    int new_n_perm = nperm / p;

    // Se crean procesos hijos
    for (int i = 0; i < p; i++) {
        
        // Se crea pipe
        int fds_z[2];
        pipe(fds_z);

        // Se usa la seed y el fork
        init_rand_seed(random()); 
        pids[i] = fork();
        
        // Caso Hijo
        if (pids[i] == 0) {
            
            // Se cierra canal de lectura
            close(fds_z[0]); 
            
            // Se usa la función
            double resultado = viajante(z, n, m, new_n_perm);

            // Se escribe Z y RESULTADO
            write(fds_z[1], &resultado, sizeof(double));
            write(fds_z[1], z, sizeof(int) * (n+1));

            // Salida
            exit(0);
        } 

        // Caso padre
        else {
            // Se cierran canales de escritura
            close(fds_z[1]);

            // Se guardan canales de lectura
            fds_z_aux[i] = fds_z[0];  
        }
    }

    // Se crea un numero grande que obligue a ser reemplazado al menos una vez
    double resultado_final_final = INFINITY;

    // Se obtienen valores de los canales
    for (int i = 0; i < p; i++) {

        // Se obtiene el resultado final
        double resultado_final;
        leer(fds_z_aux[i], &resultado_final, sizeof(double));

        // Se obtiene el Z
        int z_final[n+1];    
        leer(fds_z_aux[i], z_final, sizeof(int) * (n+1));

        // Se entierran procesos y cierran los canales
        waitpid(pids[i],NULL,0);
        close(fds_z_aux[i]);

        // Si el resultado es menor, reemplaza el actual y a Z
        if (resultado_final < resultado_final_final) {
            resultado_final_final = resultado_final;
            for (int k = 0; k < n+1; k++) {
                z[k] = z_final[k];
            }
        }   

        /* Si se entierra el proceso y se cierran canales acá, se 
        puede usar leer(... ,z, ...) en el if en lugar de usar el for*/
    }
    
    // Se devuelve el menor resultado
    return resultado_final_final;
} 
