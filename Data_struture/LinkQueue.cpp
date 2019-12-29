#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#define ElementType int

LinkQueue Q;
QNode s,temp;

typedef struct Node{
	ElementType data;
	struct Node *next;
}QNode;//struct def of the QNode;

typedef struct
{
	QNode *front;//the pointer of the QNode;
	QNode *rear;
}LinkQueue;

LinkQueue* creatQueue()
{
	Q = (LinkQueue*)malloc(sizeof(LinkQueue));

	Q->front = (QNode*)malloc(sizeof(QNode));
	Q->rear = Q->front;
	Q->front->next = NULL;
	return Q;
}
int push(LinkQueue* Q, ElementType x)
{
	s = (QNode*)malloc(sizeof(QNode));
	if (s == NULL) { return 0; }
	else 
	{
		s->next = NULL;
		s->data = x;

		Q->rear->next = s;
		Q->rear = s;
		return 1;
	}
}


int pop(LinkQueue* Q) 
{
	if (Q->front == Q->rear) { return 0; }
	else 
	{
		temp = Q->front->next;
		Q->front->next = temp->next;

		if (Q->rear == temp) { Q->rear = Q->front; }

		free(temp);
		return 1;
	}
}



