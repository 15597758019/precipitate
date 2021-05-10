#include<stdio.h> 
void main(void)
{
	long int f1, f2;
	int i;
	f1 = 1; f2 = 1;
	for (i = 1; i <= 20; i++)
	{
		printf("%-12Ld%-12Ld", f1, f2);
		if (i % 2 == 0)printf("\n");
		f1 = f1 + f2; f2 = f2 + f1;
	}
}

