#include<stdio.h>
int main()
{
	int a[9][9], i, j;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (i == j || j == 0)
			{
				a[i][j] = 1;
			}
			else
			{
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			}
		}
	}
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%-5d", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}

