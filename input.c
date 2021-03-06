#include "input.h"

//TODO make a function for cut string from index a to b

long loadFile(char *name, node **nList){

	long index = 0;
	FILE *fp;
	char line[MAX_LINE_LEN];
	printf("Opening File...\n");
	fp = fopen(name, "r");
	if(fp == NULL){
		printf("ERROR File do not exist!\n");
		abort();
	}

	printf("Loading File...\n");

	while(fgets(line, MAX_LINE_LEN, fp)){
		classifyLine(line, nList, &index);
	}
	fclose(fp);
	return index;
}

node* readNode(char *line){

	node *n = malloc(sizeof(node));
	n->closed = 0;

	char check[5] = {'\0'};
	strncpy(check, line, 4);
	check[4] = '\0';

	if(strcmp("node", check) == 0){

		char id[10] = {'\0'};
		int start = findIndexOfChar(line, '|', 1) + 1;
		int end = findIndexOfChar(line, '|', 2);
		strncpy(id, line + start, end - start);
		n->realId = atol(id);

		char lat[20] = {'\0'};
		start = findIndexOfChar(line, '|', 9) + 1;
		end = findIndexOfChar(line, '|', 10);
		strncpy(lat, line + start, end - start);
		n->lat = strtod(lat, NULL);

		char lon[20] = {'\0'};
		start = findIndexOfChar(line, '|', 10) + 1;
		end = strlen(line);
		strncpy(lon, line + start, end - start);
		n->lon = strtod(lon, NULL);
		n->tn = 0;
	}

	else{
		printf("This is not a node!\n");
	}
	return n;
}

void readWay(char *line, node **nList, long n){
	int i = 9;
	int start=0, end=-1;
	char id[10];
	char oneWay[6];
	memset( id, '\0', sizeof(char)*10 );
	memset( oneWay, '\0', sizeof(char)*6 );
	int ow = 0;
	long node1=-1, node2;

	end = findIndexOfChar(line, '|', i+1);
	if (end == -1) return;
	while(node1 < 0 && end >= 0){
		memset( id, '\0', sizeof(char)*10 );
		start = findIndexOfChar(line, '|', i) + 1;
		strncpy(id, line + start, end - start);
		//printf("id: %li\n", atol(id));
		node1 = bs(nList, atol(id), n);
		i++;
		end = findIndexOfChar(line, '|', i+1);
	}

	start = findIndexOfChar(line, '|', 7) + 1;
	end = findIndexOfChar(line, '|', 8);
	strncpy(oneWay, line + start, end - start);
	//printf("%s\n", oneWay);
	//printf("oneway?: %d\n", strcmp("oneway", oneWay));
	if(strcmp("oneway", oneWay)==0) ow = 1;

	while(findIndexOfChar(line, '|', i+1) > 0){
		memset( id, '\0', sizeof(char)*10 );
		start = findIndexOfChar(line, '|', i) + 1;
		end = findIndexOfChar(line, '|', i+1);
		strncpy(id, line + start, end - start);
		node2 = bs(nList, atol(id), n);
		if(node2 >= 0 ){
			if(ow==1){
				//printf("oneway!!!\n");
				nList[node1]->neighbors[nList[node1]->tn] = node2;
				nList[node1]->tn+=1;
			}
			else{
				nList[node1]->neighbors[nList[node1]->tn] = node2;
				nList[node2]->neighbors[nList[node2]->tn] = node1;
				nList[node1]->tn+=1;
				nList[node2]->tn+=1;
			}
			node1 = node2;
		}
		i++;
	}
	start = findIndexOfChar(line, '|', i) + 1;
	end = strlen(line);
	strncpy(id, line + start, end - start);
	node2 = bs(nList, atol(id), n);
	if(node2 >= 0 && node1 >= 0){
		if(ow==1){
				nList[node1]->neighbors[nList[node1]->tn] = node2;
				nList[node1]->tn+=1;
			}
			else{
				nList[node1]->neighbors[nList[node1]->tn] = node2;
				nList[node2]->neighbors[nList[node2]->tn] = node1;
				nList[node1]->tn+=1;
				nList[node2]->tn+=1;
			}
	}
}

void classifyLine(char *line, node **nList, long *i){

	switch(line[0]){
		case 'n':
			//printf("Loading node number: %d...\n", *i);
			nList[*i] = readNode(line);
			nList[*i]->id = *i;
			*i+=1;
			break;
		case 'w':
			//printf("Loading way:\n");
			readWay(line, nList, *i);
			break;
		default:
			//printf("Ignoring line...\n");
			break;
	}
}

void nodeInitialize(node *n){
	n = (node*)malloc(sizeof(node));
	n->closed = 0;
}

long bs(node **nList, int fItem, int len){
	int low = 0;
	int high = len + 1;
	int i = (len+1)/2;
	while(low <= high && nList[i]->realId != fItem){
		if(fItem > nList[i]->realId) low = i+1;
		else high = i - 1;
		i = (low+high) / 2;
	}
	//printf("i: %d\n", i);
	if(low > high){
		return -1;
	}
	return nList[i]->id;
	
}
