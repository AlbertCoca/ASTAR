#include "common.h"

int main(int argc, char* argv[]){
	printf("Initializing Vars...\n");
	node **nList;
	int len=3895681;

	printf("Allocating Memory...\n");
	nList = malloc(sizeof(node*)*len);
	int i;

	for(i=0; i<len; i++){
		nList[i] = (node*)malloc(sizeof(node));
	}

	int index = loadFile("cataluna.csv", nList);

	printf("Testing...\n");
	char way[] = "way|4079460|||residential|||oneway||1084302703|1084302835|21638796|21638797|21638730|21638807|21638729|1084302219|1084302697";
	printf("%s\n", way);
	readWay(way, nList, index);
	
	node *nFound;
	int indexFound = 0;
	printf("Initial Node: %lu\n", nList[2]->realId);
	indexFound = bs(nList, nList[2]->realId, index);
	nFound = nList[indexFound];
	if(nFound != NULL)
		printf("Found Node: %lu\n", nFound->realId);

	printf("index: %d\n",findIndexOfChar("hola", 'c', 1));

	printf("Priting neighbors of node 0...\n");
	for(i=0;i<nList[0]->tn; i++)printf("%lu, ",nList[0]->neighbors[i]);
	printf("\n");

	printf("Heuristic function: %f\n", 	h(nList[0], nList[1]));

	return 0;
}
