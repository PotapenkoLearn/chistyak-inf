main: floor.o
	gcc -g -O0 -o floor floor.o

floor.o: floor.c
	gcc -c -g -O0 -o floor.o floor.c

clean:
	rm floor *.o

indent:
	indent -kr -nut main.c