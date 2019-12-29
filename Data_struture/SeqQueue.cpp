#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#define ElementType int

SeqQueue Q;

typedef struct 
{
	ElementType *array;
	int front;
	int rear;
	int capacity;
}SeqQueue;


SeqQueue* creatQueue(int capacity)
{
	Q = (SeqQueue*)malloc(sizeof(SeqQueue));

	Q->front = 0;
	Q->rear = 0;
	Q->capacity = capacity;
	Q->array = (ElementType*)malloc(capacity * sizeof(ElementType));
	return Q;
}


int empty(SeqQueue* Q) 
{
	if (Q->front == Q->rear) { return 1; }
	else 
	{
		return 0;
	}
}


int full(SeqQueue*Q) 
{
	if ((Q->rear + 1) % Q->capacity == Q->front) { return 1; }
	else 
	{
		return 0;
	}
}


int push(SeqQueue* Q, ElementType x) 
{
	if (full(Q)) { return 0; }
	else 
	{
		Q->array[Q->rear] = x;
		Q->rear=(Q->rear+1)%Q->capacity;
		return 1;
	}
}


int pop(SeqQueue* Q, ElementType x)
{
	if (empty(Q)) { return 0; }
	else 
	{
		Q->front = (Q->front + 1) % Q->capacity;
	}
}

ElementType front(SeqQueue *Q) 
{
	return Q->array[Q->front];
}




