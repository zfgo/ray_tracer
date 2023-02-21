CC 			= gcc
CFLAGS 		= -Wall -g -I./src
LIBS 		= -lm
OBJECTS		= vector.o
PROGRAMS 	= main tests
BIN 		= ./bin
BUILD		= ./build

all: $(PROGRAMS)

main: main.o $(OBJECTS)
	$(CC) src/main/main.c -o main $(CFLAGS) $(LIBS)

tests: test_all.o $(OBJECTS)
	$(CC) src/tests/test_all.c -o tests $(CFLAGS) $(LIBS)

main.o: main.c vector.h
test_all.o: test_all.c test_vector.h vector.h
vector.o: vector.c vector.h

clean:
	rm -rf $(PROGRAMS) *.o
