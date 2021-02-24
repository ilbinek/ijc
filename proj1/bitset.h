// bitset.h
// Řešení IJC-DU1, příklad a), 16.3.2020
// Autor: Sotirios Pupakis, FIT
// Přeloženo: gcc 7.5
// Hlavičkový soubor pro strukturu a makra

#ifndef PLS_BITSET_H
#define PLS_BITSET_H

#include <limits.h>
#include <stdlib.h>
#include "error.h"

typedef unsigned long bitset_t[];

typedef unsigned long bitset_index_t;

#define bitset_create(name, size) unsigned long name[(size / (sizeof(unsigned long) * CHAR_BIT) + (size % (sizeof(unsigned long) * CHAR_BIT) > 0 ? 2 : 1))] = {size, 0}

#define bitset_alloc(name, size)  do { \
    name = calloc((size / (sizeof(unsigned long) * CHAR_BIT) + (size % (sizeof(unsigned long) * CHAR_BIT) > 0 ? 2 : 1)), sizeof(bitset_index_t)); \
    name[0] = size; \
    } while (0)

#define BITGETHELP(name, index) (int)((name[index / (sizeof(unsigned long) * CHAR_BIT) + 1] & ((1UL << (index % (sizeof(unsigned long) * CHAR_BIT))))) != 0)

#define BITSETHELP(name, index, bit) (bit) ? (name[index / (sizeof(unsigned long) * CHAR_BIT) + 1] |= ((1UL << (index % (sizeof(unsigned long) * CHAR_BIT))))) : (name[index / (sizeof(unsigned long) * CHAR_BIT) + 1] &= ((1UL << ~(index % (sizeof(unsigned long) * CHAR_BIT)))))

#ifndef USE_INLINE

#define bitset_size(name) name[0]

#define bitset_getbit(name, index) ((index > bitset_size(name)) || index < 0) ? error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu", (bitset_index_t) index, (bitset_index_t) bitset_size(name)), 0 : BITGETHELP(name, index)

#define bitset_setbit(name, index, bit) ((index > bitset_size(name)) || index < 0) ? error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu", (bitset_index_t) index, (bitset_index_t) bitset_size(name)) : BITSETHELP(name, index, bit)

#define bitset_free(name) free(name)
#else

inline bitset_index_t bitset_size(bitset_t name) {
    return name[0];
}

inline void bitset_setbit(bitset_t name, bitset_index_t index, int bit) {
    if (index < 0 || index > bitset_size(name) - 1) {
        error_exit("bitget_setbit: Index %lu mimo rozsah 0..%lu", (bitset_index_t) index, (bitset_index_t) bitset_size(name));
    }
    BITSETHELP(name, index, bit);
}

inline int bitset_getbit(bitset_t name, bitset_index_t index) {
    if (index < 0 || index > bitset_size(name) - 1) {
        error_exit("bitget_getbit: Index %lu mimo rozsah 0..%lu", (bitset_index_t) index, (bitset_index_t) bitset_size(name));
    }
    return (BITGETHELP(name, index));
}

inline void bitset_free(bitset_t name) {
    free(name);
}

#endif //USE_INLINE

#endif //PLS_BITSET_H
