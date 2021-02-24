// htab_iterator_set_value.c
// Řešení IJC-DU2, příklad 2), 21.4.2020
// Autor: Sotirios Pupakis, FIT
// Přeloženo: gcc 7.5.0

#include "myHtab.h"

htab_value_t htab_iterator_set_value(htab_iterator_t it, htab_value_t val) {
    it.ptr->data = val;
    return it.ptr->data;
}