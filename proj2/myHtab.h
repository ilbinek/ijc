// myHtab.h
// Řešení IJC-DU2, příklad 2), 21.4.2020
// Autor: Sotirios Pupakis, FIT
// Přeloženo: gcc 7.5.0

#ifndef PROJ2_MYHTAB_H
#define PROJ2_MYHTAB_H

#include "htab.h"

struct htab_item {
    int data;
    struct htab_item *next;
    char * key;
};

struct htab {
    int size;
    int arr_size;
    struct htab_item * list[];
};

#endif //PROJ2_MYHTAB_H