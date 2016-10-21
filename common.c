#include "common.h"

int findIndexOfChar(char* s, char c, int n){
	int i, offset = -1;
	for(i=0; i<n; i++){
		const char *ptr = strchr(s+offset+1, c);
		if(ptr == NULL) return -1;
		offset = ptr - s;
	}
	return offset;
}

long bs(node **nList, int fItem, int len){
	int low = 0;
	int high = len + 1;
	int i = (len+1)/2;
	node *n_Act;
	while(low <= high && nList[i]->realId != fItem){
		if(fItem > nList[i]->realId) low = i+1;
		else high = i - 1;
		i = (low+high) / 2;
	}
	if(low > high){
		return -1;
	}
	return nList[i]->id;
	
}
