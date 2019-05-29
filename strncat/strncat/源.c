#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<assert.h>
char *Mystrncat(char *dest, const char *src, int n)
{
	char*p = dest; int i = 0;
	assert(dest);
	assert(src);
	while (*dest!=0)
	{
		*dest++;
	}
	for (i = 0; i < n; i++)
	{
		*dest++ = *(src + i);
	}
	return *p;
}
int main()
{
	char str1[20] = "asdfghf";
	char str2[20] = "65sfse";
	Mystrncat(str1, str2, 5);
	printf("%s", str1);
	system("pause");
	return 0;
}
