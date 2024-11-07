CC = gcc
CFLAGS = -g

all: calc

calc: rational calc.o
	$(CC) $(CFLAGS) -L./rational -lrational -o calc calc.o
	
calc.o: calc.c
	$(CC) $(CFLAGS) -I./rational -c calc.c

.PHONY: rational
rational:
	cd rational && $(MAKE)

clean:
	rm -f *.o calc
	cd rational && $(MAKE) clean
