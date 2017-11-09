CC = g++
CCFLAGS = -Wall -std=c++11 -lSDL2 -lSDL2_image -L/usr/local/lib -I/usr/local/include
OFLAGS = -Wall -std=c++11 -c -I/usr/local/include
TARGETS = Gregori

all:	$(TARGETS)

Gregori:	SDL_Context.o Sprites.o	Game_Object.o Level.o main.cpp
	@echo Compiling Gregori...
	@$(CC) $(CCFLAGS) -o Gregori main.cpp SDL_Context.o Game_Object.o Sprites.o Level.o

%.o: %.cpp %.h
	@echo Compiling $@...
	@$(CC) $(OFLAGS) -o $@ $<

clean:
	@echo Cleaning up...
	@rm -f *.o Gregori

clean-o:
	@echo Cleaning up .o files...
	@rm -f *.o
