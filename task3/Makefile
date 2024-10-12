CC = gcc
CFLAGS = -g -O0 -o

main: main.o
	$(CC) $(CFLAGS) main main.o

main.o: main.c
	$(CC) -c $(CFLAGS) main.o main.c

clean:
	rm *.o main

indent:
	indent -kr -nut main.c