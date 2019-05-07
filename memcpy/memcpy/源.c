#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
void* my_memcpy(void* dest, const void* src, int n)//因为memcpy是内存拷贝函数，所以必须什么类型都能接收，所以此处用void*做参数类型和返回值类型
{
	assert(dest != NULL);
	assert(src != NULL);
	char* ret = dest;//因为dest在循环体中不断发生变化，所以将dest的地址存放在指针变量ret中，此后ret就随着dest进行变化，但dest不会随着ret进行变化，最后函数返回ret的值
	while (n--)
	{
		*(char*)dest = *(const char*)src;//void类型不能进行解引用操作，所以要进行强制类型转化，因为此处n指的是字节数，需要一个字节一个字节拷贝，所以强制类型转化为char*。
		++(char*)dest;//void*类型不能进行++操作，所以要进行强制类型转化，如果是后置++，那么强制类型转化先对dest进行，所以要进行前置++
		++(char*)src;
	}
	return ret;
}

//arr1打印输出函数
void print(int arr1[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
}

int main()
{
	char* str1[10] = { 0 };
	char* str2 = "abcdefg";
	char* ret = NULL;
	ret = my_memcpy(str1, str2, 5);//n代表的是字节数
	printf("%s\n", ret);
	int arr1[10] = { 0 };
	int arr2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	my_memcpy(arr1, arr2, 40);//此处n是字节数，40个字节也就是10个int型值
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	print(arr1, sz);
	system("pause");
	return 0;
}
