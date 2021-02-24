// htab_clear.c
// Řešení IJC-DU2, příklad 2), 21.4.2020
// Autor: Sotirios Pupakis, FIT
// Přeloženo: gcc 7.5.0

#include <stdlib.h>
#include "myHtab.h"

void freeIt(struct htab_item * it);

void htab_clear(htab_t * t) {
    struct htab_item *ptr;
    for (int i = 0; i < t->arr_size; i++) {
        ptr = t->list[i];
        struct htab_item *help;

        while (ptr != NULL) {
            help = ptr;
            ptr = ptr->next;
            freeIt(help);
        }
    }
}

void freeIt(struct htab_item * it) {
    free(it->key);
    free(it);
}
