#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
#include<assert.h>
char *my_strcat(char *dest, char *src)
{
	char *ret = dest;
	assert(dest);
	assert(src);
	while (*dest)
	{
		dest++;
	}
	while (*dest++ = *src++)

	{
		;
	}

	return ret;

}
int main()
{
	char arr1[15] = "abcd";
	char *arr2 = "ef";
	printf("%s\n", my_strcat(arr1, arr2));
	system("pause");
	return 0;
}
