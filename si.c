int main()
{
	//数组名是首元素地址
	//1.sizeof(数组名) - 数组名表示整个数组
	//2.&数组名 - 数组名表示整个数组
	int a[] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(a));//16
	printf("%d\n", sizeof(a+0));//4/8 - 数组名表示首元素地址，a+0还是首元素地址，地址的大小还是4/8个字节
	printf("%d\n", sizeof(*a));//4 - 数组名表示首元素地址，*a就是首元素，sizeof(*a)就是4
	printf("%d\n", sizeof(a+1));//4/8 - 数组名这里表示首元素的值，a+1 是第二个元素的地址，地址的大小就是4/8个字节
	printf("%d\n", sizeof(a[1]));//4 - 第二个元素的大小
	printf("%d\n", sizeof(&a));//4/8 - &a取出的是数组的地址，但是数组的地址那也是地址，地址的大小那也是4/8个字节
	printf("%d\n", sizeof(*&a));//16 - &a是数组的地址，数组的地址解引用访问的是数组，sizeof计算的是数组的大小，单位是字节
	printf("%d\n", sizeof(&a+1));//4/8 - &a是数组的地址，&a+1虽然地址跳过整个数组，还是地址
	printf("%d\n", sizeof(&a[0]));//4/8
	printf("%d\n", sizeof(&a[0]+1));//4/8
	return 0;
}
