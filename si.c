int main()
{
	//����������Ԫ�ص�ַ
	//1.sizeof(������) - ��������ʾ��������
	//2.&������ - ��������ʾ��������
	int a[] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(a));//16
	printf("%d\n", sizeof(a+0));//4/8 - ��������ʾ��Ԫ�ص�ַ��a+0������Ԫ�ص�ַ����ַ�Ĵ�С����4/8���ֽ�
	printf("%d\n", sizeof(*a));//4 - ��������ʾ��Ԫ�ص�ַ��*a������Ԫ�أ�sizeof(*a)����4
	printf("%d\n", sizeof(a+1));//4/8 - �����������ʾ��Ԫ�ص�ֵ��a+1 �ǵڶ���Ԫ�صĵ�ַ����ַ�Ĵ�С����4/8���ֽ�
	printf("%d\n", sizeof(a[1]));//4 - �ڶ���Ԫ�صĴ�С
	printf("%d\n", sizeof(&a));//4/8 - &aȡ����������ĵ�ַ����������ĵ�ַ��Ҳ�ǵ�ַ����ַ�Ĵ�С��Ҳ��4/8���ֽ�
	printf("%d\n", sizeof(*&a));//16 - &a������ĵ�ַ������ĵ�ַ�����÷��ʵ������飬sizeof�����������Ĵ�С����λ���ֽ�
	printf("%d\n", sizeof(&a+1));//4/8 - &a������ĵ�ַ��&a+1��Ȼ��ַ�����������飬���ǵ�ַ
	printf("%d\n", sizeof(&a[0]));//4/8
	printf("%d\n", sizeof(&a[0]+1));//4/8
	return 0;
}