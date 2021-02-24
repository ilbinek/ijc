# Makefile
# Řešení IJC-DU1, příklad b), 16.3.2020
# Autor: Sotirios Pupakis, FIT
# Makefile

CC=gcc
CFLAGS=-O2 -g -std=c11 -pedantic -Wall -Wextra
SOURCE=primes.o error.o eratosthenes.o
SOURCE2=steg-decode.o error.o eratosthenes.o ppm.o

all: primes primes-i steg-decode

primes: $(SOURCE) bitset.h
	$(CC) $(CFLAGS) $(SOURCE) -o primes -lm

primes-i: $(SOURCE) bitset.o
	$(CC) $(CFLAGS) -DUSE_INLINE $(SOURCE) bitset.o -o primes-i -lm

steg-decode: $(SOURCE2) bitset.h
	$(CC) $(CFLAGS) $(SOURCE2) -o steg-decode -lm

primes.o: primes.c
	$(CC) -c primes.c

error.o: error.c error.h
	$(CC) -c error.c

eratosthenes.o: eratosthenes.c eratosthenes.h
	$(CC) -c eratosthenes.c

bitset.o: bitset.c bitset.h
	$(CC) -DUSE_INLINE -c bitset.c

steg-decode.o: steg-decode.c
	$(CC) -c steg-decode.c

ppm.o: ppm.c ppm.h
	$(CC) -c ppm.c

run: primes primes-i
	./primes
	./primes-i

clean:
	rm primes
	rm primes-i
	rm steg-decode
	rm *.o

zip:
	zip xpupak01.zip *.c *.h Makefile