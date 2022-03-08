CC = clang

CFLAGS = -Wall -Wpedantic -Werror -Wextra

all: tester

tester: hw7.o tester.o
	$(CC) $(CFLAGS) -o tester hw7.o tester.o

tester.o: hw7.c hw7.h
	$(CC) $(CFLAGS) -c tester.c

clean:
	rm -f hw7.o tester.o hw7 tester

format:
	clang-format -i -style=file *.[ch]
