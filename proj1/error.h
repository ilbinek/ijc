// error.h
// Řešení IJC-DU1, příklad b), 16.3.2020
// Autor: Sotirios Pupakis, FIT
// Přeloženo: gcc 7.5
// Hlavičkový soubor pro výpis chybových hlášek

#ifndef PROJ1_ERROR_H
#define PROJ1_ERROR_H

// Prints warning message
void warning_msg(const char *fmt, ...);

// Prints error message and exits the program
void error_exit(const char *fmt, ...);

#endif //PROJ1_ERROR_H
