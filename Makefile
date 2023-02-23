-all:
	g++ "src/BaseObject.cpp" "main.cpp" -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -o main; ./main