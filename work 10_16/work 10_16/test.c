#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<windows.h>

//1.写一个函数返回参数二进制中 1 的个数 
int count_one_bite(unsigned int n)
{
	if(n%2)
		return 1+count_one_bite(n/2);
	else if(n != 0)
		return count_one_bite(n/2);
	else
		return 0;
}

int main()
{
	unsigned int num = 0;
	int ret = 0;

	scanf("%u",&num);
	ret = count_one_bite(num);
	printf("%d",ret);
	system("pause");
	return 0;
}

//2.获取一个数二进制序列中所有的偶数位和奇数位，分别输出二进制序列。 

void fun(int num , int *p)
{
	int i = 0;
	int j = 0;
	while(num!=0)
	{
		*(p+i) = num%2;
		i++;
		num = num/2;
	}
	printf("奇数位：>\n");
	for(j=i-1; j>=0; j=j-2)
		printf("%2d",*(p+j));
	printf("\n偶数位:>\n");
	for(j=i-2; j>=0; j=j-2)
		printf("%2d",*(p+j));
	printf("\n");
}

int main()
{
	int num = 0;
	int m = 0;
	int *p = &m;
	scanf("%d",&num);
	fun(num,p);
	system("pause");
	return 0;
}

3. 输出一个整数的每一位。 

void fun(int num)
{
	if(num/10)
	{
		fun(num/10);
		printf("%2d",num%10);
	}
	else
	{
		printf("%2d",num);
	}
}

int main()
{
	int num = 0;

	scanf("%d",&num);
	fun(num);
	system("pause");
	return 0;
}


//4.编程实现： 
//两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？ 
//输入例子: 
//1999 2299 
//输出例子:7	

int fun(int m, int n)
{
	int count = 0;
	int j = m^n;  // 异或 相异为1 相同为0
	while(j!=0)
	{
		if(j%2 == 1)
			count++;
		j /= 2;
	}
	return count;
}

int main()
{
	int m = 1999;
	int n = 2299;
	int ret = 0;
	
	ret = fun(m,n);
	printf("%d",ret);
	system("pause");
	return 0;
}

//5.写博客总结C语言操作符，博客链接发给我，并分享到群里。 
