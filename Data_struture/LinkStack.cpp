#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#define ElementType int

ElementType x;
LinkStack top,temp;
Node s;

typedef struct 
{
	ElementType data;
	struct Node *next;
}Node,*LinkStack;
//*LinkStack指向了第一个node

LinkStack creatStack()
{
	top = (LinkStack)malloc(sizeof(Node));
	top->next = NULL;
	return top;
}

int push(LinkStack top, ElementType x) 
{
	s = (Node*)malloc(sizeof(Node));
	
	if (s == NULL) { return 0; }//fail to call for memory
	else
	{
		s->data = x;
		s->next = top->next;
		top->next = s;
		return 1;
	}
}

int pop(LinkStack top)//delete the top one
{
	temp = top->next;
	if (top->next == NULL) { return 0; }//the stack is empty
	else 
	{
		top->next = temp->next;
		free(temp);//free the memory
		return 1;
	}
}








