CC = g++
CCFLAGS = -std=c++11 -lSDL2 -lSDL2_image -L/usr/local/lib -I/usr/local/include
OFLAGS = -std=c++11 -c -I/usr/local/include

Gregori:	SDL_Context.o SDL_Context.h
	@echo Compiling Gregori...
	@$(CC) $(CCFLAGS) -o Gregori main.cpp SDL_Context.o 

SDL_Context.o: SDL_Context.cpp SDL_Context.h
	@echo Compiling SDL_Context.o...
	@$(CC) $(OFLAGS) -o SDL_Context.o SDL_Context.cpp

clean:
	@echo Cleaning up...
	@rm *.o Gregori

clean-o:
	@echo Cleaning up .o files...
	@rm *.o
