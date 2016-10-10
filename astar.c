 #include "astar.h"
 double h(node *n1, node *n2){
 	return sqrt(pow((n1->lon - n2->lon), 2) + pow((n1->lon - n2->lon),2));
}

 double g(node *n1, node *n2){
 	return sqrt(pow((n1->lon - n2->lon), 2) + pow((n1->lon - n2->lon),2));
}