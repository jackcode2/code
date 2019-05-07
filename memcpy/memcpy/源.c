#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
void* my_memcpy(void* dest, const void* src, int n)//��Ϊmemcpy���ڴ濽�����������Ա���ʲô���Ͷ��ܽ��գ����Դ˴���void*���������ͺͷ���ֵ����
{
	assert(dest != NULL);
	assert(src != NULL);
	char* ret = dest;//��Ϊdest��ѭ�����в��Ϸ����仯�����Խ�dest�ĵ�ַ�����ָ�����ret�У��˺�ret������dest���б仯����dest��������ret���б仯�����������ret��ֵ
	while (n--)
	{
		*(char*)dest = *(const char*)src;//void���Ͳ��ܽ��н����ò���������Ҫ����ǿ������ת������Ϊ�˴�nָ�����ֽ�������Ҫһ���ֽ�һ���ֽڿ���������ǿ������ת��Ϊchar*��
		++(char*)dest;//void*���Ͳ��ܽ���++����������Ҫ����ǿ������ת��������Ǻ���++����ôǿ������ת���ȶ�dest���У�����Ҫ����ǰ��++
		++(char*)src;
	}
	return ret;
}

//arr1��ӡ�������
void print(int arr1[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
}

int main()
{
	char* str1[10] = { 0 };
	char* str2 = "abcdefg";
	char* ret = NULL;
	ret = my_memcpy(str1, str2, 5);//n��������ֽ���
	printf("%s\n", ret);
	int arr1[10] = { 0 };
	int arr2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	my_memcpy(arr1, arr2, 40);//�˴�n���ֽ�����40���ֽ�Ҳ����10��int��ֵ
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	print(arr1, sz);
	system("pause");
	return 0;
}
