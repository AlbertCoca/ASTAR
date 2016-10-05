#include "input.h"


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

	fp = fopen("catalunya.csv", "r");
	if(fp == NULL){
		printf("ERROR File do not exist!\n");
		abort();
	}

	i = 0;
	while(fgets(line, MAX_LINE_LEN, fp)){
		classifyLine(line, nList, i, iNode);
		i++;
	}
	
	fgets(line, MAX_LINE_LEN, fp);
	fgets(line, MAX_LINE_LEN, fp);
	fgets(line, MAX_LINE_LEN, fp);
	fgets(line, MAX_LINE_LEN, fp);
	node *n;
	n = readNode(line);
	printf("%s\n", line);
	//classifyLine(line);

	fclose(fp);

	return 0;
}