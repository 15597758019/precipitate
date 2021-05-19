//实现一个函数，可以左旋串中的k个字符。
//例如：
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
//旋转字符串
//1.暴力求解法：
#include<stdio.h>
#include<string.h>
#include<assert.h>
void left_move(char arr[], int k)
{
	assert(arr != NULL);
	int i = 0;
	int len = strlen(arr);
	for (i = 0; i < k; i++)
	{
		//左旋转一个字符
		//1
		char tmp = *arr;
		//2
		int j = 0;
		for (j = 0; j < len-1; j++)
		{
			*(arr + j) = *(arr + j + 1);
		}
		//3
		*(arr + len - 1) = tmp;

	}
}
int main()
{
	char arr[] = "abcdef";
	left_move(arr, 2);
	printf("%s\n", arr);
	return 0;
}
