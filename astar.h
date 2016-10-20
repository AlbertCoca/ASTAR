#include "input.h"
#include <math.h>

#define REALLOC_SIZE 100

typedef struct{
	int size;
	int n;
	int *list;
}nodeList;

double h(node *n1, node *n2);
double g(node **nList, int *path, int len);
double pDistance(node *n1, node *n2);
nodeList* astar(int initNode, int endNode, int n, node **nList);
nodeList* listInit();
void listAdd(nodeList* list, int id);
int findMin(double* fScore, int n, nodeList *openSet);
int listRemoveItem(nodeList *list, int id);
void listPrint(nodeList *list);
int cmpfunc(const void * a, const void * b);
nodeList* reconstructPath(int* cameFrom, int endNode, int initialnode);