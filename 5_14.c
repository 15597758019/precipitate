#include<math.h>
#include<stdio.h>
int main()
{
	int i = 0;
	for (i = 0; i <= 100000; i++)
	{
		//�ж�i�Ƿ�Ϊ������
		//1.����i��λ�� - nλ��
		int n = 1;
		int tmp = i;
		int sum = 0;
		while(tmp /= 10)
		{
			n++;
		}
		//2.����ÿһλ��n�η�֮�� sum
		tmp = i;
		while (tmp)
		{
			sum += pow(tmp % 10, n);
			tmp /= 10;
		}
		//3.�Ƚ�i==sum
		if (i == sum)
		{
			printf("%d ", i);
		}
	}
	return 0;
}
