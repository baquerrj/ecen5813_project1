###################################
# Makefile for memory fun utility #
###################################

CFLAGS= -Wall -Werror -Wextra -g -std=c99

INC_DIR= ./inc
SRC_DIR= ./src
RES_DIR= ./res
OBJS= $(patsubst ./src/%.c, ./res/%.o, $(shell find . -name "*.c"))

util: $(OBJS)
	mkdir -p ./bin
	gcc -o ./bin/util $(OBJS) $(CFLAGS)

$(RES_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p ./res 
	gcc -I$(INC_DIR) $(CFLAGS) -c -o "$@" "$<"

clean: 
	rm -f ./bin/*
	rm -f ./res/*
