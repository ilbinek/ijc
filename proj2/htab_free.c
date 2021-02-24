// htab_free.c
// Řešení IJC-DU2, příklad 2), 21.4.2020
// Autor: Sotirios Pupakis, FIT
// Přeloženo: gcc 7.5.0

#include <stdlib.h>
#include "myHtab.h"

void htab_free(htab_t * t) {
    htab_clear(t);
    free(t);
}