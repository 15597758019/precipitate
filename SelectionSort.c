#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int i, id, j = 0, num[5], num2[10], minID, tmp, count = 0;
	srand(time(NULL));
	printf("初始数据序列：");
	for (i = 0; i < 10; i++)
	{
		num2[i] = 1 + i;
	}
	for (i = 0; i < 5; i++)
	{
		while (num2[id = rand() % 10] == -1)//标记使用过的坑位
			count++;
		num[j++] = num2[id];
		num2[id] = -1;
	}
	for (i = 0; i < 5; i++)
		printf("%4d", num[i]);
	for (i = 0; i < 4; i++)
	{
		for (minID = i, j = i + 1; j < 5; j++)
			if (num[j] < num[minID])
				minID = j;//比较，把最小的和第一个交换
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
	printf("\n产生随机数过程中重复次数%d\n", count);
	return 0;
}
