#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#define ElementType int

SeqStack S;
ElementType x;

typedef struct {
	ElementType *array;
	int top;
	int capacity;
}SeqStack;

SeqStack*creatStack(int capacity) 
{
	S = (SeqStack*)malloc(sizeof(SeqStack));

	S->top = -1;
	S->capacity = capacity;
	S->array = (ElementType*)malloc(capacity * sizeof(ElementType));
}

int empty(SeqStack* S)
{
	if (S->top == -1) { return 1; }
	else { return 0; }
}

int full(SeqStack* S) 
{
	if (S->top >=S->capacity-1) { return 1; }
	else { return 0; }
}

int push(SeqStack *S, ElementType x) 
{
	if (full(S)) { return 0;}
	else 
	{
		S->top++;
		S->array[S->top] = x;
		return 1;
	}
}

int pop(SeqStack* S)
{
	if (empty(S) == 1) { return 0; }
	else 
	{
		S->top--;
		return 1;
	}
}

ElementType top(SeqStack* S)
{
	return S->array[S->top];
}

