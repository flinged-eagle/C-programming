#define _CRT_SECURE_NO_WARNINGS 1

//unsigned int reverse_bit(unsigned int value); 
//��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ�� 
//
//�磺 
//��32λ������25���ֵ�������и�λ�� 
//00000000000000000000000000011001 
//��ת�󣺣�2550136832�� 
//10011000000000000000000000000000 
//���������أ� 
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

//���ã�a+b��/2���ַ�ʽ������������ƽ��ֵ��

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

//3.���ʵ�֣� 
//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ� 
//���ҳ�������֡���ʹ��λ���㣩 
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
//��һ���ַ����������Ϊ:"student a am i", 
//���㽫��������ݸ�Ϊ"i am a student". 
//Ҫ�� 
//����ʹ�ÿ⺯���� 
//ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���

//�������ַ�������

//��������������

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
