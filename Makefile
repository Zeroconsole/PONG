all: pong

pong: game.o graphics.o
	g++ game.o graphics.o -o pong

game.o: game.c
	g++ -c game.c

graphics.o: graphics.c
	g++ -c graphics.c

clean:
	rm -rf *o
