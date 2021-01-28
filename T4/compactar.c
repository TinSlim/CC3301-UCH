#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Counters
    int i = 0;
    int j = 0;
    
    // Buffers initialization
    char bufferI[20];
    char bufferJ[20] = "                   ";
    bufferJ[19] = '\n';
    
    // Opening file
    argv++;
    FILE* in = fopen(*argv,"r+");

    // Report Error
    if ( in == NULL ) {
      perror("Error");;
      return 1;
    }
    
    // Writing lines with words
    while(!feof(in)) {
        
        fseek(in, i*20, SEEK_SET); 
        fread(bufferI,1,20,in);

        if (feof(in)) {
            break;
        }

        else if ((*bufferI) == ' ') {
            i++;
        }

        else {
            fseek(in, j*20, SEEK_SET);
            fwrite(bufferI,1,20,in);
            i++;
            j++;
        }
    }

    // Writing lines without words
    while (i>j) {
        fseek(in, j*20, SEEK_SET);
        fwrite(bufferJ,1,20,in);
        j++;
    }

    fclose(in);
    return 0;   
}