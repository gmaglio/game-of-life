gol:
	gcc -c ./src/gol.c -o obj/gol.o
sprites:
	gcc -c ./src/sprites.c -o obj/sprites.o
main:
	gcc -c ./src/main.c -o obj/main.o
all: gol sprites main
	gcc obj/gol.o obj/sprites.o obj/main.o -o bin/gol -lncurses
clean:
	rm -fv ./bin/gol ./obj/*
