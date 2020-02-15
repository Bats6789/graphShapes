all:
	gcc source/graphShapes.c -o executable/graphShapes -lmingw32 -mwindows -mconsole -I ./library/ -L ./library/lib/ -lSDL2main -lSDL2 -lSDL2_image
