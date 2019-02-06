#include <stdio.h>
#include <stdlib.h>

#define SIZE 76075 // max value for heap

// 1447 = Max value on stack on my 8gb ram latpop with ubuntu 18
// 1 046.9045 kilobytes
// ou 1.0469045 megabytes
// ^ limite d'allocation sur la pile


int main(int argc, char* argv[]) {
    printf("SIZE = %d\n", SIZE);
    
    int size = 10;

    int *v = malloc(sizeof(int)*SIZE);
    int **mat = malloc(sizeof(int)*SIZE);
    int i = 0;
    while (malloc(sizeof(int)*size) != NULL) {
        i++;
        size *= 10;
    }
    printf("MAx memoire = %lu octets <=> %lu kilobytes, %lu megabytes, %lu gibabytes \n", sizeof(int)*size,sizeof(int)*size/1024,sizeof(int)*size/(1024 * 1024), sizeof(int)*size/(1024*1024*1024));
    
    /*
    for (int i = 0; i <SIZE; ++i) {
        *(mat + i) = malloc(sizeof(int)*SIZE);
    }
    
    
    
    for (int i = 0; i<SIZE; ++i) {
        for (int j = 0; j<SIZE; ++j) {
            *(*(mat+i)+j) = i+j;
        }
    }
    */  
    
    free(v;)
    free(mat);
        
    return 0;
}
