make: ./src/main.c ./inc/memoryManipulation.h
	gcc -o ./bin/main ./src/main.c -I.

clean: 
	rm ./bin/main.o
