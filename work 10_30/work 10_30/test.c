#define _CRT_SECURE_NO_WARNINGS 1

//1.��������ʹ����ȫ����λ��ż��ǰ�档 
//
//��Ŀ�� 
//
//����һ���������飬ʵ��һ�������� 
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣� 
//����ż��λ������ĺ�벿�֡� 

//#include<stdio.h>
//
//void my_sort(int arr[], int num)
//{
//	int i = 0;
//	int tmp = 0;
//
//	while(i<num)
//	{
//		while(arr[i] % 2 !=0 && i<10)
//		{
//			i++;
//		}
//		while(arr[num] % 2 != 1 && num>0)
//		{
//			num--;
//		}
//		tmp = arr[i];
//		arr[i] = arr[num];
//		arr[num] = tmp;
//	}
//
//}
//
//int main()
//{
//	int arr[10];
//	int i = 0;
//
//	for(i=0; i<10; i++)
//		scanf("%d",&arr[i]);
//	
//	my_sort(arr,9);
//
//	for(i=0; i<10; i++)
//		printf("%d ",arr[i]);
//	return 0;
//}

//2. 
////���Ͼ��� 
//��һ����ά����. 
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����. 
//�������������в���һ�������Ƿ���ڡ� 
//ʱ�临�Ӷ�С��O(N); 
//
//���飺 
//1 2 3 
//2 3 4 
//3 4 5 
//
//
//1 3 4 
//2 4 5 
//4 5 6 
//
//1 2 3 
//4 5 6 
//7 8 9 
#define ROW 3
#define COL 3
#include<stdio.h>

int Is_Exit(int arr[ROW][COL], int num)
{
	int i = ROW;
	int j = COL;

	while(1)
	{
		if(arr[i][j] == num)
			return 1;
		else if(arr[i-1][j] >=num)
			i--;
		else if(arr[i][j-1] >=num)
			j--;
	}
	return 0;
	
}

int main()
{
	int arr[ROW][COL] = {1,2,3,4,5,6,7,8,9};
	int num = 0;
	int ret = 0;

	scanf("%d",&num);
	ret = Is_Exit(arr,num);

	printf("%d",ret);

	return 0;
}