CC := g++ -std=c++11
SRC := src/*.cpp
SDL2DIR := /opt/homebrew/Cellar/sdl2/2.24.0

all:
	$(CC) $(SRC) -I$(SDL2DIR)/include -L$(SDL2DIR)/lib -lSDL2 -o game

dev:
	make all; ./game

	
