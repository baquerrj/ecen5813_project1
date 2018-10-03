
INCLUDES= ./inc/help.h ./inc/allocate.h ./inc/getValue.h ./inc/getAddress.h ./inc/getNumber.h ./inc/writeToMemory.h ./inc/getNumberOfWords.h ./inc/getRandom.h
OBJS=  ./res/allocate.o ./res/help.o ./res/getValue.o ./res/getAddress.o ./res/getNumber.o ./res/writeToMemory.o ./res/getNumberOfWords.o ./res/getRandom.o
CFILES =  ./src/help.c ./src/allocate.c ./src/writeToMemory.c ./src/getNumber.c ./src/getNumberOfWords.c ./src/getValue.c ./src/getAddress.c ./src/getRandom.c
# make: ./src/main.c ./res/allocate.o ./res/help.o ./res/getValue.o ./res/getAddress.o ./res/getNumber.o ./res/writeToMemory.o ./res/getNumberOfWords.o $(INCLUDES)
# 	mkdir -p ./bin/
# 	gcc -o ./bin/main.o ./src/main.c -I.  -Wall -Werror -std=c99

make: ./src/main.c $(INCLUDES) $(OBJS)
	mkdir -p ./bin/
	gcc -o ./bin/main.o ./src/main.c $(CFILES) -I.  -Wall -Werror -std=c99

./res/help.o: ./src/help.c ./inc/help.h
	mkdir -p ./res/
	gcc -c -o ./res/help.o ./src/help.c -I. -Wall -Werror -std=c99

./res/getRandom.o: ./src/getRandom.c ./inc/getRandom.h
	mkdir -p ./res/
	gcc -c -o ./res/getRandom.o ./src/getRandom.c -I. -Wall -Werror -std=c99	

./res/allocate.o: ./src/allocate.c ./inc/allocate.h
	mkdir -p ./res/
	gcc -c -o ./res/allocate.o ./src/allocate.c -I. -Wall -Werror -std=c99

./res/getValue.o: ./src/getValue.c ./inc/getValue.h
	mkdir -p ./res/
	gcc -c -o ./res/getValue.o ./src/getValue.c -I. -Wall -Werror -std=c99

./res/getAddress.o: ./src/getAddress.c ./inc/getAddress.h
	mkdir -p ./res/
	gcc -c -o ./res/getAddress.o ./src/getAddress.c -I. -Wall -Werror -std=c99

./res/getNumber.o: ./src/getNumber.c ./inc/getNumber.h
	mkdir -p ./res/
	gcc -c -o ./res/getNumber.o ./src/getNumber.c -I. -Wall -Werror -std=c99

./res/writeToMemory.o: ./src/writeToMemory.c ./inc/writeToMemory.h
	mkdir -p ./res/
	gcc -c -o ./res/writeToMemory.o ./src/writeToMemory.c -I. -Wall -Werror -std=c99

./res/getNumberOfWords.o: ./src/getNumberOfWords.c ./inc/getNumberOfWords.h
	mkdir -p ./res/
	gcc -c -o ./res/getNumberOfWords.o ./src/getNumberOfWords.c -I. -Wall -Werror -std=c99

clean: 
	rm -rf ./bin
	rm -rf ./res
