#include<stdio.h>
#include<string.h>
int is_left_move(char* str1,char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2)
		return 0;
	strncat(str1, str1, 6);//abcdefabcdef-自己给自己追加字符串
	char* ret = strstr(str1, str2);//strstr - 找子串的
	if (ret == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
	char arr1[30] = "abcdef";
	char arr2[] = "cdefab";
	int ret = is_left_move(arr1, arr2);
	if (ret == 1)
	{
		
		printf("Yes\n");
	}
	else
	{

		printf("No\n");
	}
	return 0;
}
