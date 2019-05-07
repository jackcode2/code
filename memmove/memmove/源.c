#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
/*����˼�룺Ϊ�˱����ص�����Ϊ������������Ŀ��ָ�����dest����ʼֵС��Դָ�����src����ʼֵ����ô���ſ�������
�������ҿ��������Ŀ��ָ�����dest����ʼֵ����Դָ�����src����ʼֵ����ô���ſ��������������󿽱�*/
void* my_memmove(void* dest, const void*src, int count)//��Ϊ���ڴ濽������������ʲô���Ͷ���Ҫ���գ����Դ˴���void*����������ֵ���ͺͲ�������
{
	assert(dest != NULL);
	assert(src != NULL);
	void* ret = dest;//��Ϊdest��ѭ��������Ҫ�仯�ģ����Զ���һ����ʱָ����������dest�ĵ�ַ��dest�仯������ret�仯����ret�仯��������dest�仯
	if (dest < src)//���dest����ʼλ��С��src����ʼλ�ã���ô�������ҽ��п���
	{
		while (count--)
		{
			*(char*)dest = *(const char*)src;//��Ϊvoid*���Ͳ��ܽ��н����ò���������Ҫ����ǿ������ת��������count�Ǵ�������ֽ�����һ���ֽ�һ���ֽڵĿ���������ǿ��ת��Ϊchar*����
			++(char*)dest;//��Ϊvoid*���Ͳ��ܽ���++���㣬���Խ���ǿ������ת������������Ǻ���++,��ôǿ������ת�����ȶ�dest���У�����Ҫ����ǰ��++
			++(char)src;
		}
	}
	else
	{
		*((char*)dest + count) = *((const char*)src + count);//�������󿽱�
		--(char*)dest;
		--(char*)src;
	}
	return ret;
}
//��ӡ���arr����
void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	my_memmove(arr, arr + 3, 16);//�˴���16Ϊ�ֽ��� 
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(arr, sz);
	system("pause");
	return 0;
}
