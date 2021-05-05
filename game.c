#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
int main()
{
	int s, j, b, k, i;
	int count = 0;
	int count1 = 0;
	int count2 = 0;
	char num;
	srand(time(0));
	printf("======欢迎进入 石头 剪子 布======\n");
	for (i = 1; i <= 5; i++)
	{
		printf("第%d局：", i);
		printf("你想出什么（石头 剪子 布）-->");
		num = getche();
		switch (num)
		{
		case 's':printf("石头"); break;
		case 'j':printf("剪子"); break;
		case 'b':printf("布"); break;
		}
		printf(" ");
		printf("电脑出的是:-->");
		k = rand() % 3;
		switch (k)
		{
		case 0:printf("石头"); break;
		case 1:printf("剪子"); break;
		case 2:printf("布"); break;
		}
		printf("--");
		if (num == 's'&&k == 0 || num == 'j'&&k == 1 || num == 'b'&&k == 2)
		{
			printf("平局\n");
			count++;
		}
		if (num == 's'&&k == 1 || num == 'j'&&k == 2 || num == 'b'&&k == 0)
		{
			printf("玩家赢\n");
			count1++;
		}
		if (num == 's'&&k == 2 || num == 'j'&&k == 0 || num == 'b'&&k == 1)
		{
			printf("电脑赢\n");
			count2++;
		}
	}
	printf("平局%d次  ", count);
	printf("玩家赢%d次  ", count1);
	printf("电脑赢%d次\n", count2);
	if (count1 == count2)
		printf("平局\n");
	if (count1 > count2)
		printf("玩家获胜\n");
	if (count1 < count2)
		printf("电脑获胜\n");
	printf("=======游戏结束======");
	return 0;
}
