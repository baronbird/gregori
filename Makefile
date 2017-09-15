SRC = main.cpp
DST = Gregori
LIBS = SDL_inits.h gregori.h

$(DST) : $(SRC) $(LIBS)
	g++ -std=c++11 -lSDL2 -lSDL2_image -L/usr/local/lib -I/usr/local/include $(SRC) -o $(DST)

clean:
	rm Gregori
