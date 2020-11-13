gol: ./src/gol.h
	gcc -c ./src/gol.c -o obj/gol.o
sprites: ./src/sprites.h
	gcc -c ./src/sprites.c -o obj/sprites.o
color-helpers: ./src/color-helpers.h
	gcc -c ./src/color-helpers.c -o obj/color-helpers.o
main: ./src/sprites.h ./src/color-helpers.h
	gcc -c ./src/main.c -o obj/main.o
all: gol sprites main color-helpers
	gcc obj/gol.o obj/sprites.o obj/color-helpers.o obj/main.o -o bin/gol -lncurses
clean:
	rm -fv ./bin/gol ./obj/*
