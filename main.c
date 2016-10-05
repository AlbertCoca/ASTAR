#include "input.h"


int main(int argc, char* argv[]){
	FILE *fp;
	char line[MAX_LINE_LEN];
	node **nList;
	int len=10;

	nList = malloc(sizeof(node*)*len);
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
		nList[i] = readNode(line);
		printf("id:%lu\n", nList[i]->id);
		printf("lat:%.10f, lon:%.10f \n", nList[i]->lat, nList[i]->lon);
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