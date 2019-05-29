#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<assert.h>
char *Mystrncpy(char *dest, const char *src, int n)
{
	char *p = dest; int i = 0;
	assert(dest);
	assert(src);
	for (i = 0; i < n; i++)
	{
		*dest++ = *src++;
	}
	return p;

}
int main()
{
	char str1[] = "asdfgh";
	char str2[] = "cdewsxqaz";
	Mystrncpy(str1, str2, 5);
	printf("%s", str1);
	system("pause");
}