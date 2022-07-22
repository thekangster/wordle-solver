CC = clang

CFLAGS = -Wall -Wpedantic -Werror -Wextra

all: solver

solver: search_util.o solver.o
	$(CC) search_util.o solver.o -o solver

search_util.o:
	$(CC) $(CFLAGS) -c search_util.c

solver.o:
	$(CC) $(CFLAGS) -c solver.c

clean:
	rm -f search_util.o solver.o solver

format:
	clang-format -i -style=file *.[ch]
