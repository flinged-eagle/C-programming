#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//1. 
///*5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ�������� 
//Aѡ��˵��B�ڶ����ҵ����� 
//Bѡ��˵���ҵڶ���E���ģ� 
//Cѡ��˵���ҵ�һ��D�ڶ��� 
//Dѡ��˵��C����ҵ����� 
//Eѡ��˵���ҵ��ģ�A��һ�� 
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�*/ 

//  ^

//ȫ���У�δʵ�֣�//ȫ���У��ݹ�����㷨��
//int main()
//{
//	int arr[] = {1,2,3,4,5};
//	int i = 0;
//	int j = 0;
//	int n = 0;
//	int tmp = 0;
//
//	for(i=0; i<5; i++)
//		for(j=4; j>0; j--)
//		{
//				for(n=0; n<5; n++)
//				{
//					printf("%d",arr[n]);
//				}
//				printf("\n");
//			while( ((arr[1]==2)^(arr[0] == 3)) && ((arr[1] == 2)^(arr[4] == 4)) && ((arr[2] == 1)^(arr[3] == 2)) && ((arr[2]==5)^(arr[3]==3)) && ((arr[4] == 4)^(arr[0] == 1)))
//			{	
//				for(n=0; n<5; n++)
//				{
//					printf("%d",arr[n]);
//				}
//				printf("\n");
//				break;
//			}
//			tmp = arr[i];
//			arr[i] = arr[j];
//			arr[j] = tmp;
//		}
//		return 0;
//}

int main()
{
	int arr[] = {1,2,3,4,5};
	int i = 0;
	int j = 0;
	int k = 0;
	int m = 0;
	int n = 0;
	int tmp = 0;

	for(i=1; i<6; i++)
	{
		for(j=1; j<6; j++)
		{
			for(k=1; k<6; k++)
			{	
				for(m=1; m<6;m++)
				{	
					for(n=1; n<6; n++)
					{
						if( ((j==2)^(i == 3)) && ((j == 2)^(n == 4)) && ((k == 1)^(m == 2)) && ((k==5)^(m==3)) && ((n == 4)^(i == 1)))
						{	
							if((i*j*k*m*n)==120)
							{
								printf("%d ,%d,%d,%d,%d",i,j,k,m,n);
								printf("\n");
							break;
							}
						}
					}
				}
			}
		}
	}
	
		return 0;
}
//2. 
//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�� 
//���ɷ���һ��������Ϊ4�����ɷ��Ĺ��ʡ� 
//A˵�������ҡ�		!A
//B˵����C��			C
//C˵����D��			D
//D˵��C�ں�˵		!D
//��֪3����˵���滰��1����˵���Ǽٻ��� 
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡� 

int main()
{
	char killer= 'A';
	
	for(killer='A'; killer<='D'; killer++)
	{
		if(((killer != 'A')+(killer == 'C')+(killer == 'D')+(killer != 'C')) == 3)
			printf("%c\n",killer);
	
	}

	return 0;
}


//3.����Ļ�ϴ�ӡ������ǡ� 
//1 
//1 1 
//1 2 1 
//1 3 3 1

#define N 10


int main()
{
	int arr[N][N] = {0};
	int i = 0;
	int j = 0;
	int t = 0;

	for(i=0; i<N; i++)
	{
		arr[i][0] = 1;
		arr[i][i] = 1;
	}
	for(i=2; i<N; i++)     //�������ֵ
		for(j=1; j<i; j++)
		{
			arr[i][j] = arr[i-1][j-1] +arr[i-1][j];
		}
	for(i=0; i<N; i++)
	{
		for(t=0; t<4*(N-i)/2;t++)     //ʹ������Ǵ��м����
		printf(" ");
		for(j=0; j<=i; j++)
		{
			printf("%4d",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}