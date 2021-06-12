#include<stdio.h>
#include<assert.h>
int my_strcmp(const char* str1, const char* str2)
{
	assert(str1&&str2);
	//比较
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return 0;//相等
		}
		str1++;
		str2++;
	}
		return (*str1 - *str2);

}
int main()
{
	char* p1 = "abcdef";
	char* p2 = "abqwe";
	int ret = my_strcmp(p1, p2);
	printf("ret = %d\n", ret);
	return 0;
}
