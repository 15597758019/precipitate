#include<stdio.h> 
int main()
{
	int a[3][4], i, j, s = 0;
	char c;
	printf("���� ѧ�� ��ѧ�ɼ� Ӣ��ɼ� ����ɼ�\n");
	for (i = 0; i < 3; i++)
	for (j = 0; j <= 3; j++)
		scanf("%d", &a[i][j]);
	printf("ѧ�� ��ѧ Ӣ�� ���� �ܷ� ����\n");
	for (i = 0; i < 3; i++)
	{
		printf("%d", a[i][0]);  //���ѧ��
		for (s = 0, j = 1; j <= 3; j++)
		{
			s += a[i][j];    //�������ſγ��ܷ�
			printf("%6d", a[i][j]); //������ſγ̳ɼ�
		}
		if (s >= 270)
			c = 'Y';
		else
			c = 'N';
		printf("%6d%4c\n", s, c);//����ֺܷ������ж�
	}
	return 0;
}
