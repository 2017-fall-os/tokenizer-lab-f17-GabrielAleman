all: mytoc

CFLAGS = -g -O2

mytoc: mytoc.o test.o
	cc -o mytoc mytoc.o test.o
clean:
	rm -f *.o
