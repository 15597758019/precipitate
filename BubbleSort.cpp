
#include<stdio.h>
#include<time.h>
#include<math.h>
#define N 10
#define M 20
int arr[N];
void RanNum(int arr[], int n);
void BuSort(int *arr, int n);
void Print_f();
int main()
{
	RanNum(arr, N);
	printf("�������ظ���������У�");
	Print_f();
	BuSort(arr, N);
	printf("����ð��������");
	Print_f();
}
void RanNum(int arr[], int n)
{
	int arrayindex[N * 2] = { 0 };
	int i = 0;
	srand(time(NULL));
	while (i < n)
	{
		int q = rand() % M;
		if (arrayindex[q] == 1)
			continue;
		arr[i] = q;
		arrayindex[q] = 1;
		i++;
	}
}
void Print_f()
{
	int i;
	for (i = 0; i<N; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void BuSort(int *arr, int n)
{
	int i, j;
	int temp;
	for (i = 0; i<n - 1; i++)
	{
		for (j = 0; j<n - 1 - i; j++)
		{
			if (arr[j]<arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		printf("��%d��ð������", i);
		Print_f();
	}
}
