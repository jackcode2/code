#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
void find(int arr[3][3], int *px, int * py, int key)
{
	int x = 0;
	int y = *py - 1;
	while ((x<*px) && (y>=0))
	{
		if (arr[x][y] == key)
		{
			*px = x;
			*py = y;
			return ;
		}
		else if (arr[x][y] < key)
		{
			x++;
		}
		else if (arr[x][y]>key);
		{
			y--;
		}}
	*px = -1;
	*py = -1;
	
}
void print_Arrs(int *arr, int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%d ", arr[i*col + j]);
		}
		printf("\n");
	}
}
int main()
{
	int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	print_Arrs((int*)arr, 3, 3);
	int x = 3; int y = 3;
	find(arr, &x, &y, 4);
	if (x != -1 && y != -1)
	{
		printf("找到了,下标为：%d,%d\n", x, y);
	}
	else
	{
		printf("没有找到\n");
	}
	system("pause");
	return 0;
}