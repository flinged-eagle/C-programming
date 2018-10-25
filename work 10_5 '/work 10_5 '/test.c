#define _CRT_SECURE_NO_WARNINGS 1
#define LIST_INIT_SIZE 100
#define LISTNCRMENT 10
#define int ElemType;

#include<stdio.h>
#include<stdlib.h>

typedef struct{
	ElemType *elem;
	int length;
	int listsize;
}SqList;

SqList InitList_Sq(SqList L)
{
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElenType));
	if(!L.elem)exit(-2);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return L;
}

void MergeList(SqList L1,SqList L2,pSqList L_sum)
{
	int *pa,*pb,*pc,*pa_last,*pb_last;
	pa = L1.elem;
	pb = L2.elem;
	L_sum->length = L1.length + L2.length;
	pc = L_sum->elem = (int *)malloc(L_sum->length*sizeof(int));
	pa_last = L1.elem + L1.length - 1;
	pb_last = L2.elem + L2.length - 1;
	while(pa<=pa_last && pb<=pb_last)
	{
		if(*pa <= *pb)
			*pc++ = *pa++;
		else
			*pc++ = *pb++;
	}
	while(pa<=pa_last)
		*pc++ = *pa++;
	while(pb<=pb_last)
		*pc++ = *pb++;
}

int main()
{
	SqList L;
	L = InitList_Sq(L);
	return 0;
}