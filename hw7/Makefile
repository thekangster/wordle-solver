CC = clang

CFLAGS = -Wall -Wpedantic -Werror -Wextra

all: hw7 #tester

hw7: hw7.c
	$(CC) $(CFLAGS) hw7.c -o hw7

clean:
	rm -f hw7.o tester.o hw7 tester

format:
	clang-format -i -style=file *.[ch]
