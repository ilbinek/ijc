CC=gcc
CFLAGS=-O2 -g -std=c99 -pedantic -Wall -Wextra
SOURCE=tail.o

all: tail wordcount wordcount-dynamic

tail: $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o tail

tail.o: tail.c
	$(CC) -c tail.c

wordcount: wordcount.o libhtab.a
	$(CC) $(CFLAGS) $^ -o $@

wordcount-dynamic: wordcount.o libhtab.so
	$(CC) $(CFLAGS) $^ -o $@

libhtab.a: htab_begin.o htab_bucket_count.o htab_clear.o htab_create.o htab_end.o htab_erase.o htab_find.o htab_free.o htab_hash_fun.o htab_iterator_get_key.o htab_iterator_get_value.o htab_iterator_next.o htab_iterator_set_value.o htab_lookup_add.o htab_size.o
	ar rcs libhtab.a $^

libhtab.so: htab_begin.o htab_bucket_count.o htab_clear.o htab_create.o htab_end.o htab_erase.o htab_find.o htab_free.o htab_hash_fun.o htab_iterator_get_key.o htab_iterator_get_value.o htab_iterator_next.o htab_iterator_set_value.o htab_lookup_add.o htab_size.o
	$(CC) $(CFLAGS) -fPIC -shared $^ -o $@

%.o: %.c htab.h myHtab.h
	$(CC) $(CFLAGS) -fPIC -c $<

clean:
	rm *.o
	rm tail
	rm wordcount
	rm wordcount-dynamic
	rm libhtab.a
	rm libhtab.so

zip:
	zip xpupak01.zip *.c *.cc *.h Makefile
