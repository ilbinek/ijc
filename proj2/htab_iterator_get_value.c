// htab_iterator_get_value.c
// Řešení IJC-DU2, příklad 2), 21.4.2020
// Autor: Sotirios Pupakis, FIT
// Přeloženo: gcc 7.5.0

#include "myHtab.h"

htab_value_t htab_iterator_get_value(htab_iterator_t it) {
    return it.ptr->data;
}