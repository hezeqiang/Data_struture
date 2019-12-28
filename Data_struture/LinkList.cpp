#include <stdio.h>
#include <stdlib.h>

#define ElementType int

LinkList L;
Node p,s,pre,temp,q;
int i , j , k;

typedef struct Node {
	ElementType data;
	struct Node *next;
}Node, *LinkList;
//LinkList Ϊ�ṹָ�����ͣ�ָ����һ���ṹ����Node��������һ���ģ�������ͷָ��
//һ��Node�� ������ �Լ� ָ���� ����


LinkList creatList()
{
	L = (LinkList)malloc(sizeof(Node));//creat the first Node
	L->next = NULL;
	return L;
}

void outputList(LinkList L)
{
	p = L->next;
	//p point the first Node
	while (p!=NULL)
	{
		printf(p->data);
		p = p->next;//p point next Node
	}
}

Node* find(LinkList L, ElementType x)
{
	p = L->next;//from the first
	while (p != NULL&& p->data != x) 
	{
		p = p->next;
	}
	return p;
}

Node locate(LinkList L, int i)
{
	p = L;
	k = 0;
	while (p != NULL && k < i) 
	{
		k++;
		p = p->next;

	}
	return p;
}

int insertList(LinkList L, int i, ElementType x)
{
	//find the i-1 point and insert the x
	p = locate(L, i - 1);

	if (p == NULL || i < 1) { return 0; }

	//malloc
	s = (Node*)malloc(sizeof(Node));
	s->data = x;
	//link to the list,insert behind the i-1
	s->next = p->next;
	p->next = s;

	return 1;
}

int deletevalueList(LinkList L, ElementType x)
{
	pre = L;
	p = L->next;//pre ��p ��ǰ���ڵ�
	while (p != NULL || p->data != x)
	{
		pre = p;
		p = p->next;
	}
	if (p == NULL) 
	{
		return 0;
	}
	else 
	{
		pre->next = p->next;
		free(p);
		return 1;
	}
}


int deletenumList(LinkList L,int i, ElementType* x) //ɾ��ֵ�����x��ָ�������
{
	p = locate(L, i - 1);
	if (p != NULL || i < 1 || p->next = NULL) { return 0; }

	temp = p->next;
	p->next = temp->next;
	*x = temp->data;
	free(temp);

	return 1;
}


void reverse(LinkList L) 
{
	p = L->next;//first we should preserve the head pointer
	L->next = NULL;//a new L
	while (p != NULL) 
	{
		q = p->next;
		p->next = L->next;
		L->next = p;

		p = q;//ǰ�巽ʽ
	}
}

LinkList pa, pb,r;

void mergeList(LinkList LA, LinkList LB) //the result is put in LA
{
	pa=LA->next;
	pb=LB->next;

	LA->next = NULL;
	r = LA;
	
	while (pa!=NULL&&pb!=NULL)
	{
		if (pa->data <= pb->data) 
		{
			r->next = pa;
			r = pa;//���Ὺ���µĿռ䣬��������һ�θı�next
			pa = pa->next;
		}
		else 
		{
			r->next = pb;
			r = pb;
			pa = pb->next;
		}
	}

	if (pa != NULL) { r->next = pa; }
	if (pb != NULL) { r->next = pb; }

	free(LB);
}




