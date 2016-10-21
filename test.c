#include "common.h"
#include <time.h>

int main(int argc, char* argv[]){
	printf("Initializing Vars...\n");
	node **nList;

	printf("Allocating Memory...\n");
	nList = malloc(sizeof(node*)*NODE_MAX);
	int i=0;

	for(i=0; i<NODE_MAX; i++){
		nodeInitialize(nList[i]);
	}
	char line [] = "node|8670491||||||||41.2319821|1.690731\0";
	int n=0;
	classifyLine(line, nList, &n);
	if(nList[0]->id != 0)printf("ERROR Initializing syntetic id. \n");
	else if (nList[0]->realId != 8670491) printf("ERROR Initializing real id. \n");
	else if (nList[0]->lat != 41.2319821) printf("ERROR Initializing latitude. \n");
	else if (nList[0]->lon != 1.690731) printf("ERROR Initializing longitude. \n");
	else printf("Loading node TEST: \t \t PASSED\n");

	classifyLine ("node|8670492||||||||41.2324218|1.6907178\0", nList, &n);
	classifyLine ("node|8773162||||||||41.2318788|1.6907711\0", nList, &n);
	classifyLine ("way|8242904|||unclassified|||||8773161|8773162|8670491|8670492\0", nList, &n);

	if (nList[0]->tn != 2) printf("ERROR Total number %li of neighbors not consistent. \n", nList[0]->tn);
	else if (nList[nList[0]->neighbors[0]]->realId != 8773162) printf("ERROR neighbors 0 not consistent. \n");
	else if (nList[nList[0]->neighbors[1]]->realId != 8670492) printf("ERROR neighbors 1 not consistent. \n");
	else printf("Loading way TEST: \t \t PASSED\n");
	





	//int nodes_n = loadFile("cataluna.csv", nList);

	//Test
	/*
	for (i = 0; i < nodes_n; ++i)
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
	readWay(way, nList, nodes_n);
	printf("\n");
	readWay(way2, nList, nodes_n);
	
	printf("Fail bs: %li\n", bs(nList, 11, nodes_n));

	
	node *nFound;
	int nodes_nFound = 0;
	printf("Initial Node: %li\n", nList[2]->realId);
	nodes_nFound = bs(nList, nList[2]->realId, nodes_n);
	nFound = nList[nodes_nFound];
	if(nFound != NULL)
		printf("Found Node: %li\n", nFound->realId);

	printf("nodes_n: %d\n",findnodes_nOfChar("hola", 'c', 1));

	printf("Priting neighbors of node 0 ...\n");
	//printf("node:  771979683: %li, %li \n", bs(nList, 771979683, nodes_n), nList[bs(nList, 771979683, nodes_n)]->realId);
	for(i=0;i<nList[bs(nList, 771979683, nodes_n)]->tn; i++)printf("%li, ",nList[nList[bs(nList, 771979683, nodes_n)]->neighbors[i]]->realId);
	printf("\n");
	*/

	/*
	int path[10];
	path[0] = 0;
	path[1] = 5;
	path[2] = 10;
	printf("Entre 0 i 1: %f\n", h(nList[path[0]], nList[path[1]]));
	printf("Entre 1 i 2: %f\n", h(nList[path[1]], nList[path[2]]));
	printf("total: %f\n", g(nList, path, 3));

	nodeList *l = astar(1, 50, nodes_n, nList);
	printf("ASTAR Solution!\n");
	listPrint(l);

	
	//Dynamic list test
	printf("Testing List..\n");
	*/
	/*
	for(i=0; i<200; i++){
		printf("%d\n", i);
		listAdd(list, i);
	}
	listPrint(list);
	for(i=0; i<200; i++){
		printf("%d\n", i);
		listRemoveItem(list, i+1);
	}
	listPrint(list);
	*/

	//printf("Heuristic function: %f\n", 	112.12*1000*h(nList[0], nList[50]));
	
	return 0;
}