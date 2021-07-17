#include<string.h> 
#include<assert.h>
#include<stdio.h>
void* my_memmove(void* dest,const void* src,size_t count)
{
	void* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	if (dest < src)
	{
		//从前向后拷贝
		while (count--)
		{
			*(char*)dest = *(char*)src;
			(char*)dest++;
			(char*)src++;
		}

	}
	else
	{
		//从后向前拷贝
		while (count--)
		{
			*((char*)dest + count)=*((char*)src+count);

		}
	}
	return ret;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int i = 0;
	my_memmove(arr + 2, arr, 20);//memcpy - 不能重叠拷贝；memmove - 处理内存重叠情况的
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

