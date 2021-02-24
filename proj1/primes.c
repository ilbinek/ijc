// primes.c
// Řešení IJC-DU1, příklad a), 16.3.2020
// Autor: Sotirios Pupakis, FIT
// Přeloženo: gcc 7.5
// Implementace výpočtu prvočísel a jejich zobrazení

#include <stdio.h>
#include <time.h>
#include "bitset.h"
#include "eratosthenes.h"

#define N 500000000

int main() {
    clock_t start = clock();
    unsigned long primes[10];
    bitset_create(arr, N);

    Eratosthenes(arr);
    int j = 0;

    for (unsigned long i = N - 1; i > 1; i--) {
        if (bitset_getbit(arr, i) == 0) {
            primes[j] = i;
            j++;
            if (j == 10)
                break;
        }
    }

    for (int i = 9; i >= 0; i--) {
        printf("%ld\n", primes[i]);
    }

    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
    return 0;
}
