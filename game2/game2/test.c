#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()
{
	printf("	***********************\n");
	printf("	********1. play  ******\n");
	printf("	********0. exit  ******\n");
	printf("	***********************\n");
}

int main()
{
	int choice = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("�������ѡ��>");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			game();
			break;
		case 0:
			printf("exit��\n");
			break;
		default:
			printf("�������!\n");
			break;
		}
	}while(choice);
	return 0;
}