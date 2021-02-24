// htab_erase.c
// Řešení IJC-DU2, příklad 2), 21.4.2020
// Autor: Sotirios Pupakis, FIT
// Přeloženo: gcc 7.5.0

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "myHtab.h"

void htab_erase(htab_t * t, htab_iterator_t it) {
    size_t hash = htab_hash_fun(it.ptr->key) % t->arr_size;

    if (t->list[hash] == it.ptr) {
        t->list[hash] = it.ptr->next;
        free(it.ptr->key);
        free(it.ptr);
        return;
    }

    struct htab_item *ptr = t->list[hash];
    while (true) {
        if (ptr == NULL) {
            fprintf(stderr, "Did not find this pointer / key");
            break;
        }
        if (ptr->next == it.ptr) {
            ptr->next = it.ptr->next;
            free(it.ptr->key);
            free(it.ptr);
            break;
        } else {
            ptr = ptr->next;
        }
    }
}