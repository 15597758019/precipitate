#include<stdio.h> 
int main()
{
	int i,n;
	int a[] = {25,21,57,34,12,9,4,44};
	printf("��������ҵ�����");
	scanf("%d",&n);
	for(i = 0;i<8;i++)
	if(a[i]==n)
	{
		printf("%d��a����ĵ�%d������\n",n,i+1);
		break;
	 } 
	 if(n!=a[i])
	 printf("���޴�����\n");
	return 0;
 } 
