#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
#include <string.h>
int judge(char str1[], char str2[])
{
	int i = 0;
	int j = 0;
	int lenght = strlen(str1);
	for (j = 1; j <= lenght; j++)
	{
		{
			int tem = str1[0];
			for (i = 0; i < lenght - 1; i++)
			{
				str1[i] = str1[i + 1];
			}
			str1[lenght - 1] = tem;
		}

		if (0 == strcmp(str1, str2))
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	char s1[10] = "abcd";
	char s2[10] = "ABCD";
	printf("s1 = %s\n", s1);
	printf("s2 = %s\n", s2);
	printf("%d\n", judge(s1, s2));
	system("pause");
	return 0;
}