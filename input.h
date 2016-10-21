#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 79857
#define NODE_MAX 23895681 
#define LINE_MAX 1417363

typedef struct{
	long id;
	long realId;
	char *name;
	double lon;
	double lat;
	long neighbors[20];
	long tn;
}node;


long loadFile(char *name, node **nList);
int findIndexOfChar(char* s, char c, int n);
node* readNode(char *line);
void classifyLine(char *line, node **nList, long *i);
void readWay(char *line, node **nList, long n);
void nodeInitialize(node *n);
