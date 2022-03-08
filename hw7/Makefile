CC = clang

CFLAGS = -Wall -Wpedantic -Werror -Wextra

all: hw7 tester

hw7: hw7.o
	$(CC) hw7.o -o hw7

tester: tester.o
	$(CC) hw7.o tester.o -o tester

tester.o:
	$(CC) $(CFLAGS) -c tester.c

hw7.o:
	$(CC) $(CFLAGS) -c hw7.c

clean:
	rm -f hw7.o tester.o hw7 tester

format:
	clang-format -i -style=file *.[ch]
