#include <stdio.h>
int Add(int x, int y)
{
	int z = x + y;
	return z;
}
int main()
{
	int num1 = 10;
	int num2 = 20;
	int sum = 0;
	int a = 100;
	int b = 200;
	//sum = num1 + num2;
	sum = Add(num1, num2);
	//sum = a + b;
	sum = Add(a, b);
	printf("sum = %d\n", sum);

	return 0;
}
