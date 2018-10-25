#include<stdio.h>


/*打印100~200 之间的素数 */

int main()
{
	int i,j;
	for(i=100;i<=200;i++)
	{
		for(j=2;j<i/2;j++)
		if(i%j==0)break;
		if(i%j!=0)
			printf("%d ",i);
	}
	system("pause");
	return 0;
}


/*九九乘法表*/
int main()
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=i;j++)
			printf("%d*%d=%d  ",i,j,i*j);
		printf("\n");
	}
		system("pause");
	return 0;
}


/*1000-2000 之间的闰年*/


int main()
{
	int m;
	for(m=1000;m<=2000;m++)
		if((m%4==0 && m%100!=0)||m%400==0)
			printf("%d 年是闰年\t",m);
	system("pause");
	return 0;
}
