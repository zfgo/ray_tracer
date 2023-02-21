CC 			= gcc
CFLAGS 		= -Wall -g -I./src
LIBS 		= -lm
OBJECTS		= vector.o
PROGRAMS 	= main tests
BIN 		= ./bin
BUILD		= ./build

all: $(PROGRAMS)

main:
	$(CC) src/main.c -o main $(CFLAGS) $(LIBS)

tests:
	$(CC) tests/tests.c -o tests $(CFLAGS) $(LIBS)

vector.o: vector.c vector.h

clean:
	rm -rf $(PROGRAMS) *.o
