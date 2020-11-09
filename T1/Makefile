CFLAGS= -g -Wall -pedantic -std=c99
LDFLAGS= -g -pthread

all: test-t1

t1.o test-t1.o: t1.h

test-t1: t1.o test-t1.o

test-g:
	make clean
	make test-t1
	./test-t1

test-O:
	make clean
	make "CFLAGS=-O -Wall -pedantic -std=c99" test-t1
	./test-t1

test-O-m32:
	make clean
	make "CFLAGS=-O -m32 -Wall -pedantic -std=c99" "LDFLAGS=-m32" test-t1
	./test-t1

clean:
	rm -f *.o
	rm -f test-t1
