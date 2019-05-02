#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<string.h>
void Swap_arr(int *arr, int len)
{
	int left = 0;
	int right = len - 1;
	while (left < right)
	{
		while (left < right&&arr[left]%2==1)
		{
			left++;
		}
		while (left < right&&arr[right] % 2 == 0)
		{
			right--;
		}
		if (left < right)
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
}
void Show(int *arr,int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int len = sizeof(arr)/sizeof(arr[0]);
	Show(arr, len);
	Swap_arr(arr, len);
	Show(arr, len);
	system("pause");
	return 0;
}