// htab_begin.c
// Řešení IJC-DU2, příklad 2), 21.4.2020
// Autor: Sotirios Pupakis, FIT
// Přeloženo: gcc 7.5.0

#include "myHtab.h"

htab_iterator_t htab_begin(const htab_t * t) {
    htab_iterator_t it;
    it.ptr = NULL;
    it.t = t;
    it.idx = t->arr_size;
    for (int i = 0; i < t->arr_size; i++) {
        if (t->list[i] != NULL) {
            htab_iterator_t it;
            it.ptr = t->list[i];
            it.t = t;
            size_t hash = htab_hash_fun(it.ptr->key) % t->arr_size;
            it.idx = hash;
            return it;
        }
    }
    return it;
}
