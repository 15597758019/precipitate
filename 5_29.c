//n��Ƕ��ƽ��������
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double y(float x, int n);
int main()
{
	float x;
	int n;
	printf("������x��n:");
	scanf("%f%d", &x,&n);
	printf("y(x)=%.4lf\n", y(x, n));
	return 0;
}
double y(float x, int n)
{
	if (n == 0)
		return 0;
	else
		return (sqrt(x + y(x, n - 1)));
}
