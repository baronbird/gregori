# gregori

tiny platformer about a tiny gardener in C++ w/ SDL

developed on macOS, but will likely run in Linux as well (although I
haven't tested it)


### to compile

in order to compile this game, you must first have
[SDL](https://www.libsdl.org/) installed.

the included Makefile is configured for my system, you will probably need
to mess around with the compiler flags depending on where SDL is installed
on your system

once SDL is installed and the Makefile has been properly configured, typing
`make` in the command prompt should compile the game


### to run

in order to run the game, type `./Gregori` in the command prompt


### controls

| key        | action             |
|------------|--------------------|
| left/right | move               |
| up         | start climbing     |
| arrow keys | climb              |
| z          | jump/stop climbing |
| x          | interact           |
