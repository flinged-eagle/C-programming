#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//1.模拟实现strncpy
//2.模拟实现strncat
//3.模拟实现strncmp

char *my_strncpy(char *strDest, const char *strSource, int num)
{
	assert(strSource != NULL);
	assert(strDest != NULL);

	for (int i = 0; i < num && strlen(strSource)>0; i++)
	{
		*(strDest + i) = *(strSource + i);
	}
	return strDest;
}

char *my_strncat(char *strDest, const char *strSource, size_t count)
{
	assert(strSource != NULL);
	assert(strDest != NULL);

	int i = strlen(strDest);

	for (int j = 0; j < count && strlen(strSource)>0; j++,i++)
	{
		*(strDest + i) = *(strSource + j);
	}
	return strDest;
}

int my_strncmp(const char *string1, const char *string2, size_t count)
{
	assert(string1 != NULL);
	assert(string2 != NULL);

	while (count--)
	{
		if (*string1 > *string2)
		{
			return 1;
		}
		else if (*string1 < *string2)
		{
			return -1;
		}
		string1++;
		string2++;
	}
	return 0;
}



int main()
{
	char p[100] = "cat is cute!";

	my_strncpy(p, "dog", 3);

	printf("%s\n", p);

	my_strncat(p, "beautiful", 9);

	printf("%s\n", p);
	
	char p2[100] = "cat is not cute!";

	int i = my_strncmp(p, p2, 6);

	if (i == 0)
		printf("same");
	else if (i > 0)
		printf("str1 > str2");
	else
		printf("str1 < str2");

	system("pause");
	return 0;
}