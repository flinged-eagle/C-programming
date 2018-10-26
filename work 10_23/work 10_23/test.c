#define _CRT_SECURE_NO_WARNINGS 1

//unsigned int reverse_bit(unsigned int value); 
//这个函数的返回值value的二进制位模式从左到右翻转后的值。 
//
//如： 
//在32位机器上25这个值包含下列各位： 
//00000000000000000000000000011001 
//翻转后：（2550136832） 
//10011000000000000000000000000000 
//程序结果返回： 
//2550136832 
#include<stdio.h>
#include<math.h>

unsigned int reverse_bit(unsigned int value)
{
	unsigned int ret = 0;
	int i = 31;

	while(value)
	{
		if((value & 1) == 1)
			ret += pow(2,i);
		i--;
		value >>= 1;
	}
	return ret;
}

int main()
{
	unsigned int num = 0;
	int ret = 0;

	scanf("%u",&num);
	ret = reverse_bit(num);
	printf("%u",ret);

	return 0;
}

//不用（a+b）/2这种方式，求两个数的平均值。

int Add(int a, int b)
{
	if(a%2 == 1 && b%2 ==1)
	{
		a >>= 1;
		b >>= 1;
		return a + b + 1;
	}else
	{
		a >>= 1;
		b >>= 1;
		return a + b;
	}
	
}

int main()
{
	int a = 0;
	int b = 0;
	int ret = 0;

	scanf("%d%d",&a,&b);
	ret = Add(a,b);
	printf("%d",ret);
	return 0;
}

//3.编程实现： 
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。 
//请找出这个数字。（使用位运算） 
//
#include<stdio.h>


int main()
{
	int arr[] = {1,2,3,4,55,66,1,2,3,4,55,66,9};
	int size = sizeof(arr)/sizeof(arr[0]);
	int i = 0;
	int ret = arr[0];

	for(i=1; i<size; i++)
		ret ^= arr[i];
	printf("%d",ret);

	return 0;
}

//4. 
//有一个字符数组的内容为:"student a am i", 
//请你将数组的内容改为"i am a student". 
//要求： 
//不能使用库函数。 
//只能开辟有限个空间（空间个数和字符串的长度无关）。

//将整个字符串逆序

//将整个单词逆序

#include<assert.h>

int my_strlen(const char *arr)
{
	int ret = 0;
	assert(arr);

	while(*(arr++) != '\0')
		ret++;
	
	return ret;
}
void reserve(char *arr,int i, int j)
{
	char swap = '\0';

	while(i<j)
	{
		swap = arr[i];
		arr[i] = arr[j];
		arr[j] = swap;
		i++;
		j--;
	}
}

void reserve_arr(char* arr)
{
	int i = 0;
	int j = my_strlen(arr)-1;
	int left = 0;
	int right = 0;
	reserve(arr,i,j);

	while(*(arr+i) != '\0')
	{
		left = i;
		while(*(arr+i) != ' ' && *(arr+i) != '\0')
		{
			i++;
		}
		right = i-1;
		reserve(arr,left,right);
		if(*(arr+i) != '\0')
		i++;
	}

}

int main()
{
	char arr[] = "student a am i";

	reserve_arr(arr);
	printf("%s",arr);


	return 0;
}
