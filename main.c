#include "common.h"

int main(int argc, char* argv[]){
	printf("Initializing Vars...\n");
	FILE *fp;
	char line[MAX_LINE_LEN];
	node **nList;
	int *iNode;
	int len=3895681;

	printf("Allocating Memory...\n");
	nList = malloc(sizeof(node*)*len);
	iNode = (int*)malloc(sizeof(int)*len);
	int i;
	for(i=0; i<len; i++){
		nList[i] = (node*)malloc(sizeof(node));
	}

	printf("Opening File...\n");
	fp = fopen("cataluna.csv", "r");
	if(fp == NULL){
		printf("ERROR File do not exist!\n");
		abort();
	}

	printf("Loading File...\n");

	int index = 0;
	while(fgets(line, MAX_LINE_LEN, fp)){
		classifyLine(line, nList, &index, iNode);
	}

	printf("Testing...\n");
	char way[] = "way|32020614|||residential|||||359178404|359178420|359178417|359178402|359178415|359178413|359178397|359178411|359178408|359178406|359178399|359178404";
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

	for(i=0;i<nList[0]->tn; i++)printf("%lu, ",nList[0]->neighbors[i]);
	printf("\n");

	fclose(fp);

	return 0;
}
