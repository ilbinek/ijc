// wordcount.c
// Řešení IJC-DU2, příklad 2), 21.4.2020
// Autor: Sotirios Pupakis, FIT
// Přeloženo: gcc 7.5.0
// Wordcount, přepis z cpp do c

#include <stdio.h>
#include "myHtab.h"

#define MAGIC_NUMBER 9973   // Provočíslo + málokdy se použije více. 9973
#define WORD_LENGHT 123

int main() {
    htab_t *t = htab_init(MAGIC_NUMBER);



    char str[WORD_LENGHT + 1];

    while (fscanf(stdin, "%123s", str) == 1) {
        htab_iterator_t it = htab_lookup_add(t, str);
        htab_iterator_set_value(it, htab_iterator_get_value(it) + 1);
    }

    htab_iterator_t it = htab_begin(t);

    while (it.ptr != NULL) {
        printf("%s \t %d\n", it.ptr->key, it.ptr->data);
        it = htab_iterator_next(it);
    }

    htab_free(t);
}

int get_word(char *s, int max, FILE *f) {
    fscanf(f, "%123s", s);
    return (int) strlen(s);
}

#ifdef HASHTEST
size_t htab_hash_fun(htab_key_t str) {
    uint32_t h = 0;
    int c;
    while (c = *str++) {
        hash += c;
    }
    return hash;
}
#endif