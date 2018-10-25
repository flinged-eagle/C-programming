#include<stdio.h>
#include<string.h>
#include<windows.h>
int main()
{
	char arr1[] = "welcome to china !!!!";
	char arr2[] = "*********************";
	int left=0,right=0;
	right =  strlen(arr1);
	for( ; right>=left ; left++,right--)
	{
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		printf("%s",arr2);
		Sleep(1000);
		system("cls");
	}
	
	return 0;
}