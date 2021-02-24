// rratosthenes.c
// Řešení IJC-DU1, příklad a), 16.3.2020
// Autor: Sotirios Pupakis, FIT
// Přeloženo: gcc 7.5
// Zdrojový soubor inline funkce

#include <math.h>
#include <stdio.h>
#include "eratosthenes.h"

void Eratosthenes(bitset_t arr) {
    // size
    unsigned long size = bitset_size(arr);
    // count limit
    unsigned long limit = sqrt(size);

    bitset_setbit(arr, 0, 1);
    bitset_setbit(arr, 1, 1);

    // eratosthenes
    for (unsigned long i = 2; i <= limit; i++) {
        if (bitset_getbit(arr, i) == 0) {
            for (unsigned long j = 2; j*i < size; j++) {
                bitset_setbit(arr, j*i, 1);
            }
        }
    }
}