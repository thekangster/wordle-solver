CC = clang

CFLAGS = -Wall -Wpedantic -Werror -Wextra

all: businessdb

businessdb: hw7.o businessdb.o
	$(CC) $(CFLAGS) -o businessdb hw7.o businessdb.o

businessdb.o: businessdb.c hw7.h
	$(CC) $(CFLAGS) -c businessdb.c

clean:
	rm -f hw7.o businessdb.o hw7 businessdb

format:
	clang-format -i -style=file *.[ch]
