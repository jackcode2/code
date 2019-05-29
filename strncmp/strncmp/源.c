#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<assert.h>
char *Mystrncmp(char *dest, char *src, int n)
{
	   assert(dest);
		assert(src);
		while (n--)
		{
			if (*dest == *src)
			{
				dest++;
				src++;
			}
			else
			{
				if ((*dest - *src)<0)
					return -1;
				else
					return 1;
			}
		}
		return 0;
	}	
int main()
{
	printf("%d\n", Mystrncmp("arccdc", "abce",4));
	system("pause");
	return 0;
}