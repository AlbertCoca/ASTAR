#include "common.h"
int cmpfunc(const void *n1, const void *n2)
{
	return *(node*)n1->id - *(node*)n2->id; 
} 
