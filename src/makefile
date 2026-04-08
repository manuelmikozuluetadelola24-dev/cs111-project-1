
SRC = src/analysis.c src/input.c src/main.c src/sort.c src/splitmix64.c src/xoshiro256plusplus.c
LIB = lib/analysis.h lib/input.h lib/main.h lib/sort.h lib/splitmix64.h lib/xoshiro256plusplus.h
FLAG = -Wall -I lib
DEBUG_FLAG = -O0 -g
CC = gcc

test: $(SRC) $(LIB)
	$(CC) -o test $(SRC) $(FLAG)

debug: $(SRC) $(LIB)
	$(CC) -o debug $(SRC) $(FLAG)

.PHONY: clean

clean:
	rm debug test

