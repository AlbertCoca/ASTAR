#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 79857

typedef struct{
	long id;
	char *name;
	double lon;
	double lat;
}node;

int findIndexOfChar(char* s, char c, int n);
node readNode(FILE* fp);