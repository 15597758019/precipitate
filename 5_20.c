//����3λ��������100-999���������Ӧ������Ҵ�д��
#include<stdio.h>
int main()
{
	int num, b3, b2, b1, i;
	char rmb[][3] = { "��", "Ҽ", "��", "��", "��", "��", "½", "��", "��", "��" };
	printf("��������λ��������-->\n");
	scanf("%d", &num);
	b3 = num / 100;
	b2 = num / 10 % 10;
	b1 = num % 10;
	printf("%s��", rmb[b3]);
	if (b2 == 0 && b1 != 0)
	{
		printf("%s%s", rmb[b2], rmb[b1]);
	}
	else if (b1 == 0 && b2 != 0)
		printf("%sʰ", rmb[b2]);
	else if (b1 != 0 && b2 != 0 && b3 != 0)
		printf("%sʰ%s", rmb[b2], rmb[b1]);
	printf("Բ����\n");
	return 0;
}
