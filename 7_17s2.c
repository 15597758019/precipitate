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
		//��ǰ��󿽱�
		while (count--)
		{
			*(char*)dest = *(char*)src;
			(char*)dest++;
			(char*)src++;
		}

	}
	else
	{
		//�Ӻ���ǰ����
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
	my_memmove(arr + 2, arr, 20);//memcpy - �����ص�������memmove - �����ڴ��ص������
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
