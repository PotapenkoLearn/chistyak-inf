task1: main.o
	gcc -g -O0 -o task1 main.o

main.o: main.c
	gcc -g -O0 -c main.c

clean:
	rm task1 *.o

indent:
	indent -kr -nut main.c