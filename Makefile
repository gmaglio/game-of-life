block:
	gcc -c ./src/block.c -o obj/block.o
main:
	gcc -c ./src/main.c -o obj/main.o
all: block main
	gcc obj/block.o obj/main.o -o bin/block -lncurses
clean:
	rm -fv ./bin/block ./obj/*
