#include<stdio.h>
#include<assert.h>
#include<time.h>
char* my_strcpy(char* dest, const char*src)
{
	assert(dest != NULL);
	assert(src != NULL);
	char* ret = dest;
	//����srcָ����ַ�����destָ��Ŀռ䣬����'\0'
	while (*dest++=*src++)
	{
		;
	}
	//����Ŀ�Ŀռ����ʼλ��
	return ret;
}
int main()
{ 
	char arr1[] = "abcdefij";
	char arr2[] = "jw";

	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}
