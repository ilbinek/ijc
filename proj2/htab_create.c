// htab_create.c
// Řešení IJC-DU2, příklad 2), 21.4.2020
// Autor: Sotirios Pupakis, FIT
// Přeloženo: gcc 7.5.0

#include <stdio.h>
#include <stdlib.h>
#include "myHtab.h"

htab_t *htab_init(size_t n) {
    htab_t *t = NULL;
    t = malloc(sizeof(htab_t) + (n * sizeof(struct htab_item)));
    if (t == NULL) {
        return NULL;
    }

    t->size = 0;
    t->arr_size = n;
    for(int i = 0; i < n; i++) {
        t->list[i] = NULL;
    }

    return t;
}