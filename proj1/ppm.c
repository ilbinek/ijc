// ppm.h
// Řešení IJC-DU1, příklad b), 16.3.2020
// Autor: Sotirios Pupakis, FIT
// Přeloženo: gcc 7.5
// Implementace ppm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "ppm.h"
#include "error.h"


struct ppm * ppm_read(const char * filename) {
    FILE *file = fopen(filename, "r");

    struct ppm *img;

    int xdim = 0;
    int ydim = 0;
    int color = 0;
    char f[3];

    if (file == NULL) {
        warning_msg("Coudn't open file\n");
        return NULL;
    }

    int matches = fscanf(file, "%s %d %d %d ", f, &xdim, &ydim, &color);
    if (matches != 4) {
        warning_msg("Coudn't read correctly\n");
        fclose(file);
        return NULL;
    }

    if (color > 255 || color < 0) {
        warning_msg("Wrong color range\n");
        fclose(file);
        return NULL;
    }

    if (strcmp(f, "P6") != 0) {
        warning_msg("Wrong format\n");
        return NULL;
    }

    size_t size = 3*xdim*ydim;

    img = malloc(sizeof(struct ppm) + size);

    if (img == NULL) {
        warning_msg("Coudn't allocate memory\n");
        fclose(file);
        return NULL;
    }

    img->xsize = xdim;
    img->ysize = ydim;

    size_t control = fread(img->data, sizeof(char), size, file);

    if (control != size) {
        warning_msg("Read data does not comply with calculated data length\n");
        fclose(file);
        free(img);
        return NULL;
    }

    if (fgetc(file) != EOF) {
        warning_msg("No EOF found\n");
        fclose(file);
        free(img);
        return NULL;
    }

    fclose(file);
    return img;
}

void ppm_free(struct ppm *p) {
    free(p);
}