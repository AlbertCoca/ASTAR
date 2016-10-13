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

int* astar(node **nList, int s, int d){
	int path[100];
	int open[1000];
	path[0] = s;

}

