#include <stdio.h>
#include <stdlib.h>
#define ElementType int

SeqList* L;
int i,j,k;


typedef struct{
	ElementType *array;
	int length;
	int capacity;
}SeqList;


SeqList* creatList(int capacity) 
{
	L = ( SeqList * )malloc(sizeof(SeqList));
	L->length = 0;
	L->capacity = capacity;
	L->array = (ElementType * )malloc(capacity * sizeof(ElementType));

	return L;
}


int get(SeqList*L, int i, ElementType *x)//x is used to store the value
{
	if (i<1 || i>L->length) {
		return 0;
	}
	*x = L->array[i - 1];
	return 1;
}


int find(SeqList* L, ElementType x)
{
	i = L->length - 1;
	while (i >= 0 && L->array[i] != x) { i--; }
	return i;
}


int insertList(SeqList* L, int i, ElementType x) 
{
	if (L->length >= L->capacity)	{return 0;}

	if (i<1 || i>L->length + 1) { return 0; }

	for (k = L->length - 1; k >= i - 1; k--)
	{
		L->array[k + 1] = L->array[k];
	}
	L->array[i - 1] = x;
	L->length++;

	return 1;
}


int deleteList(SeqList*L, int i, ElementType *x) //*x is used to restore the deleted value in case
{
	if (i<1 || i>L->length) { return 0; }

	*x = L->array[i - 1];
	for (k = i; k < L->length; k++) 
	{
		L->array[k - 1] = L->array[k];
	}
	L->length--;

	return 1;
}


void mergeList(SeqList*LA, SeqList*LB, SeqList*LC)
{
	i = i = k = 0;
	while (i < LA->length&&j < LB->length)
	{
		if (LA->array[i] < LB->array[j]) 
		{
			LC->array[k] = LA->array[i];
			k++;
			i++; 
		}
		else
		{
			LC->array[k] = LB->array[j];
			k++;
			j++;
		}
	}
	while (i < LA->length)
	{
		LC->array[k++] = LA->array[i++];
	}
	while (j < LB->length) 
	{
		LC->array[k++] = LB->array[j++];
	}
	LC->length = k;
}


