#include<stdio.h>
#include<time.h>
#include<math.h>
#define m 20
#define N 10
int arr1[N];
void Rand_arr(int arr1[], int n);
void printf_f();
int count = 0;
int main()
{
	Rand_arr(arr1,N);
	printf_f();
	printf("产生重复 %d次",count);
	return 0;
}
void Rand_arr(int arr1[], int n)
{
	int arrayIndex[N * 2] = { 0 };
	
	int i = 0;
	srand(time(NULL));
	while (i < n){
		int q = rand() % m;
		if (arrayIndex[q] == 1){
			count++;
			continue;
		}
		arr1[i] = q;
		arrayIndex[q] = 1;
		i++;
	}
}
void printf_f()
{
	int i,j;
	for(i = 0;i < N;i++)
	{
		printf("%d ",arr1[i]);
	}
}

