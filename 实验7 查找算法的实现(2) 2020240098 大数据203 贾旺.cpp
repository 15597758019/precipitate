
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<random>
#define m 10000
#define K 5000
#define N 7500

int sz2[K];
int sz3[N];
int Ss(int n);
void LinearDetectionMethod(int n);
void Rand_arr(int sz2[], int n);
void SecondaryDetectionMethod(int n);

int main()
{
	int key = Ss(m);
	printf("����̽�ⷨ�ֱ����5000����7500����p�����ظ��������\n");
	LinearDetectionMethod(K);
	LinearDetectionMethod(N);
	LinearDetectionMethod(key);
	printf("\n�ֱ����������ɵ�5000�����ظ�����������ò�ͬ������\n");
	printf("����̽�ⷨ��\n");
	LinearDetectionMethod(K);
	printf("����̽�ⷨ��\n");
	SecondaryDetectionMethod(K);
	return 0;
}
int Ss(int n)
{
	int i, j;
	for (i = n; i > 0; i--)
	{
		for (j = 2; j*j < i; j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (j * j > i)
		{
			break;
		}
	}
	return i;
}

void Rand_arr(int sz2[], int n)
{
	int arrayIndex[m * 2] = { 0 };
	
	int i = 0;
	srand(time(NULL));
	while (i < n){
		int q = rand() % m;
		if (arrayIndex[q] == 1){
			continue;
		}
		sz2[i] = q;
		arrayIndex[q] = 1;
		i++;
	}
}

void LinearDetectionMethod(int n)
{
	int sz[m] = { 0 };
	Rand_arr(sz2, n);
	
	int a[m] = { 0 };
	int i, key, data;
	int count1 = 0;
	int count2 = 0;
	key = Ss(m);
	for (i = 0; i < n; i++)
	{
		data = sz2[i] % key;
		if (a[data] == -1)
		{
			count1++;//��ͻ
			while (sz[(data + 1) % m] != 0)
			{
				count2++;//�ۼ�
				data = data + 1;
			}
			sz[(data + 1) % m] = sz2[i];
		}
		else
			sz[data] = sz2[i];
		a[data] = -1;
		
	}
	printf("%d���� ��ͻ��%d , �ۼ���%d \n", n, count1, count2);
}
void SecondaryDetectionMethod(int n)
{
	int sz[m] = { 0 };
	Rand_arr(sz2, n);
	int a[m] = { 0 };
	int i, key, data;
	int e = 1;
	int count1 = 0;
	int count2 = 0;
	key = Ss(m);
	for (i = 0; i < n; i++)
	{
		int j = 0;
		data = sz2[i] % key;
		if (a[data] == -1)
		{
			count1++;//��ͻ
			while (e == 1)
			{
				int num = (int)pow(2, j);
				if (sz[(data + num) % key] != 0)
				{
					count2++;
					e = 1;
				}
				else
				{
					sz[(data + num) % key] = sz2[i];
					e = 0;
				}
				if (sz[(data - num) % key] != 0)
				{
					count2++;
					e = 1;
				}
				else
				{
					sz[(data - num) % key] = sz2[i];
					e = 0;
				}
				j = j + 1;
			}
			
		}
		else
			sz[data] = sz2[i];
		a[data] = -1;
	}
	printf("%d���� ��ͻ��%d , �ۼ���%d \n", n, count1, count2);
}
