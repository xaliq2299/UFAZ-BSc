#define DF_INFINITY 1000000
#define TRUE 1
#define FALSE 0

typedef unsigned char bool;

//2D array of integers
typedef struct df
{
	int width, height;
	int **array;		
}DistField;

DistField DF_new(int Nx, int Ny);
int DF_get(DistField df, int x, int y);
void DF_set(DistField df, int x, int y, int val);
void DF_show(DistField df, char *label);
bool DF_backTrackUntilFree(Maze mz, DistField df, Stack ds);
void DF_propagateUntilDeadEnd(Maze mz, DistField df, Stack ds);
bool DF_propagatableLinkedCell(Maze mz, DistField df, Cell c, Cell *lnkneigh);
bool DF_propogate(DistField df, Cell c1, Cell c2);
