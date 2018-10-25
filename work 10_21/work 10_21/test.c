#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int fun(int n)
{
	int i = 0;
	int count = 0;

	for(i=1; i!=0; i<<=1)
	{
		if((n&i) == i)
		{
			count++;
	
		}
	}
	return count;	
}

int main()
{
	int num = 0;
	int ret = 0;

	scanf("%d",&num);
	ret = fun(num);
	printf("%d",ret);
	return 0;
}

void fun(int n)
{
	if(n/10)
	{
		fun(n/10);
		/*printf("%2d",n%10);*/
	}
	printf("%-2d",n%10);
	//else
	//{
	//	printf("%d",n);
	//}
}
int main()
{
	int num = 0;
	
	scanf("%d",&num);
	fun(num);
	return 0;
}


