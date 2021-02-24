// ppm.h
// Řešení IJC-DU1, příklad b), 16.3.2020
// Autor: Sotirios Pupakis, FIT
// Přeloženo: gcc 7.5
// Hlavička ppm

#ifndef PLS_PPM_H
#define PLS_PPM_H

struct ppm {
    unsigned xsize;
    unsigned ysize;
    char data[];
};

struct ppm * ppm_read(const char * filename);

void ppm_free(struct ppm *p);

#endif //PLS_PPM_H
