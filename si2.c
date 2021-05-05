int main()
{
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	printf("%d\n", sizeof(arr));//6
	printf("%d\n", sizeof(arr+0));//4/8 arr是首元素地址，arr+0还是首元素的地址，地址的大小是4/8个字节
	printf("%d\n", sizeof(*arr));//1 arr是首元素地址，*arr就是首元素，首元素是字符，大小是一个字节
	printf("%d\n", sizeof(arr[1]));//1
	printf("%d\n", sizeof(&arr));//4/8 &arr虽然是数组的地址，但还是地址，地址大小是4/8个字节
	printf("%d\n", sizeof(&arr + 1));//4/8 &arr 是跳过整个数组后的地址，地址大小是4/8个字节
	printf("%d\n", sizeof(&arr[0] + 1));//地址，地址大小4/8个字节
	return 0;
}
