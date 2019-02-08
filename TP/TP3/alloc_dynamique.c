#include <stdio.h>
#include <stdlib.h>


#define SIZE 1000000000

// 1 Mo = 1000Ko = 1000000o
//#define SIZE 76075 // max value for heap

// 1447 = Max value on stack on my 8gb ram latpop with ubuntu 18
// 8192 megabytes -- same as ulimit -s


int main(int argc, char* argv[]) {
    printf("SIZE = %d\n", SIZE);

    int **mat = malloc(sizeof(*mat)*SIZE);
    int i = 0;
    for (i = 0; i<SIZE; i++) {
        //printf("Iteration : %d\n", i);
        mat[i] = malloc(sizeof(*mat[i])*SIZE);
        if (mat[i] == NULL) {
            printf("MAx memoire = %lu octets <=> %lu kilobytes, %lu megabytes, %lu gibabytes \n",
                   sizeof(int)*i*i,
                   sizeof(int)*i*i/1000,
                   sizeof(int)*i*i/(1000 * 1000), 
                   sizeof(int)*i*i/(1000 * 1000*1000));
            break;
            
        } 
    }
    
    printf("Here\n");
    
    for (i; i>-1; i--) {
        free(mat[i]);
    } 
    free(mat);
    
        
    return 0;
}
