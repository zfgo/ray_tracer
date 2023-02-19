CC = gcc
CFLAGS = -g -Wall
LIBS = -lm
PROGRAMS = main.out tests.out

all: $(PROGRAMS)

main:
	$(CC) src/main.c -o main $(CFLAGS) $(LIBS)

tests:
	$(CC) tests/tests.c -o tests $(CFLAGS) $(LIBS)

clean:
	rm -rf $(PROGRAMS) *.o
