int main()
{
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	printf("%d\n", sizeof(arr));//6
	printf("%d\n", sizeof(arr+0));//4/8 arr����Ԫ�ص�ַ��arr+0������Ԫ�صĵ�ַ����ַ�Ĵ�С��4/8���ֽ�
	printf("%d\n", sizeof(*arr));//1 arr����Ԫ�ص�ַ��*arr������Ԫ�أ���Ԫ�����ַ�����С��һ���ֽ�
	printf("%d\n", sizeof(arr[1]));//1
	printf("%d\n", sizeof(&arr));//4/8 &arr��Ȼ������ĵ�ַ�������ǵ�ַ����ַ��С��4/8���ֽ�
	printf("%d\n", sizeof(&arr + 1));//4/8 &arr ���������������ĵ�ַ����ַ��С��4/8���ֽ�
	printf("%d\n", sizeof(&arr[0] + 1));//��ַ����ַ��С4/8���ֽ�
	return 0;
}
