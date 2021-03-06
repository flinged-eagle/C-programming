#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//姓名、性别、年龄、电话、住址
typedef struct Person_info
{
	char name[30];
	int age;
	char sex[5];
	char number[30];
	char address[40];

}Person_info;


typedef struct Address_Person_info
{
	Person_info *List;
	int size;
	int List_capacity;
}Address_Person_info;

enum choice
{
	Add = 1, Del, Find, Alter, Sort, Show, Clear
};

Address_Person_info p1;  //全局变量

void init()
{
	p1.List_capacity = 2;
	p1.size = 0;
	p1.List = (Person_info*)malloc(sizeof(Person_info)* p1.List_capacity);
}

void check_capacity()
{
	if (p1.List_capacity == p1.size + 1)
	{
		p1.List_capacity *= 5;
		p1.List = (Person_info*)realloc(p1.List, sizeof(Person_info)* p1.List_capacity);
	}
}

//void check_capacity()
//{
//	Person_info *p2;
//	if (p1.List_capacity == p1.size + 1)
//	{
//		p1.List_capacity *= 5;
//		p2 = (Person_info*)malloc(sizeof(Person_info)*p1.List_capacity);
//
//		for (int i = 0; i < p1.size; i++)
//		*p2 = p1.List[i];
//		p1.List = p2;
//	}
//}

//姓名、性别、年龄、电话、住址
void Add_List()
{
	check_capacity();

	printf("请输入添加姓名：\n");
	scanf("%s", p1.List[p1.size].name);
	printf("请输入添加性别：\n");
	scanf("%s", p1.List[p1.size].sex);
	printf("请输入添加年龄：\n");
	scanf("%d", &p1.List[p1.size].age);
	printf("请输入添加号码：\n");
	scanf("%s", p1.List[p1.size].number);
	printf("请输入添加住址：\n");
	scanf("%s", p1.List[p1.size].address);
	p1.size++;
	printf("添加一条信息成功！\n");
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
			strcpy(p1.List[i].name, p1.List[p1.size - 1].name);
			strcpy(p1.List[i].sex, p1.List[p1.size - 1].sex);
			p1.List[i].age = p1.List[p1.size - 1].age;
			strcpy(p1.List[i].number, p1.List[p1.size - 1].number);
			strcpy(p1.List[i].address, p1.List[p1.size - 1].address);
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
			printf("[%d]		%s		%s		%d		%s		%s\n", i, p1.List[i].name, p1.List[i].sex, p1.List[i].age, p1.List[i].number, p1.List[i].address);
			count++;
		}
	}
	printf("搜索到的%d条信息\n", count);
}

void Alter_List()
{
	char name[10] = { 0 };
	int i = 0;
	int age = 0;

	printf("请输入修改的姓名：\n");
	scanf("%s", name);

	while (strcmp(name, p1.List[i].name) != 0 && i < p1.size)
	{
		i++;
	}
	int num = -1;
	if (i < p1.size)
	{
		printf("请输入需要修改的参数:\n1.name	2.sex 3.age 4.number 5.address\n");
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
			printf("请输入修改的性别：\n");
			scanf("%s", name);
			strcpy(p1.List[i].sex, name);
			printf("修改成功\n");
			break;
		case 3:
			printf("请输入修改的年龄：\n");
			scanf("%d", &age);
			p1.List[i].age = age;
			printf("修改成功\n");
			break;
		case 4:
			printf("请输入修改的号码：\n");
			scanf("%s", name);
			strcpy(p1.List[i].number, name);
			printf("修改成功\n");
			break;
		case 5:
			printf("请输入修改的地址：\n");
			scanf("%s", name);
			strcpy(p1.List[i].address, name);
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
		for (int j = i + 1; j < p1.size; j++)
		{
			if (strcmp(p1.List[i].name, p1.List[j].name) > 0)
			{
				// name sex age number address
				strcpy(pm, p1.List[i].name);
				strcpy(p1.List[i].name, p1.List[j].name);
				strcpy(p1.List[j].name, pm);

				strcpy(pm, p1.List[i].sex);
				strcpy(p1.List[i].sex, p1.List[j].sex);
				strcpy(p1.List[j].sex, pm);

				int age = p1.List[i].age;
				p1.List[i].age = p1.List[j].age;
				p1.List[j].age = age;

				strcpy(pm, p1.List[i].number);
				strcpy(p1.List[i].number, p1.List[j].number);
				strcpy(p1.List[j].number, pm);

				strcpy(pm, p1.List[i].address);
				strcpy(p1.List[i].address, p1.List[j].address);
				strcpy(p1.List[j].address, pm);
			}
		}
	}
	printf("排序完成\n");
}

void Show_List()
{
	for (int i = 0; i < p1.size; i++)
	{
		printf("[%d]\t%s\t%s\t%d\t%s\t%s\n", i, p1.List[i].name, p1.List[i].sex, p1.List[i].age, p1.List[i].number, p1.List[i].address);

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
	{
		free(p1.List);
		p1.List = NULL;
		p1.size = 0;
	}
	else
		printf("取消\n");
}

void save() //保存到文件
{
	FILE *fp = fopen("../text.txt", "w");
	if (fp == NULL)
	{
		printf("保存失败！\n");
		return;
	}

	for (int i = 0; i < p1.size; i++)
	{
		fwrite(p1.List+i, sizeof(Person_info),1,fp);
	}
	fclose(fp);
	printf("保存完成！保存了%d个成员\n",p1.size);
}

void load() //加载
{
	Person_info tmp = { 0 };

	FILE *fp = fopen("../text.txt", "r");
	if (fp == NULL)
	{
		printf("读取失败！\n");
		return;
	}
	//fread 返回值为实际读到的元素个数
	while (fread(&tmp, sizeof(Person_info), 1, fp))
	{
		check_capacity();
		p1.List[p1.size] = tmp;
		p1.size++;
	}
	fclose(fp);

	printf("加载完成！加载了%d个对象\n",p1.size);

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
	init();
	load();
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
		case 0: save();
			break;
		default:
			printf("输入有误\n");
			break;
		}
	}

	system("pause");
	return 0;
}
