#include "common.h"

int cmpfunc(const void *n1, const void *n2)
{
	printf("hola\n");
	printf("ptr n1: %p\n", n1);
	printf("ptr n2: %p\n", n2);
	const node *nn1 = (node*)n1; 
	const node *nn2 = (node*)n2;
	printf("%lu\n", nn1->id);
	printf("%lu\n", nn2->id);
	printf("\n");
	return nn1->id - nn2->id; 
} 

int main(int argc, char* argv[]){
	FILE *fp;
	char line[MAX_LINE_LEN];
	node **nList;
	int *iNode;
	int len=100000000;

	nList = malloc(sizeof(node*)*len);
	iNode = (int*)malloc(sizeof(int)*len);
	int i;
	for(i=0; i<len; i++){
		nList[i] = (node*)malloc(sizeof(node));
	}

	fp = fopen("cataluna.csv", "r");
	if(fp == NULL){
		printf("ERROR File do not exist!\n");
		abort();
	}

	int index = 0;
	while(fgets(line, MAX_LINE_LEN, fp)){
		classifyLine(line, nList, &index, iNode);
		//printf("%d\n", index);
		//printf("id: %d\n", iNode[index-1]);
	}
	node *nFound;
	printf("Initial Node: %lu\n", nList[2]->id);
	printf("Initial Node ptr: %p\n", nList);
	nFound = bsearch (nList[2], nList, index, sizeof(node*), cmpfunc);
	printf("%lu\n", (long)nList[2]);
	if(nFound != NULL)
		printf("Found Node: %f\n", nFound->lat);

	fclose(fp);

	return 0;
}