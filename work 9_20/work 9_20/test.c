#include<stdio.h>
#include<stdlib.h>

//int main()
//{
//	int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
//	int arr2[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//	int* swap=0;
//	swap = &arr1;
//	arr1 = &arr2;
//	&arr2 = swap;
//	printf("%d " ,arr1);
//	printf("%d " ,arr2);
//	system("pause");
//	return 0;
//}
int main()
{	
	int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	int arr2[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int m=0,i;
	for(i = 0; i<10 ; i++)
	{
		m = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = m;
	}
	for(i = 0;i<10 ;i++)
	{
	printf("%d  ",arr1[i]);
	}
	for(i = 0;i<10 ;i++)	
	printf("%d  ",arr2[i]);
	system("pause");
	return 0;
}

int main()
{
	int i;
	double sum=0.0;
	for(i=1; i<=100;i++)
	{
		if(i%2==0)
		{
		sum-=1/i;
		}
		else
		{
			sum+=1/i;
		}
	}
	printf("%f",sum);
	system("pause");
	return 0;
}
int main()
{		
	int i;
	int count=0;
	for(i=9 ; i<100 ; i+=10)
	{
		if(i%10==9)
		{
			count++;
			if(i/9==0)
			{
				count++;
			}
		}

	}
	printf("%d\n",count);
	system("pause");

	return 0;
}