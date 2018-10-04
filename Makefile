###################################
# Makefile for memory fun utility #
###################################
#Description: This is the makefile for Project 1
#Authors: Roberto Baquerizo, Vance Farren
#Tools: Make, gcc
#Links: https://www.gnu.org/software/make/manual/make.html
#
#
#


CFLAGS= -Wall -Werror -Wextra -g -std=c99

INC_DIR= ./inc
SRC_DIR= ./src
RES_DIR= ./res
OBJS= $(patsubst ./src/%.c, ./res/%.o, $(shell find . -name "*.c"))

util: $(OBJS)
	mkdir -p ./bin
	gcc -o ./bin/util $(OBJS) $(CFLAGS)

$(RES_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/%.h
	mkdir -p ./res 
	gcc -I$(INC_DIR) $(CFLAGS) -c -o "$@" "$<"

./res/main.o: ./src/main.c
	mkdir -p ./res
	gcc -I$(INC_DIR) $(CFLAGS) -c -o "$@" "$<"

test: util testscript.txt
	./bin/util < testscript.txt

clean: 
	rm -f ./bin/*
	rm -f ./res/*
