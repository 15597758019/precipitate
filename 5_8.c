#include<stdio.h>
int main()
{
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));//48
	printf("%d\n", sizeof(a[0][0]));//4
	printf("%d\n", sizeof(a[0]));//16  a[0]�൱�ڵ�һ����Ϊһά�������������
	         //sizeof(a[0])����������������sizeof()�ڣ�������ǵ�һ�еĴ�С
	printf("%d\n", sizeof(a[0]+1));//4/8  ��Ԫ�ص�ַ+1���ڶ���Ԫ�ص�ַ
	printf("%d\n", sizeof(*(a[0]+1)));//4  ��һ�еڶ���Ԫ�أ���С��4
	printf("%d\n", sizeof(a+1));  //4/8  a�Ƕ�ά�������������û��sizeof(������)��Ҳû��&(������)������a����Ԫ�ص�ַ
	        //���Ѷ�ά���鿴��һά����ʱ����ά�������Ԫ�ص�ַ�����ĵ�һ�У�a���ǵ�һ��(��Ԫ��)�ĵ�ַ a+1���ǵڶ��еĵ�ַ
	printf("%d\n", sizeof(*(a+1)));//16  sizeof(a[1]),�ڶ��еĴ�С
	printf("%d\n", sizeof(&a[0]+1));//4/8  �ڶ��еĵ�ַ
	printf("%d\n", sizeof(*(&a[0]+1)));//16 ����ڶ��еĴ�С
	printf("%d\n", sizeof(*a));//16 a����Ԫ�ص�ַ����һ�еĵ�ַ��*a���ǵ�һ�У�sizeof(*a)���Ǽ����һ�еĴ�С
	printf("%d\n", sizeof(a[3]));//16 
	return 0;
}