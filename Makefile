make: ./src/main.c ./inc/memoryManipulation.h
	gcc -o ./bin/main ./src/main.c -I. -Wall -Werror

clean: 
	rm ./bin/main.*
