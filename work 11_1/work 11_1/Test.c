//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//1.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB


void Slue(char *arr, int a,const int length)
{
	//char arr1[100] = {0};
	//int k = 0;
	//int i = 0;
	//
	//for (k = a - 1; k < length; k++)
	//{
	//	arr1[i++] = *(arr + k);
	//}
	//for (k = 0; k < a - 1; k++)
	//{
	//	arr1[i++] = *(arr + k);
	//}
	//arr1[i] = '\0';
	//arr = arr1;
	char arr1[100] = { 0 };
	int k = 0;
	int i = 0;

	for (k = 0; k < length; k++)
	{
		arr1[k] = *(arr + k);
	}
	for (k = a - 1; k < length; k++)
	{
		*(arr + i++) = arr1[k];
	}
	for (k = 0; k < a - 1; k++)
	{
		*(arr + i++) = arr1[k];
	}
}

int main()
{
	char arr[] = "aabbcc";
	int a = 0;
	
	scanf("%d", &a);
	Slue(arr, a,strlen(arr));
	printf("%s", arr);

	system("pause");
}

//2.�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1������s1 = abcd��s2 = ACBD������0.
//
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//
//AABCD����һ���ַ��õ�DAAB

int Is_Slue(char *arr1, char *arr2, int length)
{
	int i = 0;
	int count = 0;
	int ret = 0;

	for (i = 0; i < length; i++)
	{
		while(*(arr1 + i) == *arr2)
		{
			count++;
			arr2++;
		}
	}
	for (int j = 0; j < length-count; j++)
	{
		if (*(arr1 + j) == *arr2)
			ret++;
		else
			return 0;
	}
	if (length == count+ret)
		return 1;
	return 0;

}

int main()
{
	char arr1[] = "abcd";
	char arr2[] = "ABCD";
	int ret = 0;

	ret = Is_Slue(arr1, arr2,strlen(arr1));
	if (ret == 1)
		printf("���ַ�����Ϊ�����ַ���\n");
	else
		printf("error\n")

		system("pause");

	return 0;
}