make: ./src/main.c ./inc/helper.h
	mkdir -p ./bin/
	gcc -o ./bin/main ./src/main.c -I.

clean: 
	rm -rf ./bin/
