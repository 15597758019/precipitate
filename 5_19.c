//ʵ��һ�������������������е�k���ַ���
//���磺
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
//��ת�ַ���
//1.������ⷨ��
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
		//����תһ���ַ�
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
