//存入5行5列数字，并找出最大值在第几行第几列
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int GenRanNums(int arr[][5], int min, int max);
int PrintMatrix(int arr[][5]);
int FindPrint(int arr[][5]);
int main()
{
	int n[5][5];
	srand(time(0));
	GenRanNums(n, 10, 99);
	PrintMatrix(n);
	FindPrint(n);
	return 0;
}
int GenRanNums(int arr[][5], int min, int max)
{
	int i, j;
	int arr1[5][5];
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			arr1[i][j] = rand() % 90 + 10;
			while (arr1[i][j] == -1)
			{
				arr1[i][j] = rand() % 90 + 10;
			}
			arr[i][j] = arr1[i][j];
			arr1[i][j] = -1;
		}
	}
}
int PrintMatrix(int arr[][5])
{
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf(" %3d", arr[i][j]);
		}
		printf("\n");
	}
}
int FindPrint(int arr[][5])
{
	int i, j, row, col;
	int max = arr[0][0];
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (arr[i][j]>max)
			{
				max = arr[i][j];
				row = i;
				col = i;
			}
		}
	}
	printf("最大数字是第%d行第%d列的%d", row + 1, col + 1, max);
}
