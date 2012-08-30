CFLAGS=-Wall -g
LDFLAGS=-lssl

all: cloak

cloak: cloak.o hash.o

clean:
	rm -f cloak *.o
