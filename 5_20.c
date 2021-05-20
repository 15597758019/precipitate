//输入3位正整数（100-999），输出对应的人民币大写。
#include<stdio.h>
int main()
{
	int num, b3, b2, b1, i;
	char rmb[][3] = { "零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖" };
	printf("请输入三位正整数：-->\n");
	scanf("%d", &num);
	b3 = num / 100;
	b2 = num / 10 % 10;
	b1 = num % 10;
	printf("%s佰", rmb[b3]);
	if (b2 == 0 && b1 != 0)
	{
		printf("%s%s", rmb[b2], rmb[b1]);
	}
	else if (b1 == 0 && b2 != 0)
		printf("%s拾", rmb[b2]);
	else if (b1 != 0 && b2 != 0 && b3 != 0)
		printf("%s拾%s", rmb[b2], rmb[b1]);
	printf("圆整。\n");
	return 0;
}
