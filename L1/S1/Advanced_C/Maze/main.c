#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Maze.h"
#include "Cell.h"
#include "Stack.h"
#include "ExplorationMarker.h"
#include "Solution.h"

//functions that deal with argument problems
int argProblems(int argc, char *argv[]);
int isNumber(char *num);

int main(int argc, char **argv){
	if( argProblems(argc,argv) ) {	
		printf("PS: the args should be\n1)./maze\n"
		   	   "2)width\n3)height\n4)difficulty\n");
		return 1;
	}
	
	char filename[25], solutionFilename[35];
	strcat(filename,"Maze");
	strcat(filename,argv[1]);
	strcat(filename,"x");
	strcat(filename,argv[2]);
	
	int width = atoi(argv[1]);
	int height = atoi(argv[2]);
	char diffic = argv[3][0];
	Maze mz;

	if(diffic == 's' || diffic == 'S'){	//algorithm Simple level	
		strcat(filename,"Simple.ppm");
		mz = MZ_new(width,height,0);	
		MZ_saveImg(mz,filename);
		
		Cell entrance, exit, solution_cells[3], linked_cells_Entrance[4], linked_cells_Exit[4];	
		entrance = CL_entrance(mz);
		exit = CL_exit(mz);
		int nb_cells_Entrance = CL_linkedCells(mz,entrance,linked_cells_Entrance);
		int nb_cells_Exit = CL_linkedCells(mz,exit,linked_cells_Exit);
		for(int i=0;i<nb_cells_Entrance;i++){
			for(int j=0;j<nb_cells_Exit;j++){
				if( CL_isTheSame(linked_cells_Entrance[i], 	linked_cells_Exit[j]) )
				solution_cells[1] = linked_cells_Exit[j];
			}
		}
		solution_cells[0]=entrance;
		solution_cells[2]=exit;
		S_build(mz,solution_cells,3);
	}

	else if(diffic == 'm' || diffic == 'M'){ //algorithm Medium level	
		strcat(filename,"Medium.ppm");
		mz = MZ_new(width,height,1);
		MZ_saveImg(mz,filename);
		
		Cell entrance, exit, cur, linked_cells[2];	
		entrance = CL_entrance(mz);
		exit = CL_exit(mz);
		Stack s = ST_new(width*height);
		ExplorationMarker em = EM_new(width,height);
		
		s = ST_push(s,entrance);
		EM_mark(em,entrance);
		ST_top(s,&cur);
		while( CL_isTheSame(cur,exit) == 0 ){
			int nb_cells = CL_linkedCells(mz,cur,linked_cells);
			for(int i=0;i<nb_cells;i++){
				if(EM_isMarked(em,linked_cells[i]) == 0){
					s = ST_push(s,linked_cells[i]);
					EM_mark(em,linked_cells[i]);
				}
			}
			ST_top(s,&cur);
		}

		Cell solution_cells[s->_first_free_place];
		int size = ST_export(s,solution_cells);
		S_build(mz,solution_cells,size);
		EM_free(em);
		ST_free(s);
	}

	else if(diffic == 'h' || diffic == 'H'){ //algorithm Hard level	
		strcat(filename,"Hard.ppm");
		mz = MZ_new(width,height,2);	
		MZ_saveImg(mz,filename);
		
		Cell entrance = CL_entrance(mz);
		Cell exit = CL_exit(mz);
		Stack s = ST_new(width*height);
		ExplorationMarker em = EM_new(width,height);

		s = ST_push(s,entrance);
		EM_mark(em,entrance);
		
		while(1){
			if( S_advanceUntilBlockedOrFound(mz,s,em,exit) )
				break;
			else
				S_trackBackUntilFree(mz,s,em);
		}
		
		Cell solution_cells[s->_first_free_place];
		int size = ST_export(s,solution_cells);
		S_build(mz,solution_cells,size);
		EM_free(em);
		ST_free(s);
	}
	
	strcat(solutionFilename,"Solution");	
	strcat(solutionFilename,filename);
	MZ_saveImg(mz,solutionFilename);
	MZ_free(mz);
	
	return 0;
}

int argProblems(int argc, char *argv[]){
	if(argc != 4){
		printf("[!] There is some problem with the #of args in input.\n");
		return 1;
	}
	if( isNumber(argv[1]) == 0){
		printf("[!] The second arg has to be a number: i.e. width of the maze.\n");
		return 1;
	}
	if( isNumber(argv[2]) == 0){
		printf("[!] The third arg has to be a number: i.e. height of the maze.\n");	
		return 1;
	}
	if( argv[3][0] != 's' && argv[3][0] != 'S' &&
		argv[3][0] != 'm' && argv[3][0] != 'M' &&
		argv[3][0] != 'h' && argv[3][0] != 'H' &&
		strcmp(argv[3],"simple") != 0 &&
		strcmp(argv[3],"medium") != 0 &&
		strcmp(argv[3],"hard") != 0 &&
		strcmp(argv[3],"Simple") != 0 &&
		strcmp(argv[3],"Medium") != 0 &&
		strcmp(argv[3],"Hard") != 0 ){
			printf("[!] You entered smth wrong for difficulty\n");
			printf("There are three types only: Simple(s), Medium(m) and Hard(h).\n");
			return 1;
		}
	return 0;
}

int isNumber(char *num){
	for(int i=0;num[i] != '\0';i++){ 
		if( num[i] != 0 &&
			num[i] != 1 &&
			num[i] != 2 &&
			num[i] != 3 &&
			num[i] != 4 &&
			num[i] != 5 &&
			num[i] != 6 &&
			num[i] != 7 &&
			num[i] != 8 &&
			num[i] != 9 )	return 0;
	}
	return 1;
}
