#include <stdio.h>
#include <stdlib.h>
#include "Maze.h"
#include "Cell.h"
#include "Stack.h"
#include "ExplorationMarker.h"
#include "Solution.h"
#include "DistField.h"
#define WIDTH 8
#define HEIGHT 8

int main()
{	/*				
	Maze mz = MZ_new(WIDTH,HEIGHT,MZ_HARD); // for instance a 8x8 maze of hard level 
	MZ_saveImg(mz,"myFirstMaze.ppm");
	//MZ_free(mz);

	char label;
  	int is_random, num;
	
	Cell start = CL_entrance(mz);
	Cell exit = CL_exit(mz);
	
	// declaring stack
	StructStack st;
	Stack s;
	s=&st;
	*s = *ST_new(WIDTH*HEIGHT);
	
	//Stack s = ST_new(WIDTH*HEIGHT);

	// declaring explorationmarker
	StructExplorationMarker ie; 
	ExplorationMarker em;
	em=&ie;
	*em = *EM_new(HEIGHT, WIDTH);
	
	//ExplorationMarker em = EM_new(HEIGHT,WIDTH);
	
	// start will be in our solution directly		
	s = ST_push(s, start);
	EM_mark(em, start);

	// algorithm
	while(1)
	{
		num = S_advanceUntilBlockedOrFound(mz, s, em, exit, is_random);

		if(num == 0)
			S_trackBackUntilFree(mz, s, em);
		else
			break;
	}

	//final stage
	CL_setSolution(mz, s->_array, s->_first_free_place);
	MZ_saveImg(mz, "maze.ppm");
	*/
	
	//this is the exam part, previous is my maze project
	/*
	DistField df = DF_new(WIDTH, HEIGHT);
	DF_show(df, "first");
	printf("%d\n", DF_get(df, 7, 8) );
	DF_set(df, 7, 8, 85);
	printf("%d\n", DF_get(df, 7, 8) );
	*/
	DistField df = DF_new(WIDTH, HEIGHT);
	
	
	return 0;
}
