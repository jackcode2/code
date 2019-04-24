#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void adjust(int arr[], int len)
{
	int left = 0;
	int right = len - 1;
	int temp = 0;
	while (left < right)
	{
		while (arr[left] % 2 == 1)
		{
			left++;
		}
		while (arr[right] % 2 == 0)
		{
			right--;
		}
		if (left < right)
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			left++;
			right--;
		}
	}
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int len = sizeof(arr) / sizeof(arr[0]);
	adjust(arr, len);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}