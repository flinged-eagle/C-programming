#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<windows.h>

//1.дһ���������ز����������� 1 �ĸ��� 
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

//2.��ȡһ�������������������е�ż��λ������λ���ֱ�������������С� 

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
	printf("����λ��>\n");
	for(j=i-1; j>=0; j=j-2)
		printf("%2d",*(p+j));
	printf("\nż��λ:>\n");
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

3. ���һ��������ÿһλ�� 

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


//4.���ʵ�֣� 
//����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ�� 
//��������: 
//1999 2299 
//�������:7	

int fun(int m, int n)
{
	int count = 0;
	int j = m^n;  // ��� ����Ϊ1 ��ͬΪ0
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

//5.д�����ܽ�C���Բ��������������ӷ����ң�������Ⱥ� 
