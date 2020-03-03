#include <stdio.h>

int main(){ //Dijkstra algorithm for above graph(A B C D E F G = 7 towns)
	int nGraph[7][7]; int nNodes[2][7];
	nNodes[0]={1,1,1,1,1,1,1};
	for(int i=0;i<7;i++)
		nNodes[1][i]=
	nGraph[0]={0,4,3,1000,7,1000,1000};
	nGraph[1]={0,0,6,5,1000,1000,1000};
	nGraph[2]={0,0,0,11,8,1000,1000};
	nGraph[3]={0,0,0,0,2,2,10};
	nGraph[4]={0,0,0,0,0,1000,5};
	nGraph[5]={0,0,0,0,0,0,0,3};
	nGraph[6]={0};
	int nCurrentNode=0, nGoal=5; //starting point is A(0) goal if F(5)
	while(nCurrentNode-nGoal){

	}
}