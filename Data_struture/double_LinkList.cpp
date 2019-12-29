#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#define ElementType int

typedef struct Node {
	ElementType data;
	struct Node *next;
	struct Node *prior;
}DNode, *DList;








