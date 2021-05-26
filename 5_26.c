#include<stdio.h>
#include<time.h>
#include<assert.h>
char* my_strcat(char*dest,const char*src)
{
	char* ret = dest;
	assert(dest&&src);
	//1.找到目的字符串的'\0'
	while (*dest!='\0')
	{
		dest++;
	}
	//2.追加
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	char arr1[30] = "hello ";
	char arr2[] = "world";
	my_strcat(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}
