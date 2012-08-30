CFLAGS=-Wall -g
LDFLAGS=-lssl

all: cloak decloak

cloak: cloak.o hash.o

decloak: decloak.o hash.o

clean:
	rm -f cloak decloak *.o
