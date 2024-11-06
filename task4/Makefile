CC = gcc
CFLAGS = -g -O0

all: primes goldbach

primes: primes.o calculate_primes.o
	$(CC) $(CFLAGS) -o primes primes.o calculate_primes.o

primes.o: primes.c calculate_primes.h
	$(CC) $(CFLAGS) -c primes.c

goldbach: goldbach.o calculate_primes.o
	$(CC) $(CFLAGS) -o goldbach goldbach.o calculate_primes.o

goldbach.o: goldbach.c calculate_primes.h
	$(CC) $(CFLAGS) -c goldbach.c

calculate_primes.o: calculate_primes.c calculate_primes.h
	$(CC) $(CFLAGS) -c calculate_primes.c

clean:
	rm -f *.o primes goldbach

indent:
	indent -kr -nut primes.c golbdach.c calculate_primes.c
