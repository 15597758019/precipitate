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
	printf("======��ӭ���� ʯͷ ���� ��======\n");
	for (i = 1; i <= 5; i++)
	{
		printf("��%d�֣�", i);
		printf("�����ʲô��ʯͷ ���� ����-->");
		num = getche();
		switch (num)
		{
		case 's':printf("ʯͷ"); break;
		case 'j':printf("����"); break;
		case 'b':printf("��"); break;
		}
		printf(" ");
		printf("���Գ�����:-->");
		k = rand() % 3;
		switch (k)
		{
		case 0:printf("ʯͷ"); break;
		case 1:printf("����"); break;
		case 2:printf("��"); break;
		}
		printf("--");
		if (num == 's'&&k == 0 || num == 'j'&&k == 1 || num == 'b'&&k == 2)
		{
			printf("ƽ��\n");
			count++;
		}
		if (num == 's'&&k == 1 || num == 'j'&&k == 2 || num == 'b'&&k == 0)
		{
			printf("���Ӯ\n");
			count1++;
		}
		if (num == 's'&&k == 2 || num == 'j'&&k == 0 || num == 'b'&&k == 1)
		{
			printf("����Ӯ\n");
			count2++;
		}
	}
	printf("ƽ��%d��  ", count);
	printf("���Ӯ%d��  ", count1);
	printf("����Ӯ%d��\n", count2);
	if (count1 == count2)
		printf("ƽ��\n");
	if (count1 > count2)
		printf("��һ�ʤ\n");
	if (count1 < count2)
		printf("���Ի�ʤ\n");
	printf("=======��Ϸ����======");
	return 0;
}
