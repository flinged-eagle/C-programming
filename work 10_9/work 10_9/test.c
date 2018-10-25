#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲��������� 
int fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	int i = 0;
	for( i=0; i<n-2; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

int fib_recursion(int n)
{
	if(n<=2)
		return 1;
	else
		return fib_recursion(n-1)+ fib_recursion(n-2);
}

int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d",&n);
	ret = fib(n);
	printf("%d\n",ret);
	ret = fib_recursion(n);
	printf("%d\n",ret);
	return 0;
}

//��дһ������ʵ��n^k��ʹ�õݹ�ʵ�� 
int pow(int n, int k)
{
	if(k>0)
		return n*pow(n,k-1);
	else
		return 1;
}

int main()
{
	int ret = 0;
	int m = 0;
	int n = 0;

	scanf("%d%d",&m,&n);
	ret = pow(m,n);
	printf("%d\n",ret);
	return 0;
}



//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ����磬����DigitSum(1729)����Ӧ�÷���1+7+2+9�����ĺ���19 
int Digitsum(int num)
{
	if(num>9)
		return num%10+Digitsum(num/10);
	else
		return num;
}

int main()
{
	int n = 0;
	int ret = 0;

	scanf("%d",&n);
	ret = Digitsum(n);
	printf("%d",ret);
	return 0;
}

//��дһ������reverse_string(char * string)���ݹ�ʵ�֣� 
//ʵ�֣��������ַ����е��ַ��������С� 
//Ҫ�󣺲���ʹ��C�������� 
//���ַ�������������
int n = 0;
int m =0;
void reverse_string(char* arr)
{
	char a = '0';
	if(m<n)
	{
		a = arr[m];
		arr[m] = arr[n];
		arr[n] = a;
		m++;
		n--;
		reverse_string(arr);
	}

}

int main()
{
	char arr[] = "hello world!";
	while(arr[n]!='\0')
		n++;
	n--;
	printf("%s\n",arr);
	reverse_string(arr);
	printf("%s\n",arr);
	return 0;
}

//�ݹ�ͷǵݹ�ֱ�ʵ��strlen 

int a = 0;

int fun(char* arr)
{
	int i=0;
	while(arr[i] != '\0')
		i++;
	return i;
}

int fun_recursion(char* arr)
{
	if(arr[a] != '\0')
	{
		a++;
		fun_recursion(arr);
	}
	return a;
}
int main()
{
	char arr[] = "hahahahaha";
	printf("%d\n",fun(arr));
	printf("%d\n",fun_recursion(arr));
	return 0;
}

//�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳� 

int factorical_recursion(int n)
{
	if(n>=2)
		return n*factorical_recursion(n-1);
	else
		return 1;
}

int factorical(int n)
{
	int ret = 1;

	for( ; n>1; n--)
	{
		ret *= n; 
	}
	return ret;
}

int main()
{
	int n = 0;

	scanf("%d",&n);
	printf("%d\n",factorical_recursion(n));
	printf("%d\n",factorical(n));
	return 0;
}

//�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ 

void Print(int n)
{
	if(n>9)
		Print(n/10);
	printf(" %d",n%10);
	
}
int main()
{
	int n = 0;

	scanf("%d",&n);
	Print(n);
	return 0;
}