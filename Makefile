make: ./src/main.c ./inc/memoryManipulation.h
	mkdir -p ./bin/
	gcc -o ./bin/main ./src/main.c -I. -Wall -Werror -std=c99

clean: 
	rm -rf ./bin
