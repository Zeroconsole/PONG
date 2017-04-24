all: pong

pong: Game.o graphics.o
	g++ Game.o graphics.o -o pong

Game.o: Game.c
	g++ -c Game.c

graphics.o: graphics.c
	g++ -c graphics.c

clean:
	rm -rf *o
