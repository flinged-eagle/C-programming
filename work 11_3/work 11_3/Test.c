//1.一个数组中只有两个数字是出现一次，
//其他所有数字都出现了两次。
//找出这两个数字，编程实现。
//
//

#include<stdio.h>
#include<stdlib.h>

void sort(int arr[], int length, int *p1, int *p2)
{
	int count = 0;

	for (int i = 0; i < length; i++)
	{
		for(int j = i; j < length; j++)
		if (arr[i] > arr[j])
		{
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}

	while (count < length)
	{
		if (arr[count] == arr[count + 1])
			count += 2;
		else
		{
			if (*p1 == *p2)
			{
				*p1 = arr[count];
			}
			else
				*p2 = arr[count];
			count++;
		}
	}

}

int main()
{
	int p1 = -1;
	int p2 = -1;
	int arr[] = { 11, 22, 11, 5, 66, 55, 9, 66, 55, 22 };

	sort(arr, sizeof(arr) / sizeof(arr[0]), &p1, &p2);

	printf("%d  %d", p1, p2);

	system("pause");
	return 0;
}


	

//2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
//给20元，可以多少汽水。
//编程实现。
//

int judge(int num)
{
	int ret = num;
	int i = 0;
	int count = 0;

	//for (i = num; i > 1;)
	//{
	//	if ((num % 2) == 0)
	//	{
	//		num /= 2;
	//		ret += num;
	//	}
	//	else if (count == 1)
	//	{
	//		ret += num / 2;
	//		num = num / 2 + 1;
	//		count = 0;
	//	}
	//	else
	//	{
	//		ret += num / 2;
	//		num = num / 2 + 1;
	//		count = 1;
	//	}
	//	i = num;
	//}
	while(i = num, i > 1)
	{
		if ((num % 2) == 0)
		{
			num /= 2;
			ret += num;
		}
		else 
		{
			ret += num / 2;
			num = num / 2 + 1;
			if (count == 1)
				count = 0;
			else
				count = 1;
		}
	}

	return ret;
}

int main()
{
	int num = 20;

	printf("the number is %d\n",judge(num));

	system("pause");
	return 0;
}
//3.模拟实现strcpy

void my_strcpy(char *p1, char *p2)
{
	while (*p2++ = *p1++, *p1 != '\0')
	{
	}

}

int main()
{
	char *arr1 = "hello world";
	char arr2[100] = { 0 };

	my_strcpy(arr1, arr2);
	printf("%s", arr2);

	system("pause");
	return 0;
}

//4.模拟实现strcat
//连接字符串
//char *strcat(char *strDestination, const char *strSource);
char *my_strcat(char *str, const char *strsource)
{
	int i = 0;
	int j = 0;
	while (*(str+i) != 0)
	{
		i++;
	}
	while (*(strsource + j) != 0)
	{
		*(str + i) = *(strsource + j);
		i++;
		j++;
	}
	return str;
}

int main()
{
	char str[100] = "children ,";
	char *strsource = "hello world";
	printf("%s", my_strcat(str, strsource));

	system("pause");
	return 0;
}
