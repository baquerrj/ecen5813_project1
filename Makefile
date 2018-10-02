###################################
# Makefile for memory fun utility #
###################################

CFLAGS= -Wall -Werror -Wextra -g -std=c99

INCLUDES= ./inc/help.h ./inc/allocate.h ./inc/getValue.h ./inc/getAddress.h \
			 ./inc/getNumber.h ./inc/writeToMemory.h ./inc/getNumberOfWords.h

OBJS= ./res/main.o ./res/help.o ./res/allocate.o ./res/getValue.o \
	  	./res/getAddress.o ./res/getNumber.o ./res/writeToMemory.o ./res/getNumberOfWords.o

util: $(OBJS)
	mkdir -p ./bin
	gcc -o ./bin/util $(OBJS) $(CFLAGS)

./res/main.o: ./src/main.c
	mkdir -p ./res
	gcc -c -o ./res/main.o ./src/main.c -I $(CFLAGS)

./res/help.o: ./src/help.c ./inc/help.h
	mkdir -p ./res
	gcc -c -o ./res/help.o ./src/help.c -I. $(CFLAGS)

./res/allocate.o: ./src/allocate.c ./inc/allocate.h
	mkdir -p ./res
	gcc -c -o ./res/allocate.o ./src/allocate.c -I. $(CFLAGS)

./res/getValue.o: ./src/getValue.c ./inc/getValue.h
	mkdir -p ./res
	gcc -c -o ./res/getValue.o ./src/getValue.c -I. $(CFLAGS)

./res/getAddress.o: ./src/getAddress.c ./inc/getAddress.h
	mkdir -p ./res
	gcc -c -o ./res/getAddress.o ./src/getAddress.c -I. $(CFLAGS)

./res/getNumber.o: ./src/getNumber.c ./inc/getNumber.h
	mkdir -p ./res
	gcc -c -o ./res/getNumber.o ./src/getNumber.c -I. $(CFLAGS)

./res/writeToMemory.o: ./src/writeToMemory.c ./inc/writeToMemory.h
	mkdir -p ./res
	gcc -c -o ./res/writeToMemory.o ./src/writeToMemory.c -I. $(CFLAGS)

./res/getNumberOfWords.o: ./src/getNumberOfWords.c ./inc/getNumberOfWords.h
	mkdir -p ./res
	gcc -c -o ./res/getNumberOfWords.o ./src/getNumberOfWords.c -I. $(CFLAGS)

clean: 
	rm -rf ./bin
	rm -rf ./res
