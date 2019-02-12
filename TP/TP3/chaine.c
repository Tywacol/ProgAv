#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char *data;
    int alloc;
    int size;

} chaine;

void init_chaine(chaine *chaine1)
{
    chaine1->alloc = 0;
    chaine1->size = 0;
    chaine1->data = NULL;

}

void clean_chaine(chaine *chaine1)
{
    free(chaine1->data);
    free(chaine1);
}


void print_chaine(chaine *chaine1)
{
    printf("%s", chaine1->data);
}

void concat_chaine_char(chaine *chaine1, char chr)
{
    if (chaine1->data == NULL) {
        chaine1->alloc = 8;
        chaine1->data = malloc(sizeof(char) * chaine1->alloc);

    }
    if (chaine1->size == chaine1->alloc - 1) {
        chaine1->alloc *= 2;
        chaine1->data = realloc(chaine1->data, sizeof(char) * chaine1->alloc);
    }
    chaine1->data[chaine1->size] = chr;
    if (chr != '\0') {
        chaine1->size++;
    }
}

void concat_chaine_chaine(chaine *chaine1, chaine *chaine2)
{
    int i = 0;
    while (chaine2->data[i] != '\0') {
        // Le '\0' de chaine1 est supprimé lors de l'ajout du premier charactere de chaine2
        concat_chaine_char(chaine1, chaine2->data[i]);
        i++;
    }
}

int main()
{
    chaine *ch = malloc(sizeof(chaine));
    chaine *ch1 = malloc(sizeof(chaine));
    init_chaine(ch);

    concat_chaine_char(ch, 'H');
    concat_chaine_char(ch, 'e');
    concat_chaine_char(ch, 'l');
    concat_chaine_char(ch, 'l');
    concat_chaine_char(ch, 'o');
    concat_chaine_char(ch, ' ');
    concat_chaine_char(ch, '\0');

    concat_chaine_char(ch1, 'W');
    concat_chaine_char(ch1, 'o');
    concat_chaine_char(ch1, 'r');
    concat_chaine_char(ch1, 'l');
    concat_chaine_char(ch1, 'd');
    concat_chaine_char(ch1, '!');
    concat_chaine_char(ch1, '\n');
    concat_chaine_char(ch1, '\0');

    print_chaine(ch);
    printf("\n");
    print_chaine(ch1);

    concat_chaine_chaine(ch, ch1);
    print_chaine(ch);

    clean_chaine(ch1);
    clean_chaine(ch);
    return 0;
}
