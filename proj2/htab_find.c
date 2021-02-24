// htab_find.h
// Řešení IJC-DU2, příklad 2), 21.4.2020
// Autor: Sotirios Pupakis, FIT
// Přeloženo: gcc 7.5.0

#include <string.h>
#include "myHtab.h"

htab_iterator_t htab_find(htab_t * t, htab_key_t key) {
    size_t hash = htab_hash_fun(key) % t->arr_size;
    if (t->list[hash] == NULL) {
        return htab_end(t);
    }

    struct htab_item *ptr = NULL;
    ptr = t->list[hash];

    while (true) {
        if (strcmp(ptr->key, key) == 0) {
            htab_iterator_t iterator;
            iterator.t = t;
            iterator.idx = hash;
            iterator.ptr = ptr;
            return iterator;
        }
        if (ptr->next == NULL) {
            return htab_end(t);
        } else {
            ptr = ptr->next;
        }
    }
}
