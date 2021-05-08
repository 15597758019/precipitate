#include<stdio.h>
int main()
{
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));//48
	printf("%d\n", sizeof(a[0][0]));//4
	printf("%d\n", sizeof(a[0]));//16  a[0]相当于第一行作为一维数组的数组名，
	         //sizeof(a[0])把数组名单独放在sizeof()内，计算的是第一行的大小
	printf("%d\n", sizeof(a[0]+1));//4/8  首元素地址+1，第二个元素地址
	printf("%d\n", sizeof(*(a[0]+1)));//4  第一行第二个元素，大小是4
	printf("%d\n", sizeof(a+1));  //4/8  a是二维数组的数组名，没有sizeof(数组名)，也没有&(数组名)，所以a是首元素地址
	        //而把二维数组看成一维数组时，二维数组的首元素地址是它的第一行，a就是第一行(首元素)的地址 a+1就是第二行的地址
	printf("%d\n", sizeof(*(a+1)));//16  sizeof(a[1]),第二行的大小
	printf("%d\n", sizeof(&a[0]+1));//4/8  第二行的地址
	printf("%d\n", sizeof(*(&a[0]+1)));//16 计算第二行的大小
	printf("%d\n", sizeof(*a));//16 a是首元素地址，第一行的地址，*a就是第一行，sizeof(*a)就是计算第一行的大小
	printf("%d\n", sizeof(a[3]));//16 
	return 0;
}
