#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include <string.h>
#include <assert.h>
char *my_strcpy(char *str1, const char *str2)
{
	char *p = str1;
	assert(str1);
	assert(str2);
	while (*str2 != '\0')
	{
		*str1 = *str2;
		str2++;
		str1++;
	}
	*str1 = *str2;
	return p;
}

int main()
{
	char str1[10] = { 1, 2, 3 };
	char str2[] = "asdfg";
	char *ret = my_strcpy(str1, str2);
	puts(ret);
	system("pause");
	return 0;
}