#include "game.h"

void InitBoard(char arr[ROWS][COLS],int row,int col,char set)
{
	int i = 0;
	int j = 0;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			arr[i][j] = set;
		}
	}
	//memset(arr,set,ROWS*COLS*sizeof(arr[0][0]));
}
void DisplayBoard(char arr[ROWS][COLS],int row,int col)
{
	int i = 0;
	int j = 0;
	system("CLS");
	printf("       ɨ��        \n");
	printf("-------------------\n");
	for(i=0; i<=col; i++)
	{
		printf("%d ",i);
	}
	printf("\n");
	for(i=1; i<=row; i++)
	{
		printf("%d ",i);
		for(j=1; j<=col; j++)
		{
			printf("%c ",arr[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char arr[ROWS][COLS],int row,int col,int diff)
{
	int x = 0;
	int y = 0;
	
	while(diff)
	{
		x = rand()%row+1;
		y = rand()%col+1;
		if(arr[x][y] == '0')
		{
			arr[x][y] = 1+'0';
			diff--;
		}
	}
}

void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col,int diff)
{
	int x = 0;
	int y = 0;
	int safenum = 0;
	//DisplayBoard(mine,ROW,COL);
		/*if(IsWin(show,row,col,diff) == diff)
		{
			printf("��Ӯ�ˣ���ϲ����\n");
			break;
		}*/
	do	
	{
		printf("������Ҫ�ų���λ��>:");
		scanf("%d%d",&x,&y);
		
		if (x>=1 && x<= row && y>=1  && y<= col)
		{
			if (mine[x][y] == '1')
			{
				if (!safenum)//�Ƿ��ǵ�һ��ɨ��
				{
					mine[x][y] = '0';
					SetMine(mine, ROW, COL, 1);
					Ass(mine, show, x, y, &safenum);//�����һ��ɨ���ף������һ�α�ը������1���0�����ҽ�һ��������������ɵ�mine���ȥ�����׵��������䡣
				    DisplayBoard(show, ROW, COL);
				}
				else
				{
					printf("�ܱ�Ǹ���㱻ը���ˣ�\n");
					DisplayBoard(mine, ROW, COL);
					return;
				}
			}
			else
			{
				Ass(mine, show, x, y, &safenum);
				DisplayBoard(show, ROW, COL);
			}
		}
		else
			printf("����������>:");
	}while(IsWin(show,row,col,diff)-diff);
	printf("��Ӯ�ˣ���ϲ����\n");
		////DisplayBoard(mine,ROW,COL);
		//if(x>0 && x<=row && y>0 && y<=col)
		//{
		//	if(mine[x][y] == '1')
		//	{
		//		DisplayBoard(mine,ROW,COL);
		//		printf("Boom~ �㱻ը���ˣ�\n");
		//		break;
		//	}
		//	else if(mine[x][y] == '0')
		//	{
		//		if(!MuchMine(mine,x,y))
		//		{
		//			show[x][y] = MuchMine(mine,x,y) + '0';
		//		}
		//		else
		//		{
		//			show[x][y] = MuchMine(mine,x,y) + '0';
		//			Ass(mine,show,x,y);
		//		}
		//		DisplayBoard(show,ROW,COL);
		//	//show[x][y] = MuchMine(mine,x,y) + '0';
		//	//tmp = (int)MuchMine(mine,x,y);
		//	//Ass(mine,show,x,y);
		//	//DisplayBoard(show,ROW,COL);
		//	//	/*GetMineCount(mine,show,x,y);*/
		//	//stop -= tmp;
		//}
		//else
		//	printf("���������룡");
		//}
}
int IsWin(char show[ROWS][COLS],int row,int col,int diff)
{
	int i = 0;
	int j = 0;
	int sum = 0;
	for(i=1; i<=row; i++)
	{
		for(j=1; j<=col; j++)
		{
			if(show[i][j] == '*')
				sum++;
		}
	}
	return sum;
}
int MuchMine(char mine[ROWS][COLS],int x,int y)
{
	return  mine[x-1][y-1] + mine[x-1][y] +  mine[x-1][y+1]+ 
            mine[x][y-1]   +                 mine[x][y+1]  + 
		    mine[x+1][y-1] + mine[x+1][y] +  mine[x+1][y+1]- 8 * '0';
}
void Ass(char mine[ROWS][COLS],char show[ROWS][COLS],int x,int y,int *Num)
{
	int i = 0;	
	int j = 0;
	int AroundCount = 0;
	if(x>0 && x<=ROW && y>0 && y<=COL){
		if (!MuchMine(mine,x,y))
		{
			(*Num)++;
			show[x][y] = '0';
			for (i = -1; i <= 1; i++)
			{
				for (j = -1; j <= 1; j++)
				{
					if (x + i >= 1 && x + i <= ROW && y + j >= 1 && y + j <= COL)
					{
						if (i != 0 || j != 0)
						{
							if(show[x+i][y+j] != '0')
								Ass(mine, show, x + i, y + j,Num);//�Դ�������Χ�İ˸����������ж��Ƿ�Ϊ0��ֻҪ��0����������Ӧ�������жϲ���ɨ�ף�ֱ��û���������0Ϊֹ��
						}                                               //��Ҳ�ǵݹ��˼�롣
					}
				}
			}
		}
		else
		{
			(*Num)++;
			show[x][y] = MuchMine(mine,x,y) + '0';
		}
	}
}
//{
//	int p = 0;
//	int q = 0;
//	if(x>0 && x<=ROW && y>0 && y<=COL)
//	{
//		if(MuchMine(mine,x,y) != '0')
//		{
//			if(MuchMine(mine,x-1,y-1) != '0')
//			{
//				show[x-1][y-1] = MuchMine(mine,x-1,y-1) + '0';
//			}
//			else
//			{
//				show[x-1][y-1] = MuchMine(mine,x-1,y-1) + '0';
//				p = x-1;
//				q = y-1;
//				Ass(mine,show,p,q);
//			}
//			if(MuchMine(mine,x-1,y) != '0')
//			{
//				show[x-1][y] = MuchMine(mine,x-1,y) + '0';
//			}
//			else
//			{
//				show[x-1][y] = MuchMine(mine,x-1,y) + '0';
//				p = x-1;
//				q = y;
//				Ass(mine,show,p,q);
//			}
//			if(MuchMine(mine,x-1,y+1) != '0')
//			{
//				show[x-1][y+1] = MuchMine(mine,x-1,y+1) + '0';
//			}
//			else
//			{
//				show[x-1][y+1] = MuchMine(mine,x-1,y+1) + '0';
//				p = x-1;
//				q = y+1;
//				Ass(mine,show,p,q);
//			}
//			if(MuchMine(mine,x,y-1) != '0')
//			{
//				show[x][y-1] = MuchMine(mine,x,y-1) + '0';
//			}
//			else
//			{
//				show[x-1][y-1] = MuchMine(mine,x-1,y-1) + '0';
//				p = x-1;
//				q = y-1;
//				Ass(mine,show,p,q);
//			}
//			if(MuchMine(mine,x,y+1) != '0')
//			{
//				show[x][y+1] = MuchMine(mine,x,y+1) + '0';
//			}
//			else
//			{
//				show[x][y+1] = MuchMine(mine,x,y+1) + '0';
//				p = x;
//				q = y+1;
//				Ass(mine,show,p,q);
//			}
//			if(MuchMine(mine,x+1,y-1) != '0')
//			{
//				show[x+1][y-1] = MuchMine(mine,x+1,y-1) + '0';
//			}
//			else
//			{
//				show[x+1][y-1] = MuchMine(mine,x+1,y-1) + '0';
//				p = x+1;
//				q = y-1;
//				Ass(mine,show,p,q);
//			}
//			if(MuchMine(mine,x+1,y) != '0')
//			{
//				show[x+1][y] = MuchMine(mine,x+1,y) + '0';
//			}
//			else
//			{
//				show[x+1][y] = MuchMine(mine,x+1,y) + '0';
//				p = x+1;
//				q = y;
//				Ass(mine,show,p,q);
//			}
//			if(MuchMine(mine,x+1,y+1) != '0')
//			{
//				show[x+1][y+1] =MuchMine(mine,x+1,y+1) + '0';
//			}
//			else
//			{
//				show[x+1][y+1] = MuchMine(mine,x+1,y+1) + '0';
//				p = x+1;
//				q = y+1;
//				Ass(mine,show,p,q);
//			}
//		}
//		}
//}
//int GetMineCount(char mine[ROWS][COLS],char show[ROWS][COLS],int m,int n)
//{
//	int sum = 0;
//	if(MuchMine(mine,m,n) == '0')
//	{
//		show[m][n] = '0';
//		Ass(mine,show,m,n);
//		sum++;
//		DisplayBoard(show,ROW,COL);
//	}
//	else
//	{
//		show[m][n] = MuchMine(mine,m,n);
//		sum += (int)MuchMine(mine,m,n);
//		DisplayBoard(show,ROW,COL);
//	}
//	return sum;
//}