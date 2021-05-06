#include<stdio.h> 
int main()
{
	int i,n;
	int a[] = {25,21,57,34,12,9,4,44};
	printf("请输入查找的数：");
	scanf("%d",&n);
	for(i = 0;i<8;i++)
	if(a[i]==n)
	{
		printf("%d是a数组的第%d个数字\n",n,i+1);
		break;
	 } 
	 if(n!=a[i])
	 printf("查无此数！\n");
	return 0;
 } 
