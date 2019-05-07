#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
/*基本思想：为了避免重叠，分为两种情况。如果目标指针变量dest的起始值小于源指针变量src的起始值，那么正着拷贝，即
从左向右拷贝。如果目标指针变量dest的起始值大于源指针变量src的起始值，那么倒着拷贝，即从右向左拷贝*/
void* my_memmove(void* dest, const void*src, int count)//因为是内存拷贝函数，所以什么类型都需要接收，所以此处用void*做函数返回值类型和参数类型
{
	assert(dest != NULL);
	assert(src != NULL);
	void* ret = dest;//因为dest在循环体内是要变化的，所以定义一个临时指针变量来存放dest的地址。dest变化会引起ret变化，但ret变化不会引起dest变化
	if (dest < src)//如果dest的起始位置小于src的起始位置，那么从左向右进行拷贝
	{
		while (count--)
		{
			*(char*)dest = *(const char*)src;//因为void*类型不能进行解引用操作，所以要进行强制类型转化，并且count是代表的是字节数，一个字节一个字节的拷贝，所以强制转化为char*类型
			++(char*)dest;//因为void*类型不能进行++运算，所以进行强制类型转化，并且如果是后置++,那么强制类型转化会先对dest进行，所以要进行前置++
			++(char)src;
		}
	}
	else
	{
		*((char*)dest + count) = *((const char*)src + count);//从右向左拷贝
		--(char*)dest;
		--(char*)src;
	}
	return ret;
}
//打印输出arr函数
void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	my_memmove(arr, arr + 3, 16);//此处的16为字节数 
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(arr, sz);
	system("pause");
	return 0;
}
