// htab_end.c
// Řešení IJC-DU2, příklad 2), 21.4.2020
// Autor: Sotirios Pupakis, FIT
// Přeloženo: gcc 7.5.0

#include "myHtab.h"

htab_iterator_t htab_end(const htab_t * t) {
    htab_iterator_t it;
    it.ptr = NULL;
    it.t = t;
    it.idx = t->arr_size;
    return it;
}


