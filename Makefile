CC = g++
CCFLAGS = -std=c++11 -lSDL2/SDL -lSDL2/SDL_image -L/usr/local/lib -I/usr/local/include
OFLAGS = -c

Gregori:	SDL_Context.o SDL_Context.h
	$(CC) $(CCFLAGS) -o Gregori main.cpp SDL_Context.o 

SDL_Context.o: SDL_Context.cpp SDL_Context.h
	$(CC) $(CCFLAGS) $(OFLAGS) -o SDL_Context.o SDL_Context.cpp

clean:
	rm *.o Gregori
