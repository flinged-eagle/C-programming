#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Person_info
{
	char name[30];
	char number[30];
}Person_info;

#define SIZE 1000

typedef struct Address_Person_info
{
	Person_info List[SIZE];
	int size;
}Address_Person_info;

enum choice
{
	Add = 1, Del, Find, Alter, Sort, Show, Clear
};

Address_Person_info p1;
void Add_List()
{
	if (p1.size < SIZE)
	{
		printf("请输入添加姓名：\n");
		scanf("%s", p1.List[p1.size].name);
		printf("请输入添加号码：\n");
		scanf("%s", p1.List[p1.size].number);
		p1.size++;
		printf("添加一条信息成功！\n");
	}
	else
	{
		printf("插入失败\n");
	}
}

void Del_List()
{
	char name[10] = { 0 };

	printf("请输入删除姓名：\n");
	scanf("%s", name);

	for (int i = 0; i < p1.size; i++)
	{
		if (strcmp(name, p1.List[i].name) == 0)
		{
			strcpy(p1.List[i].name, p1.List[p1.size-1].name);
			strcpy(p1.List[i].number, p1.List[p1.size-1].number);
			--p1.size;
			printf("删除成功\n");
			return;
		}
	}
	printf("查无此人!\n");
}

void Find_List()
{
	char name[10] = { 0 };
	int count = 0;

	printf("请输入查找姓名：\n");
	scanf("%s", name);

	for (int i = 0; i < p1.size; i++)
	{
		if (strcmp(name, p1.List[i].name) == 0)
		{
			printf("[%d]	%s		%s\n", i, p1.List[i].name, p1.List[i].number);
			count++;
		}
	}
	printf("搜索到的%d条信息\n",count);
}

void Alter_List()
{
	char name[10] = { 0 };
	int i = 0;

	printf("请输入修改的姓名：\n");
	scanf("%s", name);

	while (strcmp(name, p1.List[i].name) != 0 && i < p1.size)
	{
		i++;
	}
	int num = -1;
	if (i != p1.size)
	{
		printf("请输入需要修改的参数:\n1.name	2.number\n");
		scanf("%d", &num);
		switch (num)
		{
		case 1: 
			printf("请输入修改的姓名：\n");
			scanf("%s", name);
			strcpy(p1.List[i].name, name);
			printf("修改成功\n");
			break;
		case 2:
			printf("请输入修改的号码：\n");
			scanf("%s", name);
			strcpy(p1.List[i].number, name);
			printf("修改成功\n");
			break;
		default:
			printf("error\n");
		}
	}
	else
	{
		printf("查无此人\n");
	}

}
//姓名排序 升序
void Sort_List()
{
	char pm[20] = { 0 };

	for (int i = 0; i < p1.size; i++)
	{
		for (int j = i+1; j < p1.size; j++)
		{
			if (strcmp(p1.List[i].name, p1.List[j].name) > 0)
			{
				strcpy(pm, p1.List[i].name);
				strcpy(p1.List[i].name, p1.List[j].name);
				strcpy(p1.List[j].name, pm);

				strcpy(pm, p1.List[i].number);
				strcpy(p1.List[i].number, p1.List[j].number);
				strcpy(p1.List[j].number, pm);
			}
		}
	}
	printf("排序完成\n");
}

void Show_List()
{
	for (int i = 0; i < p1.size; i++)
	{
		printf("[%d]	%s	%s\n",i, p1.List[i].name, p1.List[i].number);
	}
	printf("打印了%d条信息\n", p1.size);
}

void Clear_List()
{
	char p = 0;

	fflush(stdin);  //清空键盘缓存区
	printf("确认清空(y/s)\n");
	scanf("%c", &p);
	if (p == 'y')
		p1.size = 0;
	else
		printf("取消\n");
}

void menu()
{
	printf("-----------------------------------\n");
	printf("-------------1.添加----------------\n");
	printf("-------------2.删除----------------\n");
	printf("-------------3.查找----------------\n");
	printf("-------------4.修改----------------\n");
	printf("-------------5.排序----------------\n");
	printf("-------------6.打印----------------\n");
	printf("-------------7.清空----------------\n");
	printf("-----------------------------------\n");
	printf("-------------0.exit----------------\n");
	printf("-----------------------------------\n");
}

int main()
{
	int choice = 1;
	//实现增删改查
	while (choice)
	{
		menu();
		printf("请输入你的选择：\n");
		scanf("%d", &choice);
		system("cls");
		switch (choice)
		{
		case Add:Add_List();   // 增
			break;
		case Del:Del_List();	// 删
			break;
		case Find:Find_List();  // 查
			break;
		case Alter:Alter_List(); // 改
			break;
		case Sort:Sort_List();  // 排序（姓名）
			break;
		case Show:Show_List();  // 打印
			break;
		case Clear:Clear_List(); // 整体清空
			break;
		case 0:
			break;
		default:
			printf("输入有误\n");
			break;
		}
	}

	system("pause");
	return 0;
}