#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
   	printf("----------------------- \n");
	printf("|      ɨ��С��Ϸ     |\n");
	printf("-----------------------\n");
	printf("|       1.play        |\n");
	printf("|       0.exit        |\n");
	printf("-----------------------\n");

}

void menu2()
{
	printf("------------------\n");
	printf("|    1. ����     |\n");
	printf("|    2. �м�     |\n");
	printf("|    3. ج��     |\n");
	printf("------------------\n");
}

void game()
{
	int input2 = 0;
	int diff = 0;
	//�������̣�����
	char mine[ROWS][COLS] ={0};
	char show[ROWS][COLS] ={0};
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show,ROWS,COLS,'*');
	/*DisplayBoard(mine,ROW,COL);*/
	DisplayBoard(show,ROW,COL);
	menu2();
	printf("��ѡ���Ѷ�>:");
	scanf("%d",&input2);
	switch(input2)
	{
	case 1 :
		diff = ROW*COL/ROW;
		break;
	case 2 :
		diff = ROW*COL/4;
		break;
	case 3 :
		diff = ROW*COL/2;
		break;
	default:
		printf("ѡ�����Ĭ��Ϊ�����Ѷ�\n");
		diff = ROW*COL/ROW;
		break;
	}
	SetMine(mine,ROW,COL,diff);
	DisplayBoard(mine,ROW,COL);
	FindMine(mine,show,ROW,COL,diff);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ!\n");
			break;
		default:
			printf("��ѡ���ˣ����䣡\n");
			break;
		}
	}while(input);
	return 0;
}