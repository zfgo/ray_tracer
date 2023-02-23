CC 			= gcc
CFLAGS 		= -Wall -g -I./src
LIBS 		= -lm
BIN 		= ./bin/main
BUILD		= ./build
SRCS		= $(shell find . -name '*.c' -not -path './src/tests/*')
OBJECTS		= $(patsubst %.c, $(BUILD)/%.o, $(SRCS))
#PROGRAMS 	= main tests

all: $(BIN) $(BIN_TESTS)

$(BUILD)/%.o: %.c $(BUILD)
	@mkdir -p '$(@D)'
	$(info CC $<)
	@$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)

$(BIN): $(OBJECTS) $(BUILD)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LIBS)

#$(BUILD_TESTS)/%.o: %.c $(BUILD_TESTS) $(BUILD)
#	@mkdir -p '$(@D)'
#	$(info CC $<)
#	@$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)
#
#$(BIN_TESTS): $(OBJECTS) $(BUILD_TESTS) $(BUILD)
#	@$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LIBS)
#main: main.o $(OBJECTS)
#	$(CC) src/main/main.c -o main $(CFLAGS) $(LIBS)

#tests: test_all.o $(OBJECTS)
#	$(CC) src/tests/test_all.c -o tests $(CFLAGS) $(LIBS)

#main.o: main.c vector.h
#test_all.o: test_all.c test_vector.h vector.h
#vector.o: vector.c vector.h

clean:
	rm -rf ./bin/* ./build/*
