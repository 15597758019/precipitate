#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int i, id, j = 0, num[5], num2[10], minID, tmp, count = 0;
	srand(time(NULL));
	printf("��ʼ�������У�");
	for (i = 0; i < 10; i++)
	{
		num2[i] = 1 + i;
	}
	for (i = 0; i < 5; i++)
	{
		while (num2[id = rand() % 10] == -1)//���ʹ�ù��Ŀ�λ
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
				minID = j;//�Ƚϣ�����С�ĺ͵�һ������
		tmp = num[i];
		num[i] = num[minID];
		num[minID] = tmp;
		Sleep(500);
		printf("\n��%2d�������", i + 1);
		for (j = 0; j < 5; j++)
		{
			Sleep(500);
			printf("%4d", num[j]);
		}

	}
	printf("\n����������������ظ�����%d\n", count);
	return 0;
}
