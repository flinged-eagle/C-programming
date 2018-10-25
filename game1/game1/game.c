#define _CRT_SECURE_NO_WARNINGS 1


#include"game.h"
#include<stdio.h>

void InitBoard(char board[ROW][COL],int row,int col)
{
	int i = 0;
	int j = 0;
	for(i=0 ; i<row; i++)
		for(j=0 ; j<col; j++)
			board[i][j] = ' ';
}

void DisplayBoard(char board[ROW][COL] , int row, int col) 
{
	int i = 0 ;
	int j = 0 ;
	for(i=0; i<=row; i++)
	{
		for(j=0; j<row; j++)
		{
			printf("  |") ;
		}
		printf("\n") ;
		for(j=0 ; j<=col; j++)
		{
			if (i == row)
			{
				break;
			}
			else if (j < col)
			{
				printf("--%c" , board[i][j]) ;
			}
			else if( j == col)
			{
				printf("--") ;
			}
		}
		printf("\n");
	}
}


void ComputerMove(char board[ROW][COL],int row,int col)
{

	while(1)
	{
		int x = rand()%3;
		int y = rand()%3;
		if(board[x][y] == ' ')
		{	
			board[x][y] = 'X';
			break;
		}
	}

}

void PlayerMove(char board[ROW][COL],int row,int col)
{
	int x = 0;
	int y = 0;
	printf("���������꣺>\n");
	while(1)
	{
	scanf("%d%d",&x,&y);
	if(x>3 || y>3)
	{
		printf("�������!\n");
	}
	else if(board[x-1][y-1] == ' ')
	{
		board[x-1][y-1] = 'Y';
		break;
	}
	else
		printf("���걻ռ�ã����������룡\n");
	}

}

char Is_Win(char board[ROW][COL],int row,int col)
{
	int i = 0;

	for(i=0 ; i<row; i++)
	{
		//�ж���
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
			return board[0][i];
		//�ж���
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
	}

	//�ж�б��
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
		return board[0][0];

	if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ')
		return board[0][0];
	//�ж��Ƿ�ƽ��
	if(Is_full(board,ROW,COL) == 0)
		return 'Q';
	return 'L';

}

int Is_full(char board[ROW][COL],int row,int col)
{	
	int i = 0;
	int j = 0;
	for(i=0 ; i<row; i++)
		for(j=0 ; j<col;j++)
			if(board[i][j] == ' ')
				return 0;
	return 1;

}

void game()
{
	char board[ROW][COL] = {0};
	char ret = 0;

	InitBoard(board,ROW,COL);
	DisplayBoard(board,ROW,COL);
	while(1)
	{
		ComputerMove(board,ROW,COL);
		DisplayBoard(board,ROW,COL);
		ret = Is_Win(board,ROW,COL);
		if('Q' != ret)
			break;
		PlayerMove(board,ROW,COL);
		DisplayBoard(board,ROW,COL);
		ret = Is_Win(board,ROW,COL);
		system("cls");
		if('Q' != ret)
			break;
	}
	//'Q' ����
	//'X' ����Ӯ
	//'Y' ���Ӯ
	//'L' ƽ��

	switch(ret)
	{
	case 'X':
		printf("����Ӯ\n");
		break;
	case 'Y':
		printf("���Ӯ\n");
		break;
	case 'L':
		printf("ƽ��\n");
		break;
	default:
		printf("û�뵽�ɣ�\n");
	}
}