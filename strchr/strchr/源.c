#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
char* my_strchr(const char*str, char c)
{
	assert(str != NULL);
	while (*str != '\0')//���ַ���û���ߵ�������ʶ��ʱ������ѭ��
	{
		/*���ַ�����ָ��ָ��λ�õ��ַ���Ҫ���ҵ��ַ�c���ʱ�����ش�ʱ���ַ����������ַ���ָ��++,
		��ѭ��������һ�αȽ�,ֱ���ҵ��ַ�c�����ѭ������Ҳû���ҵ���ô���ؿ�ָ��*/
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
		printf("�ҵ���:%s\n", ret);
	}
	else
	{
		printf("û�ҵ�\n");
	}
	system("pause");
	return 0;
}
