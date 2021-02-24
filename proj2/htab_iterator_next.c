// htab_iterator_next.c
// Řešení IJC-DU2, příklad 2), 21.4.2020
// Autor: Sotirios Pupakis, FIT
// Přeloženo: gcc 7.5.0

#include "myHtab.h"

htab_iterator_t htab_iterator_next(htab_iterator_t it) {
    size_t hash = htab_hash_fun(it.ptr->key) % it.t->arr_size;

    if (it.ptr->next != NULL) {
        htab_iterator_t i;
        i.ptr = it.ptr->next;
        i.t = it.t;
        i.idx = it.idx;
        return i;
    }

    htab_iterator_t ret;
    ret.ptr = NULL;
    ret.t = it.t;
    ret.idx = it.t->arr_size;

     for (int i = (int)hash + 1; i < it.t->arr_size; i++) {
         if (ret.t->list[i] != NULL) {
             ret.ptr = ret.t->list[i];
             ret.idx = i;
             break;
         }
     }

     return ret;
}