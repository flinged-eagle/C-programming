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
//#include<math.h>
//
//unsigned int reverse_bit(unsigned int value)
//{
//	unsigned int ret = 0;
//	int i = 31;
//
//	while(value)
//	{
//		if((value & 1) == 1)
//			ret += pow(2,i);
//		i--;
//		value >>= 1;
//	}
//	return ret;
//}
//
//int main()
//{
//	unsigned int num = 0;
//	int ret = 0;
//
//	scanf("%u",&num);
//	ret = reverse_bit(num);
//	printf("%u",ret);
//
//	return 0;
//}

//���ã�a+b��/2���ַ�ʽ������������ƽ��ֵ��

//int Add(int a, int b)
//{
//	if(a%2 == 1 && b%2 ==1)
//	{
//		a >>= 1;
//		b >>= 1;
//		return a + b + 1;
//	}else
//	{
//		a >>= 1;
//		b >>= 1;
//		return a + b;
//	}
//	
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int ret = 0;
//
//	scanf("%d%d",&a,&b);
//	ret = Add(a,b);
//	printf("%d",ret);
//	return 0;
//}

//3.���ʵ�֣� 
//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ� 
//���ҳ�������֡���ʹ��λ���㣩 
//
//#include<stdio.h>
//
//
//int main()
//{
//	int arr[] = {1,2,3,4,55,66,1,2,3,4,55,66,9};
//	int size = sizeof(arr)/sizeof(arr[0]);
//	int i = 0;
//	int ret = arr[0];
//
//	for(i=1; i<size; i++)
//		ret ^= arr[i];
//	printf("%d",ret);
//
//	return 0;
//}

//4. 
//��һ���ַ����������Ϊ:"student a am i", 
//���㽫��������ݸ�Ϊ"i am a student". 
//Ҫ�� 
//����ʹ�ÿ⺯���� 
//ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���
//void fun(char* arr)
//{
//	int count = 0;
//	char arr1[10] = {0};1
//	char* arr2 = arr1; 
//	int i = 0;
//
//	while(*arr++ != '\0')
//		count++;
//	arr--;
//
//	while(*arr-- != ' ')
//	{
//	}
//	while(*arr)
//	{
//		*arr2 = *--arr
//	}
//	printf("%s",arr1);
//
//
//}
//
//int main()
//{
//	char* arr = "student a am i";
//
//	fun(arr);
//
//	//printf("%s",arr);
//	return 0;
//}