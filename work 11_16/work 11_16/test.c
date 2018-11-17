#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//判断是否为2的幂级数
int judge(int num)
{
	int device = 0;
	while (num)
	{
		if (num & 1 == 1 && device == 0)
		{
			num >>= 1;
			device++;
		}
		else if (device != 0 && num & 1 == 1)
			return 0;
		else
			num >>= 1;
	}
	return 1;
}

int main()
{
	int num = 0;
	scanf("%d", &num);
	int ret = judge(num);

	if (ret)
		printf("true");
	else
		printf("false");
	system("pause");
	return 0;
}


//寻找缺少的数字
int find(int arr[], int length)
{
	int num = 0;

	for (int i = 0; i <= length; i++)
	{
		if (i < length)
		{
			num = num ^ i ^ arr[i];
		}
		else
		{
			num ^= i;
		}
	}
	return num;
}

int main()
{
	int num[] = { 0, 1, 3, 4, 5, 6, 7, 8, 9 };
	int ret = find(num, 9);

	printf("%d", ret);
	system("pause");
	return 0;
}
//判断回文数
int Number(int num)
{
	int div = 0;
	int n = num;

	while (n)
	{
		n /= 10;
		div++;
	}

	while (num > 9)
	{
		if (num % 10 == num / (int)(pow(10, div - 1)))
		{
			num /= 10;
			num -= num / (int)(pow(10, div - 1) *pow(10, div - 1));
			div -= 2;
		}
		else
		{
			return 0;

		}
		return 1;
	}
}



int main()
{
	int num = 0;

	scanf("%d", &num);
	int ret = Number(num);

	if (ret && num>0)
		printf("true");
	else
		printf("false");


	system("pause");
	return 0;
}

//判断回文字符串
int fun(char *str)
{
	int length = strlen(str);
	int left = 0;
	int right = length - 1;

	while (left < right)
	{
		if (str[left] == str[right])
		{
			left++;
			right--;
		}
		else
			return 0;
	}
	return 1;
}

int main()
{
	char arr[] = "abcdcba";
	int i = fun(arr);
	if (i)
		printf("true");
	else
		printf("false");

	system("pause");
	return 0;
}

//输出数字的逆置
int Reverse_Integer(int num)
{
	int m = 0;
	if (num >= INT_MAX || num <= INT_MIN)
		return 0;

	while (num)
	{
		if (num)
		{
			m = m * 10 + num % 10;
			num /= 10;
		}
	}
	return m;
}

int main()
{
	int num = 0;
	int ret = 0;

	scanf("%d", &num);
	ret = Reverse_Integer(num);
	printf("%d", ret);

	system("pause");
	return 0;
}
