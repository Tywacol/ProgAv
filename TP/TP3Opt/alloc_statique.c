#include <stdio.h>

#define SIZE 76075 // max value for heap

// 1447 = Max value on stack on my 8gb ram latpop with ubuntu 18
// 1 046.9045 kilobytes
// ou 1.0469045 megabytes
// ^ limite d'allocation sur la pile

int M[SIZE][SIZE];

int main(int argc, char* argv[]) {
    printf("SIZE = %d\n", SIZE);
    
    
    for (int i = 0; i<SIZE; ++i) {
        for (int j = 0; j<SIZE; ++j) {
            M[i][j] = i+j;
        }
    }
    
        
    return 0;
}
