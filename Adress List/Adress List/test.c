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
		printf("���������������\n");
		scanf("%s", p1.List[p1.size].name);
		printf("��������Ӻ��룺\n");
		scanf("%s", p1.List[p1.size].number);
		p1.size++;
		printf("���һ����Ϣ�ɹ���\n");
	}
	else
	{
		printf("����ʧ��\n");
	}
}

void Del_List()
{
	char name[10] = { 0 };

	printf("������ɾ��������\n");
	scanf("%s", name);

	for (int i = 0; i < p1.size; i++)
	{
		if (strcmp(name, p1.List[i].name) == 0)
		{
			strcpy(p1.List[i].name, p1.List[p1.size-1].name);
			strcpy(p1.List[i].number, p1.List[p1.size-1].number);
			--p1.size;
			printf("ɾ���ɹ�\n");
			return;
		}
	}
	printf("���޴���!\n");
}

void Find_List()
{
	char name[10] = { 0 };
	int count = 0;

	printf("���������������\n");
	scanf("%s", name);

	for (int i = 0; i < p1.size; i++)
	{
		if (strcmp(name, p1.List[i].name) == 0)
		{
			printf("[%d]	%s		%s\n", i, p1.List[i].name, p1.List[i].number);
			count++;
		}
	}
	printf("��������%d����Ϣ\n",count);
}

void Alter_List()
{
	char name[10] = { 0 };
	int i = 0;

	printf("�������޸ĵ�������\n");
	scanf("%s", name);

	while (strcmp(name, p1.List[i].name) != 0 && i < p1.size)
	{
		i++;
	}
	int num = -1;
	if (i != p1.size)
	{
		printf("��������Ҫ�޸ĵĲ���:\n1.name	2.number\n");
		scanf("%d", &num);
		switch (num)
		{
		case 1: 
			printf("�������޸ĵ�������\n");
			scanf("%s", name);
			strcpy(p1.List[i].name, name);
			printf("�޸ĳɹ�\n");
			break;
		case 2:
			printf("�������޸ĵĺ��룺\n");
			scanf("%s", name);
			strcpy(p1.List[i].number, name);
			printf("�޸ĳɹ�\n");
			break;
		default:
			printf("error\n");
		}
	}
	else
	{
		printf("���޴���\n");
	}

}
//�������� ����
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
	printf("�������\n");
}

void Show_List()
{
	for (int i = 0; i < p1.size; i++)
	{
		printf("[%d]	%s	%s\n",i, p1.List[i].name, p1.List[i].number);
	}
	printf("��ӡ��%d����Ϣ\n", p1.size);
}

void Clear_List()
{
	char p = 0;

	fflush(stdin);  //��ռ��̻�����
	printf("ȷ�����(y/s)\n");
	scanf("%c", &p);
	if (p == 'y')
		p1.size = 0;
	else
		printf("ȡ��\n");
}

void menu()
{
	printf("-----------------------------------\n");
	printf("-------------1.���----------------\n");
	printf("-------------2.ɾ��----------------\n");
	printf("-------------3.����----------------\n");
	printf("-------------4.�޸�----------------\n");
	printf("-------------5.����----------------\n");
	printf("-------------6.��ӡ----------------\n");
	printf("-------------7.���----------------\n");
	printf("-----------------------------------\n");
	printf("-------------0.exit----------------\n");
	printf("-----------------------------------\n");
}

int main()
{
	int choice = 1;
	//ʵ����ɾ�Ĳ�
	while (choice)
	{
		menu();
		printf("���������ѡ��\n");
		scanf("%d", &choice);
		system("cls");
		switch (choice)
		{
		case Add:Add_List();   // ��
			break;
		case Del:Del_List();	// ɾ
			break;
		case Find:Find_List();  // ��
			break;
		case Alter:Alter_List(); // ��
			break;
		case Sort:Sort_List();  // ����������
			break;
		case Show:Show_List();  // ��ӡ
			break;
		case Clear:Clear_List(); // �������
			break;
		case 0:
			break;
		default:
			printf("��������\n");
			break;
		}
	}

	system("pause");
	return 0;
}