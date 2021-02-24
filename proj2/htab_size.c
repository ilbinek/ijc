// htab_size.c
// Řešení IJC-DU2, příklad 2), 21.4.2020
// Autor: Sotirios Pupakis, FIT
// Přeloženo: gcc 7.5.0

#include "myHtab.h"

size_t htab_size(const htab_t * t) {
    return t->size;
}