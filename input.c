#include "input.h"

int findIndexOfChar(char* s, char c, int n){
	int i, offset = -1;
	for(i=0; i<n; i++){
		const char *ptr = strchr(s+offset+1, c);
		offset = ptr - s;
	}
	return offset;
}

node readNode(FILE* fp){

	char line[MAX_LINE_LEN];
	node n;

	fgets(line,MAX_LINE_LEN, fp);
	printf("%s\n", line);

	char check[4];
	strncpy(check, line, 4);

	if(strcmp("node", check) == 0){

		char id[10];
		int start = findIndexOfChar(line, '|', 1) + 1;
		int end = findIndexOfChar(line, '|', 2);
		strncpy(id, line + start, end - start);
		n.id = atoi(id);

		char lat[20];
		start = findIndexOfChar(line, '|', 9) + 1;
		end = findIndexOfChar(line, '|', 10);
		strncpy(lat, line + start, end - start);
		n.lat = strtod(lat, NULL);

		char lon[20];
		start = findIndexOfChar(line, '|', 10) + 1;
		end = strlen(line);
		strncpy(lon, line + start, end - start);
		n.lon = strtod(lon, NULL);
	}

	else{
		printf("This is not a node!\n");
	}

	return n;
}