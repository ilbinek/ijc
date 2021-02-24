// steg-decode.c
// Řešení IJC-DU1, příklad b), 16.3.2020
// Autor: Sotirios Pupakis, FIT
// Přeloženo: gcc 7.5
// Implementace dekódování zprávy z obrázku
//      Test ukrývání zpráv metodou podobnou steganografii - viz
//      http://en.wikipedia.org/wiki/Steganography

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bitset.h"
#include "eratosthenes.h"
#include "error.h"
#include "ppm.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        error_exit("Not enough or too many arguments provided\n");
    }

    struct ppm *img = ppm_read(argv[1]);

    if (img == NULL) {
        error_exit("Wrong format\n");
    }

    unsigned long size = img->xsize * img->ysize * 3;

    unsigned long *arr;
    bitset_alloc(arr, size);
    Eratosthenes(arr);

    bool ended = false;
    char c = '\0';
    int charCounter = 0;
    for (int i = 23; i < size; i++) {
        // am I on prime?
        if (bitset_getbit(arr, i) == 0) {
            // Get char
            char ch = img->data[i];
            // Get lsb and shift it
            char bit = 0x01 & ch;
            bit = bit << charCounter;
            // Set it as next bit in c
            c = c | bit;
            // Increment charCounter
            charCounter++;
            // Check if char is filled
            if (charCounter == 8) {
                // Print char
                printf("%c", c);
                // End?
                if (c == '\0') {
                    ended = true;
                    break;
                }
                // Reset charCounter and c
                c = '\0';
                charCounter = 0;
            }
        }
    }

    if (!ended) {
        bitset_free(arr);
        ppm_free(img);
        error_exit("NO \\0 character\n");
    }

    bitset_free(arr);
    ppm_free(img);
    return 0;
}