#define _CRT_SECURE_NO_WARNINGS 1
//shell�����㷨
#include<stdio.h>
//
//void shellsort(int v[],int n)
//{
//	int gap,i,j,temp;
//	for(gap = n/2 ; gap>0 ;gap/=2)
//	{
//		for(i=gap ; i<n ;i++)
//		{
//			for(j=i-gap ; j>=0 && v[j]>v[j+gap] ; j-=gap)
//			{
//				temp = v[j];
//				v[j] = v[j+gap];
//				v[j+gap] = temp;
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[] = {6,656,5,546,46,5435,43,4,13,4,35,465,66,354,45,88,56};
//	int n = sizeof(arr)/sizeof(arr[0]);
//	int i = 0;
//	shellsort(arr,n);
//	for(i=0 ; i<n ; i++)
//	{
//		printf("%6d",arr[i]);
//	}
//	printf("\n");
//	return 0;
//}

void expand(char s1[],char s2[])
{
	char c;
	int i,j;
	i = j = 0;

	while((c = s1[i++]) != '\0')
	{
		if(s1[i] == '-' && s1[i+1] >=c)
		{
			i++;
		while(c<s1[i])
			s2[j++] = c++;
		}
		else
		{
			s2[j++] = c;
		}

	}
	s2[j] = '\0';

}

int main()
{
	char s1[] = "a-z";
	char s2[100] = {0};
	expand(s1,s2);
	printf("%s",s2);
	system("pause");
	return 0;
}