#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int i = 8;
    printf("Here\n");
    char *tab = malloc(sizeof(char)*i);
    char c = getchar();
    tab[0] = c;
    
    printf("Here\n");

    int nb_char = 1;
    while (!isspace(c)) {
        if (nb_char == i) {
            i = i + 8;
            tab = realloc(tab,i*sizeof(char));
        }
        //putchar(c[nb_char]);
        c  = getchar();
        
        tab[nb_char] = c;
        nb_char++;

    }
    printf("%s\n",tab);
    
    free(tab);
    return 0;
}
