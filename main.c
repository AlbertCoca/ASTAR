#include "common.h"
#include <time.h>

int main(int argc, char* argv[]){
	printf("Initializing Vars...\n");
	node **nList;
	int len=3895681;

	printf("Allocating Memory...\n");
	nList = malloc(sizeof(node*)*len);
	int i;

	for(i=0; i<len; i++){
		nodeInitialize(nList[i]);
	}

	clock_t start = clock();

	int index = loadFile("cataluna.csv", nList);

	printf("Time spent for loading data: %0.3f\n", (double)(clock() - start) / CLOCKS_PER_SEC);

	//Test
	/*
	for (i = 0; i < index; ++i)
	{
		if(nList[i]->id != i){
			printf("i: %d, realId: %li, id: %li\n", i, nList[i]->realId, nList[i]->id);
		}
	}
	*/
	
	/*
	printf("Testing...\n");
	
	char way[] = "way|61943433|Carrer de Santa Clara||living_street||||20|771979683|772184663|772163132";
	char way2[] = "way|61946122|Carrer de Santa Clara||living_street|||oneway|20|771979683|772141890";
	readWay(way, nList, index);
	printf("\n");
	readWay(way2, nList, index);
	
	printf("Fail bs: %li\n", bs(nList, 11, index));

	
	node *nFound;
	int indexFound = 0;
	printf("Initial Node: %li\n", nList[2]->realId);
	indexFound = bs(nList, nList[2]->realId, index);
	nFound = nList[indexFound];
	if(nFound != NULL)
		printf("Found Node: %li\n", nFound->realId);

	printf("index: %d\n",findIndexOfChar("hola", 'c', 1));

	printf("Priting neighbors of node 0 ...\n");
	//printf("node:  771979683: %li, %li \n", bs(nList, 771979683, index), nList[bs(nList, 771979683, index)]->realId);
	for(i=0;i<nList[bs(nList, 771979683, index)]->tn; i++)printf("%li, ",nList[nList[bs(nList, 771979683, index)]->neighbors[i]]->realId);
	printf("\n");
	*/

	
	int path[10];
	path[0] = 0;
	path[1] = 5;
	path[2] = 10;
	printf("Entre 0 i 1: %f\n", h(nList[path[0]], nList[path[1]]));
	printf("Entre 1 i 2: %f\n", h(nList[path[1]], nList[path[2]]));
	printf("total: %f\n", g(nList, path, 3));

	

	printf("Heuristic function: %f\n", 	112.12*1000*h(nList[0], nList[50]));
	
	return 0;
}