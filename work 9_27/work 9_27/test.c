//#include<stdio.h>
//#include<math.h>

//int main()
//{
//	int i=0;
//	int count = 1;
//	int sum = 0;
//	int tmp = 0;
//	for(i=0 ; i<=99999 ; i++)
//	{
//		tmp = i;
//		//�ж�λ��
//		while(tmp/10)
//		{
//			count++;
//			tmp = tmp/10;
//		}
//		tmp = i;
//		while(tmp!=0)
//		{
//				sum += pow(tmp%10,count);
//				tmp = tmp/10;
//		}
//		if(sum == i)
//			printf("%d  ", i);
//	}
//	system("pause");
//	return 0;
//}


////��������Ϸ
//#include<stdio.h>
//#include<stdlib.h>
//#include <time.h>
//
//
//void menu();
//void game();
//
//
//int main()
//{
//	srand((unsigned)time( NULL ) );
//	menu();
//	return 0;
//}
//void menu()
//{
//	int a = 0;
//	do{
//		printf("****************************\n");
//		printf("*******   1. play   ********\n");
//		printf("*******   0. exit   ********\n");
//		printf("****************************\n");
//		printf("��ѡ��>\n");
//		scanf("%d",&a);;
//		switch(a)
//		{
//		case 1:game();
//			break;
//		case 0:
//			break;
//		default:printf("�������\n");
//			break;
//		}
//	}while(a);
//}
//void game()
//{
//	int i = 0;
//	int num = 0;
//	i = rand()%100 +1;
//	printf("��������Ϸ��ʼ!\n");
//	while(1){
//		scanf("%d",&num);
//		if(i<num)
//		{
//			printf("�´���\n");
//		}
//		else if(i>num)
//		{
//			printf("��С��\n");
//		}else
//		{
//			printf("�¶���\n");
//			break;
//		}	
//	}
//
//}

////�۰����
//#include<stdio.h>
//
//int main()
//{
//	int arr1[10] = {0};
//	int i = 0;
//	int num = 0;
//	int left = 0 ,right = sizeof(arr1) / sizeof(arr1[0]);
//	int mid = 0;
//	printf("������һ����������\n");
//	for(i=0 ; i<10 ; i++)
//	{
//		scanf("%d",&arr1[i]);
//	}
//	printf("��������Ҫ��ѯ������:>\n");
//	scanf("%d",&num);
//	while(left<=right)
//	{
//		mid = (right - left)/2 + left;
//		if(arr1[mid]>num)
//		{
//			right = --mid; 
//		}else if(arr1[mid]<num)
//		{
//			left = ++mid;
//		}else{
//			printf("�ҵ��ˣ�\n");
//			break;
//		}
//	}
//	if(left>right)
//		printf("δ�ҵ���\n");
//	return 0;
//}

////ģ�������½
//
//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	char code[20] = "mimashimima";
//	char secret[20];
//	int i = 0;
//	int result = -1;
//	for(i=0 ; i<3 ; i++)
//	{
//		printf("���������룺>\n");
//		scanf("%s",secret);
//		if((result = strcmp(secret,code))==0)
//		{
//			printf("��½�ɹ���\n");
//			break;
//		}
//		else
//		{
//			printf("�������\n");
//		}
//		
//	}
//	if(i == 3)
//		printf("��½ʧ��\n");
//	return 0;
//}

//�ַ�ת��
#include<stdio.h>

int main()
{
	int c = 0;
	while((c = getchar())!=EOF)
	{
		if(c>=65 && c<=90)
		{
			printf("%c",c+32);
		}
		else if(c>=97 && c<=122)
		{
		printf("%c",c-32);
		} else
			printf("%c",c);
	}

	return 0;
}