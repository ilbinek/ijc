// htab_hash_fun.c
// Řešení IJC-DU2, příklad 2), 21.4.2020
// Autor: Sotirios Pupakis, FIT
// Přeloženo: gcc 7.5.0

#include <stdint.h>
#include "myHtab.h"

size_t htab_hash_fun(htab_key_t str) {
    uint32_t h = 0;
    const unsigned char *p;
    for (p = (const unsigned char*) str; *p != '\0'; p++) {
        h = 65599 * h + *p;
    }
    return h;
}