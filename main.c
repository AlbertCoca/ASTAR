#include "common.h"
#include <time.h>

int main(int argc, char* argv[]){
	printf("Initializing Vars...\n");
	node **nList;

	printf("Allocating Memory...\n");
	nList = malloc(sizeof(node*)*NODE_MAX);
	long i;

	for(i=0; i<NODE_MAX; i++){
		nodeInitialize(nList[i]);
	}

	clock_t start = clock();

	long nodes_n = loadFile("spain.csv", nList);

	printf("Time spent for loading data: %0.3f\n", (double)(clock() - start) / CLOCKS_PER_SEC);

	long origen = bs(nList, 771979683, nodes_n);
	long dest = bs(nList, 429854583, nodes_n);
	start = clock();

	nodeList *l = astar(origen, dest, nodes_n, nList);

	printf("Time spent searching: %0.3f\n", (double)(clock() - start) / CLOCKS_PER_SEC);

	printf("ASTAR Solution!\n");
	if(l==NULL)printf("No Solution!\n");
	else listPrintReal(l, nList);
	for(i=0; i<NODE_MAX; i++){
		free(nList[i]);
	}
	free(nList);
	
	return 0;
}