#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define LEN 10
#define MIN 10
#define MAX 19
void print_list(int *list, int len);
void gen_rand_list(int *list, int len, int min, int max);
int find_in_list(int *list, int len, int num);
int main()
{
	int a[LEN] = { 0 }, num, pos;
	srand(time(0));
	gen_rand_list(a, LEN, MIN, MAX);
	printf("随机数组a已生成，请输入一个整数（%d-%d）：", MIN, MAX);
	scanf("%d", &num);
	print_list(a, LEN);
	pos = find_in_list(a, LEN, num);
	if (pos < 0)printf("数组a中没有%d这个数。\n",num);
	else printf("%d在数组a中排在第%d位。\n", a[pos], pos + 1);
	return 0;
}
void print_list(int *list, int len)
{
	int i, *p1;
	for (i = 0; i < len; i++)
		printf("a[%d] ", i);
	printf("\n");
	for (p1 = list, i = 0; i < len; i++, p1++)
		printf("%3d  ", *p1);//通过指针访问数组元素
	printf("\n");

}
void gen_rand_list(int *list, int len, int min, int max)
{
	//生成len个[min,max]之间的不重复随机数放入list所指向的一维数组
	int i, b[MAX+1],id,j=0;
	for (i = min; i <=max; i++)
	{
		b[i] = min+j;
		j++;

	}
	printf("\n");
	j = 0;
	for (i = 0; i < len; i++)
	{
		while (b[id = rand() % (max + 1 - min) + min] == -1)
		{
			;
		}
		list[j++] = b[id];
		b[id] = -1;
	}

}
int find_in_list(int *list, int len, int num)
{
	//在list指向的一维数组（有len个不重复随机数）中查找num
	//若找到则返回num在该数组中的自然位置，否则返回-1
	int i;
	for (i = 0; i < len; i++)
	{
		if (list[i] == num)
		{
			return (i);
			break;
		}
	}
	if (i == len)
	return -1;
}
