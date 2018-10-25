#include<stdio.h>
#include<math.h>

//int main()
//{
//	char arr1[13] =  "             ";
//	int left = 6;
//	int right = 8;
//	arr1[7] = '*';
//	while(left!=0)
//	{
//		printf("%s\n",arr1);
//		arr1[left] = '*';
//		arr1[right] = '*';
//		/*printf("%s",arr1);*/
//		left--;
//		right++;
//	}
//	while(left<right)
//	{
//		arr1[left] = ' ';
//		arr1[right] = ' ';
//		printf("%s\n",arr1);
//		left++;
//		right--;
//	}
//	system("pause");
//	return 0;
//}
int main()
{
	int i=0, j=0,n=7;

    for(i=1; i<=n; i++) {
        for(j=1; j<=n-i; j++)
            printf(" ");
        for(j=1; j<=2*i-1; j++)
            printf("*");
        printf("\n");
    }
    for(i=1; i<=n-1; i++) {
        for(j=0; j<i; j++)
            printf(" ");
        for(j=0; j<2*n-1-2*i; j++)
            printf("*");
        printf("\n");
    }
	system("pause");
	return 0;

}
int main()
{
	int a=0,b=0,c=0;
	for(a=1 ; a<10 ; a++)
		for(b=0 ; b<10 ;b++)
			for(c=0 ; c<10 ; c++)
				if(a*100+b*10+c == pow(a,3) + pow(b,3) + pow(c,3))
					printf("%d\t",a*100+b*10+c);
	system("pause");
	return 0;
}
int main()
{
	int m=0,sum=0;
	for(m=1 ; m<10 ; m++)
	{
		sum = m*10000 + m*1000*2 + m*100*3 + m*10*4 + m*5;
		printf("%d\n",sum);
	}
	system("pause");
	return 0;
}