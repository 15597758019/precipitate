//2.Èı²½·­×ª·¨£º
//abcdef
//bafedc//×ó±ßÄæĞò£¬ÓÒ±ßÄæĞò
//cdefab//ÔÙÕûÌåÄæĞò

//ÄæĞò×Ö·û´®º¯Êı
#include<assert.h>
#include<string.h>
void reverse(char *left, char* right)
{
	assert(left != NULL);
	assert(right != NULL);
	while (left<right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}

}
void left_move(char* arr, int k)
{
	assert(arr);
	int len = strlen(arr);
	assert(k <= len);
	reverse(arr, arr + k - 1);//ÄæĞò×ó±ß
	reverse(arr+k, arr + len-1);//ÄæĞòÓÒ±ß
	reverse(arr, arr + len - 1);//ÄæĞòÕûÌå±ß

}
int main()
{
	char arr[] = "abcdef";
	left_move(arr, 2);
	printf("%s\n", arr);
	return 0;
}
