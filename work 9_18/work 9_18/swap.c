#include<stdio.h>
#include<stdlib.h>
	
int main()
{
	int a=10,b=20;
	int c;
    printf("a= %d  b = %d\n",a,b);
	c = a;
	a = b;
	b = c;
	printf("a= %d  b = %d\n",a,b);
	system("pause");
	return 0;
}
int main(){
	int a=10,b=20;
	a = a+b;
	b = a-b;
	a = a-b;
	printf("a= %d  b = %d\n",a,b);
	system("pause");
	return 0;
}
int main()
{	
	int a =10,b=20;
	a=a^b;
	b=a^b;
	a=a^b;
	printf("a= %d  b = %d\n",a,b);
	system("pause");
	return 0;
}


��������
int main()
{
	int arr[10]={9,23,34,4,78,44,55,33,11,0};
	int i;
	int max=arr[0];
	for(i=1;i<10;i++)
		max = (max<arr[i])?arr[i]:max;
	printf("max = %d\n",max);
	system("pause");
	return 0;
}

����������

int main(){
	int a =20,b=15,c=50;
	int S;
	if(a<b)
	{
		S=a;
		a=b;
		b=S;
	}else if(b<c)
	{
		S=b;
		b=c;
		c=S;
	}
	if(a<b)
	{
		S=a;
		a=b;
		b=S;
	
	}
	printf("%d %d %d",a,b,c);
	system("pause");

	return 0;
}	

int main()
{
	int a = 123456 , b =7890;
	int m = b;
	while(a%b!=0)
	{
		m = a%b;
		a = b;
		b = m;
	}
	printf("���Լ��Ϊ %d\n",m);
	system("pause");
	return 0;
}