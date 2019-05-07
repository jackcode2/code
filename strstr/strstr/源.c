#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<windows.h>
char *my_strstr(const char *str, char *string)
{
	int i = 0;
		assert(str&&string!=NULL);
	while ('\0' != str)
	{
		while (1)
		{
			if (string[i] != str[i])    //从第一个字符开始匹配字符是否相同
				break;
			if (string[i] == '\0')       //判断string的字符是否遍历完成
				return str;
			i++;
		}
		string++;
	}
	return NULL;
}

int main()
{
	char string[] = "you";
	char str[] = "Happy birthday to you";
	char *p = my_strstr(str, string);
	int result = p - str + 1;
	if (p != NULL)
		printf("%s found at position %d\n\n", string, result);
	else
		printf("%s not found\n", string);
	system("pause");
	return 0;
}
