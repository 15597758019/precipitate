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
	printf("�������a�����ɣ�������һ��������%d-%d����", MIN, MAX);
	scanf("%d", &num);
	print_list(a, LEN);
	pos = find_in_list(a, LEN, num);
	if (pos < 0)printf("����a��û��%d�������\n",num);
	else printf("%d������a�����ڵ�%dλ��\n", a[pos], pos + 1);
	return 0;
}
void print_list(int *list, int len)
{
	int i, *p1;
	for (i = 0; i < len; i++)
		printf("a[%d] ", i);
	printf("\n");
	for (p1 = list, i = 0; i < len; i++, p1++)
		printf("%3d  ", *p1);//ͨ��ָ���������Ԫ��
	printf("\n");

}
void gen_rand_list(int *list, int len, int min, int max)
{
	//����len��[min,max]֮��Ĳ��ظ����������list��ָ���һά����
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
	//��listָ���һά���飨��len�����ظ���������в���num
	//���ҵ��򷵻�num�ڸ������е���Ȼλ�ã����򷵻�-1
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
