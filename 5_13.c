#include<stdio.h> 
#include<string.H>
void reverse(char* str)
{
	int len = strlen(str);
	char* left = str;
	char* right = str + len - 1;
	while (left<right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
int main()
{
	char arr[256] = { 0 };
	//scanf("%s", arr);
	gets(arr);

	//ÄæÐòº¯Êý
	reverse(arr);
	printf("ÄæÐòºóµÄ×Ö·û´®£º%s\n", arr);
	return 0;
}
