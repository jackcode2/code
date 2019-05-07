#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
char* my_strchr(const char*str, char c)
{
	assert(str != NULL);
	while (*str != '\0')//当字符串没有走到结束标识符时，进行循环
	{
		/*当字符串的指针指向位置的字符和要查找的字符c相等时，返回此时的字符串，否则将字符串指针++,
		再循环进行下一次比较,直到找到字符c。如果循环完了也没有找到那么返回空指针*/
		if (*str == c)
		{
			return str;
		}
		str++;
	}
	return NULL;
}
int main()
{
	char* str = "abcdefgh";
	char c = 'd';
	char* ret = NULL;
	ret = my_strchr(str, c);
	if (ret != NULL)
	{
		printf("找到了:%s\n", ret);
	}
	else
	{
		printf("没找到\n");
	}
	system("pause");
	return 0;
}
