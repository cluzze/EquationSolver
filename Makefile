

CC=g++
CFLAGS=-g -Wall -Wextra

main.o: main.cpp
	$(CC) $(CFLAGS) -c $^

# test.o: test.cpp
# 	$(CC) $(CFLAGS) -c $^

equation.o: equation.h helper.h equation.cpp
	$(CC) $(CFLAGS) -c $^

myapp: main.o equation.o
	$(CC) $(CFLAGS) -o $@ $^ -lm

# test: test.o equation.o
# 	$(CC) $(CFLAGS) -o $@ $^ -lm

clean:
	rm myapp test *.o *.gch