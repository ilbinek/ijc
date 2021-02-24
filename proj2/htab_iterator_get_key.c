// htab_iterator_get_key.c
// Řešení IJC-DU2, příklad 2), 21.4.2020
// Autor: Sotirios Pupakis, FIT
// Přeloženo: gcc 7.5.0

#include "myHtab.h"

htab_key_t htab_iterator_get_key(htab_iterator_t it) {
    return it.ptr->key;
}