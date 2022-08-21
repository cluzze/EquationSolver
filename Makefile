

CC=g++
CFLAGS=-g -Wall -Wextra -Werror

main.o: main.cpp
	$(CC) $(CFLAGS) -c $^

equation.o: equation.h helper.h equation.cpp
	$(CC) $(CFLAGS) -c $^

myapp: main.o equation.o
	$(CC) $(CFLAGS) -o $@ $^ -lm

clean:
	rm myapp *.o *.gch