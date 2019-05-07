#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<assert.h>
#include<string.h>
int my_strcmp(const char *str1, const char *str2)  
{
	assert(str1!=NULL);
	assert(str2!=NULL);
	while (*str1&&*str2 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return *str1 - *str2;
}
int main()
{
	char string1[] = "Happy BIRTHDAY TO you";
	char string2[] = "Happy BIRTHDAY TO you";
	char tmp[20];
	int result;
	printf("Compare strings:\n\t%s\n\t%s\n\n", string1, string2);
	result = my_strcmp(string1, string2);
	if (result > 0)
		strcpy(tmp, ">");
	else if (result < 0)
		strcpy(tmp, "<");
	else
		strcpy(tmp, "==");
	printf("\tstrcmp:   String 1  %s string 2\n", tmp);
	system("pause");
	return 0;
}


