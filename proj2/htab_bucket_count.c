// htab_bucket_count.c
// Řešení IJC-DU2, příklad 2), 21.4.2020
// Autor: Sotirios Pupakis, FIT
// Přeloženo: gcc 7.5.0

#include "myHtab.h"

size_t htab_bucket_count(const htab_t * t) {
    return t->arr_size;
}