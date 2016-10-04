#include "input.h"


int main(int argc, char* argv[]){
	FILE *fp;
	char line[5000];

	fp = fopen("cataluna.csv", "r");
	if(fp == NULL){
		printf("ERROR File do not exist!\n");
		abort();
	}

	fgets(line,5000, fp);
	fgets(line,5000, fp);
	fgets(line,5000, fp);
	fgets(line,5000, fp);

	readNode(fp);

	fclose(fp);

	return 0;
}