#define _CRT_SECURE_NO_WARNINGS 1
//�˷���

#include<stdio.h>

void List(int n)
{
	int i = 0;
	int j = 0;
	for(i=1 ; i<=n ; i++)
	{
		for(j=1 ; j<=i ; j++)
			printf("%d*%d=%-2d  ",i,j,i*j);
		printf("\n");
	}
}
int main()
{	
	int n = 0;
	printf("������������>\n");
	scanf("%d",&n);
	List(n);
	return 0;
}

//���Ľ���

#include<stdio.h>

void swap(int* i,int* j)
{
	int tmp = *i;
	*i = *j;
	*j = tmp;

}

int main()
{
	int i = 0,j = 0;
	scanf("%d%d",&i,&j);
	swap(&i,&j);
	printf("%d %d",i ,j);
	return 0;
}

//�ж�����

#include<stdio.h>

int leap(int year)
{
	if(( year%4 == 0 && year%100 != 0)||( year%400 ==0 ))
		return 1;
	return 0;
}

int main()
{
	int year = 0;
	int i = -1;
	printf("�����ѯ��֣�>\n");
	scanf("%d",&year);
	i = leap(year);
	if(i==1)
		printf("%d������\n",year);
	else
		printf("%d��������\n",year);

	return 0;
}

//����ĳ�ʼ������գ�����


#include<stdio.h>

void init(int arr[],int n)
{
	int i = 0;
	for(i=0 ; i<n ; i++)
	{
		scanf("%d",&arr[i]);
	}

}
void empty(int arr[],int n)
{
	int i = 0;
	for(i=0 ; i<n ; i++)
	{
		arr[i] = 0;
	}
}
void reverse(int arr[],int n)
{
	int left = 0;
	int right = n-1;
	int tmp = 0;
	while(left<=right)
	{
		tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}
void show(int arr[],int n)
{
	int i =0;
	for(i=0 ; i<n ; i++)
	{
		printf("%2d ",arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[10] = {0};
	int i = 0;
	int n = sizeof(arr)/sizeof(arr[0]);
	init(arr,n);
	show(arr,n);
	reverse(arr,n);
	show(arr,n);
	empty(arr,n);
	show(arr,n);
	system("pause");
	return 0;
}


//�������ж�


#include<stdio.h>
#include<math.h>

int prime(int num)
{
	int i = 0;
	for(i=2; i<=sqrt(num) ; i++)
	{
		if(num%i == 0)
			return 0;
	}
	return 1;

}
int main()
{
	int num = 0;
	printf("��������Ҫ�жϵ�����>\n");
	scanf("%d",&num);
	if(prime(num)==1)
		printf("%d������\n",num);
	else
		printf("%d��������\n",num);
	return 0;
}