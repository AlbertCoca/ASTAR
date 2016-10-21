#include "input.h"
#include <math.h>

#define REALLOC_SIZE 100000

typedef struct{
	long size;
	long n;
	long *list;
}nodeList;

double h(node *n1, node *n2);
double g(node **nList, long *path, long len);
double pDistance(node *n1, node *n2);
nodeList* astar(long initNode, long endNode, long n, node **nList);
nodeList* listInit();
void listAdd(nodeList* list, long id);
long findMin(double* fScore, long n, nodeList *openSet);
int listRemoveItem(nodeList *list, long id);
void listPrint(nodeList *list);
int cmpfunc(const void * a, const void * b);
nodeList* reconstructPath(long* cameFrom, long endNode, long initialnode);
void listPrintReal(nodeList *list, node** nList);