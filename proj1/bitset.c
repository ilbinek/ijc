// bitset.c
// Řešení IJC-DU1, příklad a), 16.3.2020
// Autor: Sotirios Pupakis, FIT
// Přeloženo: gcc 7.5
// Zdrojový soubor pro výpočty prvočísel

#include "bitset.h"

#include "bitset.h"

extern bitset_index_t bitset_size(bitset_t name);
extern void bitset_setbit(bitset_t name, bitset_index_t index, int bit);
extern int bitset_getbit(bitset_t name, bitset_index_t index);
extern void bitset_free(bitset_t name);