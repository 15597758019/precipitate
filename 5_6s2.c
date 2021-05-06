#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
int main()
{
	int i, j, num[5], minID, tmp;
	srand(time(NULL));
	printf("初始数据序列：");
	for (i = 0; i < 5; i++)
	{
		num[i] = rand() % 10;
		printf("%4d", num[i]);
	}
	for (i = 0; i < 4; i++)
	{
		for (minID = i, j = i + 1; j < 5;j++)
		if (num[j] < num[minID])
			minID = j;
		tmp = num[i];
		num[i] = num[minID];
		num[minID] = tmp;
		Sleep(500);
		printf("\n第%2d趟排序后：", i + 1);
		for (j = 0; j < 5; j++)
		{
			Sleep(500);
			printf("%4d", num[j]);
		}

	}
	return 0;
}
