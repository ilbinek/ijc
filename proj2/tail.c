// tail.c
// Řešení IJC-DU2, příklad 1), 07.4.2020
// Autor: Sotirios Pupakis, FIT
// Přeloženo: gcc 7.5.0
// Úkol a, který napodobuje shell program "tail", akorát implementován v jazyce C.
// Limit for max line length is 2047 characters + '\n'

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_LENGTH 2048

int main(int argc, char *argv[]) {
    // Basic variables to be parsed as parameters
    int numbered = 0;
    int skip = 0;
    int n = 10;
    int err = 0;
    FILE *f = NULL;

    // Parsing of parameters
    int iterator = 1;
    while (iterator < argc) {
        if (strcmp("-n", argv[iterator]) == 0) {
            numbered = 1;
            iterator++;
            if (iterator == argc) {
                err = 1;
                break;
            }
            long x = strtol(argv[iterator], NULL, 10);
            if (x <= 0) {
                err = 1;
                break;
            } else if (x <= INT_MAX) {
                n = (int) x;
            } else {
                err = 2;
                break;
            }
        } else {
            if (strcmp("+n", argv[iterator]) == 0) {
                skip = 1;
                iterator++;
                if (iterator == argc) {
                    err = 1;
                    break;
                }
                long x = strtol(argv[iterator], NULL, 10);
                if (x <= 0) {
                    err = 1;
                    break;
                } else if (x <= INT_MAX) {
                    n = (int) x;
                } else {
                    err = 2;
                    break;
                }
        } else {
                f = fopen(argv[iterator], "r");
                if (f == NULL) {
                    err = 3;
                    break;
                }
            }
        }
        iterator++;
    }

    switch (err) {
        case 1:
            fprintf(stderr, "Could not parse value or was less or equal to zero.");
            if (f != NULL) {
                fclose(f);
            }
            printf("\n");
            return 1;

        case 2:
            fprintf(stderr, "Specified length is too long. Could not parse.");
            if (f != NULL) {
                fclose(f);
            }
            printf("\n");
            return 2;

        case 3:
            fprintf(stderr, "Couldn't not open file. Check filename and file directory.");
            if (f != NULL) {
                fclose(f);
            }
            printf("\n");
            return 3;

        default:;
    }

    // Check if reading from  file
    FILE *pnt = stdin;
    if (f != NULL) {
        pnt = f;
    }

    if (skip == 1) {
        int i = 0;
        char *line = malloc(sizeof(char) * MAX_LENGTH);
        if (line == NULL) {
            fprintf(stderr, "Could not allocate memory!");
            exit(1);
        }
        while (fgets(line, MAX_LENGTH, pnt) != NULL) {
            i++;
            if (i == n) {
                break;
            }
        }

        while (fgets(line, MAX_LENGTH, pnt) != NULL) {
            printf("%s", line);
        }

        free(line);
        // Check to close file
        if (f != NULL) {
            fclose(f);
        }
    } else {
        // Create buffer and allocate it
        char *lines[n];
        for (int i = 0; i < n; ++i) {
            char *ptr = NULL;
            ptr = malloc(sizeof(char) * MAX_LENGTH);
            while (ptr == NULL) {
                fprintf(stderr, "Could not allocate memory, trying again.");
                ptr = malloc(sizeof(char) * MAX_LENGTH);
            }
            lines[i] = ptr;
        }

        int offset = 0;
        int iHelper = 0;

        while (fgets(lines[iHelper], MAX_LENGTH, pnt) != NULL) {
            // Check if there is \n character
            int success = 0;
            for (int i = 0; i < MAX_LENGTH; ++i) {
                if (lines[iHelper][i] == '\n') {
                    success = 1;
                    break;
                }
            }

            if (success == 0) {
                fprintf(stderr, "Error, line exceeded maximal length.\n");
                lines[iHelper][MAX_LENGTH - 2] = '\n';
                while (1) {
                    char * ptr = malloc(sizeof(char) * MAX_LENGTH);
                    int suc = 0;

                    if (fgets(ptr, MAX_LENGTH, pnt) == NULL) {
                        break;
                    }
                    for (int i = 0; i < MAX_LENGTH; ++i) {
                        if (ptr[i] == '\n') {
                            suc = 1;
                            break;
                        }
                    }

                    free(ptr);

                    if (suc == 1) {
                        break;
                    }
                }

            }

            iHelper++;
            if (iHelper >= n) {
                iHelper = 0;
            }
        }

        if (iHelper == 0) {
            offset = n;
        } else {
            offset = iHelper;
        }

        for (int i = 0; i < n; ++i) {
            int index = offset + i;
            if (index >= n) {
                index -= n;
            }
            printf("%s", lines[index]);

            if (i == n - 1) {
                for (int j = 0; j < MAX_LENGTH; ++j) {
                    if (lines[index][j] == '\n')
                        break;
                    if (lines[index][j] == '\0')
                        printf("\n");
                }
            }
        }

        // Check to close file
        if (f != NULL) {
            fclose(f);
        }

        // Free buffer
        for (int i = 0; i < n; ++i) {
            free(lines[i]);
        }
    }


    return 0;
}