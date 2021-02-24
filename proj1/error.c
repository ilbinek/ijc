// error.c
// Řešení IJC-DU1, příklad b), 16.3.2020
// Autor: Sotirios Pupakis, FIT
// Přeloženo: gcc 7.5
// Implementace výpisu chybových hlášek

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void warning_msg(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, ap);
    va_end(ap);
}

void error_exit(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    exit(1);
}