// htab_lookup_add.c
// Řešení IJC-DU2, příklad 2), 21.4.2020
// Autor: Sotirios Pupakis, FIT
// Přeloženo: gcc 7.5.0

#include <stdlib.h>
#include <string.h>
#include "myHtab.h"

htab_iterator_t htab_lookup_add(htab_t * t, htab_key_t key) {
    size_t hash = htab_hash_fun(key) % t->arr_size;
    if (t->list[hash] == NULL) {
        char *str = malloc(sizeof(char) * strlen(key) + 1);
        strcpy(str, key);
        struct htab_item *ptr = malloc(sizeof(struct htab_item));
        ptr->next = NULL;
        ptr->key = str;
        ptr->data = 0;
        t->list[hash] = ptr;
        htab_iterator_t it;
        it.ptr = ptr;
        it.t = t;
        it.idx = hash;
        t->size++;
        return it;
    } else {
        if (strcmp(t->list[hash]->key, key) == 0) {
            htab_iterator_t it;
            it.ptr = t->list[hash];
            it.t = t;
            it.idx = hash;
            return it;
        } else {
            char *str = malloc(sizeof(char) * strlen(key) + 1);
            strcpy(str, key);
            struct htab_item *ptr = malloc(sizeof(struct htab_item));
            ptr->next = t->list[hash];
            ptr->key = str;
            ptr->data = 0;
            t->list[hash] = ptr;
            htab_iterator_t it;
            it.ptr = ptr;
            it.t = t;
            it.idx = hash;
            t->size++;
            return it;
        }
    }
}

