#include<stdio.h>
#include<stdlib.h>
#include"compare.h"

void my_qsort(void *base, int num, int width, int(__cdecl *compare)(const void *elem1, const void *elem2))
{
	char p[1024] = {0};
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (compare(((char *)base + i*width), ((char *)base + j*width)))
			{
				for (int z = 0; z < width; z++)
				{
					*p = *((char*)base + i + z);
					*((char *)base + j + z) = *((char*)base + i + z);
					*((char *)base + j + z) = *p;
				}
			}
		}
	}
}

int main()
{
	int arr[10] = { 5, 6, 8, 2, 4, 1, 9, 0, 3, 7 };
	my_qsort(arr, 5, 4, intGreat);

	for (int i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	system("pause");
}