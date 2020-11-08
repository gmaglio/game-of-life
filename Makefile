block:
	gcc -c ./src/block.c -o obj/block.o
sprites:
	gcc -c ./src/sprites.c -o obj/sprites.o
main:
	gcc -c ./src/main.c -o obj/main.o
all: block sprites main
	gcc obj/block.o obj/sprites.o obj/main.o -o bin/block -lncurses
clean:
	rm -fv ./bin/block ./obj/*
