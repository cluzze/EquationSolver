

CC=g++
CFLAGS=-g -Wall -Wextra -Werror

main.o: main.c
	$(CC) $(CFLAGS) -c $^

test.o: test.c
	$(CC) $(CFLAGS) -c $^

equation.o: equation.h helper.h equation.c
	$(CC) $(CFLAGS) -c $^

myapp: main.o equation.o
	$(CC) $(CFLAGS) -o $@ $^ -lm

test: test.o equation.o
	$(CC) $(CFLAGS) -o $@ $^ -lm

clean:
	rm myapp test output *.o *.gch