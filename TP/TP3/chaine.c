//
// Created by corto on 11/02/19.
//

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
    if (chaine1->size == chaine1->alloc - 1) {
        chaine1->alloc = chaine1->alloc * 2;
        chaine1->data = realloc(sizeof(char) * alloc);
        chaine1->data[chaine1->size] = chr;
        chaine1->size++;

    }
}

