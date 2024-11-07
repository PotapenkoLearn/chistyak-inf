CC = gcc
CFLAGS = -fPIC -g -c
LIBNAME = librational

all: $(LIBNAME).so

rational.o: rational.c rational.h
	$(CC) $(CFLAGS) rational.c

rat_math.o: rat_math.c rational.h
	$(CC) $(CFLAGS) rat_math.c

rat_io.o: rat_io.c rational.h
	$(CC) $(CFLAGS) rat_io.c

$(LIBNAME).so: rational.o rat_math.o rat_io.o
	$(CC) -shared -o $(LIBNAME).so rational.o rat_math.o rat_io.o

clean:
	rm -f *.o $(LIBNAME).so