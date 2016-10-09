#include "input.h"

node* readNode(char *line){

	node *n = malloc(sizeof(node));

	char check[5];
	strncpy(check, line, 4);
	check[4] = '\0';

	if(strcmp("node", check) == 0){

		char id[10] = {0};
		int start = findIndexOfChar(line, '|', 1) + 1;
		int end = findIndexOfChar(line, '|', 2);
		strncpy(id, line + start, end - start);
		n->realId = atoi(id);

		char lat[20] = {'a'};
		start = findIndexOfChar(line, '|', 9) + 1;
		end = findIndexOfChar(line, '|', 10);
		strncpy(lat, line + start, end - start);
		n->lat = strtod(lat, NULL);

		char lon[20];
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

void readWay(char *line, node **nList, int n){
	int i = 9;
	int start=0, end=0;
	char id[10] = {'0'};
	int node1, node2;
	start = findIndexOfChar(line, '|', i) + 1;
	end = findIndexOfChar(line, '|', i+1);
	strncpy(id, line + start, end - start);
	node1 = bs(nList, atoi(id), n);
	while(findIndexOfChar(line, '|', i+1) > 0){
		start = findIndexOfChar(line, '|', i) + 1;
		end = findIndexOfChar(line, '|', i+1);
		strncpy(id, line + start, end - start);
		node2 = bs(nList, atoi(id), n);
		if(node2 != -1){
			nList[node1]->neighbors[nList[node1]->tn] = node2;
			nList[node2]->neighbors[nList[node2]->tn] = node1;
			nList[node1]->tn+=1;
			nList[node2]->tn+=1;
			node1 = node2;
		}
		i++;
	}
}

void classifyLine(char *line, node **nList, int *i, int* iNode){

	switch(line[0]){
		case 'n':
			//printf("Loading node number: %d...\n", *i);
			nList[*i] = readNode(line);
			iNode[*i] = nList[*i]->id;
			nList[*i]->id = *i;
			*i+=1;
			break;
		case 'w':
			//printf("Loading way:\n");
			//readWay(line, nList, *i);
			break;
		default:
			printf("Ignoring line...\n");
			break;
	}
}
