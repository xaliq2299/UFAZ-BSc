#include <stdio.h>
#include <stdlib.h>
#include "Maze.h"

int main(){
	Maze mz = MZ_new(8,8,MZ_HARD); // for instance a 8x8 maze of hard level
	MZ_saveImg(mz,"myFirstMaze.ppm");
	MZ_free(mz);
	
	return 0;
}
