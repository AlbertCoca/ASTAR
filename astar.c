 #include "astar.h"

// Pitagoras distance GPS
double pDistance(node *n1, node *n2){
	return sqrt(pow((n1->lon - n2->lon), 2) + pow((n1->lon - n2->lon),2));
}

double h(node *n1, node *n2){
 	return pDistance(n1, n2);
}

double g(node **nList, int *path, int len){
	int i;
	double t=0.0;
	for(i=0; i<len-1; i++){
		t+=pDistance(nList[path[i]], nList[path[i+1]]);
	}
	return t;
} 

void expandNode(node **nList, int n, int open){
	int i;
	for(i=0; i<nList[n]->tn; i++){
		
	}
}

int astar(int initNode, int endNode, int n, node **nList){
	nodeList* closedSet;
	nodeList* openSet;
	int *cameFrom;
	double *gScore;
	double *fScore;
	//Different best paths
	cameFrom = (int*) malloc(sizeof(int)*n);
	//Cost from the initial node to the index node
	gScore = (double*) malloc(sizeof(double)*n);
	//Cost + Heuristic from the initial node to the index node
	fScore = (double*) malloc(sizeof(double)*n);

	int i;
	//Closed Set
	closedSet = listInit();
	//Open Set
	openSet = listInit();

	//Adding initNode to openSet
	listAdd(openSet, initNode);
	//Setting for the initialnode cost to 0
	gScore[initNode] = 0;

	//Initializing vector fScore to -1
	for(i=0; i<n; i++)fScore[i] = -1;

	//First Value of fScore is only the heuristic (g(initNode, initNode) = 0)
	fScore[initNode] = h(nList[initNode], nList[endNode]);

	printf("Starting ASTAR!\n");

	//Compute untill we have no more nodes in the openSet
	while(openSet->n > 0){
		//Get the nomes with the lowest value in fScore
		printf("Fiding the minium...\n");
		int current = findMin(fScore, n);
		//Returning the path
		if(current == endNode)return 1;
		//Remove the current node from the open list and add it to the close list
		printf("Removing and adding to lists...\n");
		listRemoveItem(openSet, openSet->list[current]);
		listAdd(closedSet, current);

		node *curr = nList[current];
		//Sorting the lists for a faster search
		printf("Sorting the lists...\n");
		qsort(openSet->list, openSet->n, sizeof(int), cmpfunc);
		qsort(closedSet->list, closedSet->n, sizeof(int), cmpfunc);

		printf("Starting to compute the neighbors\n");
		for(i=0; i < curr->tn; i++){
			//For each neighbor we look if it is in the close list, if it's not the next neighbor
			if(bsearch(&curr->neighbors[i], closedSet->list, closedSet->n, sizeof(int), cmpfunc)==NULL){
				int tentative_gScore = gScore[curr->id] + pDistance(curr, nList[curr->neighbors[i]]);

				//if this neighbor is not in the openset then its a new node.
				if(bsearch(&curr->neighbors[i], openSet->list, openSet->n, sizeof(int), cmpfunc)==NULL){
					listAdd(openSet, curr->neighbors[i]);
					cameFrom[curr->neighbors[i]] = curr->id;
		            gScore[curr->neighbors[i]] = tentative_gScore;
	            	fScore[curr->neighbors[i]] = gScore[curr->neighbors[i]] + h(nList[curr->neighbors[i]], nList[endNode]);
				}

				//if this neighbor is in the openset then we actualize the Scores only if it's less than the previous one
				else if( tentative_gScore < gScore[curr->neighbors[i]] ){
					cameFrom[curr->neighbors[i]] = curr->id;
		            gScore[curr->neighbors[i]] = tentative_gScore;
	            	fScore[curr->neighbors[i]] = gScore[curr->neighbors[i]] + h(nList[curr->neighbors[i]], nList[endNode]);
				}
			}

		}
		
	}
	return 0;
}

nodeList* listInit(){
	nodeList* list;
	list = (nodeList*) malloc(sizeof(nodeList));
	list->n = 0;
	list->size = REALLOC_SIZE;
	list->list = (int *) malloc(sizeof(int)*REALLOC_SIZE);
	return list;
}

void listAdd(nodeList* list, int id){
	if(list->n+1 <= list->size){
		list->list[list->n] = id;
		list->n+=1;
	}
	else{
		list->list = (int *) realloc(list->list, sizeof(int)*REALLOC_SIZE);
		list->size+=REALLOC_SIZE;
		listAdd(list, id);
	}
}

void listRemoveItem(nodeList *list, int id){
	if(list->n > 1){
		qsort(list->list, list->n, sizeof(int), cmpfunc);
		int *item = (int*) bsearch (&id, list->list, list->n, sizeof(int), cmpfunc);
		list->list[item - list->list] = list->list[list->n-1];
		list->n-=1;
	}
	else list->n-=1;
}

void listPrint(nodeList *list){
	int i;
	for(i=0; i<list->n; i++){
		printf("%d, ", list->list[i]);
	}
	printf("\n");
}

//TODO: fast minium search
int findMin(double* fScore, int n){
	int i;
	int min = 0;
	for(i=0; i<n; i++){
		if(fScore[i] >= 0 && fScore[i] < fScore[min]){
			min = i;
		}
	}
	return min;
}

int cmpfunc(const void * a, const void * b)
{
	int aa = *(int*)a;
	int bb = *(int*)b;
	return ( aa - bb );
}