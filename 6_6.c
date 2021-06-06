#include<stdio.h>
int CalOdd(int n);
int CalEven(int n);
void Collatz(int z);
int main()
{
	int n;
	printf("��������Ȼ��n:");
	scanf("%d", &n);
	Collatz(n);
	return 0;
}
void Collatz(int n)
{
	int count = 0, n1, max;
	float Mul;
	n1 = n;
	max = n;
	while (n != 1)
	{
		count++;
		if (n % 2 == 1)
		{
			n = CalOdd(n);
			printf("%6d", n);
		}
		else if (n % 2 == 0)
		{
			n = CalEven(n);
			printf("%6d", n);
		}
		if (count % 8 == 0)
		{
			printf("\n");
		}
		if (n > max)
		{
			max = n;
		}
	}
	Mul = ((max - n1)*1.0) / n1 * 100;
	printf("\n\n %d ���� %d �κ��Ϊ %d \n", n1, count, n);
	printf("���ֵ�ﵽ %d �������� %.2f%%��\n", max, Mul);
}
int CalOdd(int n)
{
	return n * 3 + 1;
}
int CalEven(int n)
{
	return n / 2;
}
