#include<stdio.h>
#include<stdlib.h>
//1.实现strcpy

void my_strcpy(char *p1, char *p2)
{
	while (*p2++ = *p1++, *p1 != '\0')
	{
	}

}

//2.实现strcat

char *my_strcat(char *str, const char *strsource)
{
	int i = 0;
	int j = 0;
	while (*(str + i) != 0)
	{
		i++;
	}
	while (*(strsource + j) != 0)
	{
		*(str + i) = *(strsource + j);
		i++;
		j++;
	}
	return str;
}

//3.实现strstr

char* my_strstr(const char *string, const char *strCharSet)
{
	char *p = (char*)string;
	int i = 0;

	while (*p != '\0' && *(strCharSet+i) != '\0')
	{
		if (*p == *(strCharSet + i))
			i++;
		else
			i = 0;
		p++;
	}
	if (*(strCharSet + i) == '\0')
		return p - i;
	else
		return NULL;
}

//4.实现strchr
//返回字符首次出现的指针
char *my_strchr(const char *string, int c)
{	
	char *p = (char*)string;
	while (*p != (char)c)
	{
		p++;
	}
	if (*p == (char)c)
		return p;
	else
		return NULL;

}
//5.实现strcmp
//比较字符串的大小
int my_strcmp(const char *string1, const char *string2)
{
	while (*string1 != '\0' && *string2 != '\0')
	{
		if (*string1 > *string2)
			return 1;
		else if (*string1 > *string2)
			return -1;
		string1++;
		string2++;
	}
	if (*string1 == *string2)
		return 0;
	return *string1 ? 1 : -1;
}

//6.实现memcpy
//指针定义字符串，创建一个字符串！！常量 ！！
void *my_memcpy(void *dest, const void *src, size_t count)
{

	char *p = dest;
	while (count)
	{
		*p = *((char*)src)++;

		p++;
		count--;
	}
	return dest;
}


//7.实现memmove
//当目标区域与源区域!!重叠!!时，保证源串在被复盖之前将重叠区域的字节拷贝到目标区域中，但复制后src内容会被更改
void *my_memmove(void *dest, const void *src, size_t count)
{
	if (dest < src)
	{
		while (count)
		{
			*((char*)dest)++ = *((char*)src)++;
			count--;
		}
	}
	else						//dest>src
	{
		while (count)
		{
			*((char*)dest+count) = *((char*)src+count);
			count--;
		}
	}

}

int main()
{
	//指针定义字符串，创建一个字符串！！常量 ！！
	//char *arr1 = "hello world";
	//char *arr2 = "hello";
	//无法运行my_memcpy;
	char arr1[] = "hello world";
	char arr2[] = "hello";
	char c = 'm';
	char *num = {0};

	my_memmove(arr1, arr1+ 6, 5);
	printf("%s", arr1);


	//指针定义字符串，创建一个字符串！！常量 ！！
	my_memcpy(arr1 + 6, arr2, 5);
	printf("%s", arr1);

	if (my_strcmp(arr1, arr2) > 0)
		printf("str1 > str2");
	else if (my_strcmp(arr1, arr2) < 0)
		printf("str2 > str1");
	else
		printf("str1 equal str2");

	if (strchr(arr1, c) != NULL)
		printf("%p\n", my_strchr(arr1, c));
	else
		printf("error, not found\n");

	if ((num = my_strstr(arr1, arr2)) == NULL)
	{
		printf("error , not found\n");
	}
	else
		printf("%p \n", num);

	system("pause");
	return 0;
}


