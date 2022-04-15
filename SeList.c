
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef int SQDataType;
//��̬˳���
//���⣺�����˲����ã��������ò��꣬�������Ӧ��
typedef struct SeqList
{
	SQDataType* a;
	int size;		//��Ч���ݸ���
	int capacity;//����
}SL;
//���ٿռ�
void SeqListDestory(SL* ps);

void SeqListInit(SL* ps);
void SeqListCheckCapacity(SL* ps);

void SeqListPrint(SL* ps);

//ͷ�� β�� ͷɾ βɾ
void SeqListPushBack(SL* ps, SQDataType x);
void SeqListPushFront(SL* ps, SQDataType x);
void SeqListPopBack(SL* ps);
void SeqListPopFront(SL* ps);
//������룬���ɾ��
void SeqListInsert(SL* ps, int pos,SQDataType x);
void SeqListErase(SL* ps, int pos);

//���
int SeqListFind(SL* ps, SQDataType x);
void SeqListModity(SL* ps, int pos, SQDataType x);

void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListDestory(SL* ps){
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

void SeqListCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SQDataType* tmp = (SQDataType*)realloc(ps->a, newcapacity * sizeof(SQDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			ps->a = tmp;
			ps->capacity = newcapacity;
		}
	}
	
}
//β��
void SeqListPushBack(SL* ps, SQDataType x)
{
	SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

//ͷ��
void SeqListPushFront(SL* ps, SQDataType x)
{
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;
	ps->size++;
}
//βɾ
void SeqListPopBack(SL* ps)
{
	ps->size--;
}
//ͷɾ
void SeqListPopFront(SL* ps)
{
	
	int start = 1;
	while (start < ps->size)
	{
		ps->a[start - 1] = ps->a[start];
		++start;
	}
	ps->size--;
}
void SeqListInsert(SL* ps, int pos, SQDataType x)
{
	
	SeqListCheckCapacity(ps);
	
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[pos] = x;
	ps->size++;
}

void SeqListErase(SL* ps, int pos)
{
	int start = pos + 1;
	while (start < ps->size)
	{
		ps->a[start - 1] = ps->a[start];
		++start;
	}
	ps->size--;
	
}
//��
int SeqListFind(SL* ps, SQDataType x)
{
	for (int i = 0; i < ps->size; ++i)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
}
//��
void SeqListModity(SL* ps, int pos, SQDataType x)
{
	ps->a[pos] = x;
}

void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}


void TestSeqList1()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 6);
	SeqListPushBack(&sl, 7);
	SeqListPushBack(&sl, 8);
	SeqListPushBack(&sl, 9);
	SeqListPushBack(&sl, 10);
	SeqListPushBack(&sl, 11);
	
	SeqListPrint(&sl);
	SeqListDestory(&sl);
	
}
void TestSeqList2()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 5);
	SeqListPushFront(&sl, 6);
	SeqListPushFront(&sl, 7);
	SeqListPushFront(&sl, 8);
	SeqListPushFront(&sl, 9);
	SeqListPushFront(&sl, 10);
	SeqListPushFront(&sl, 11);
	SeqListPrint(&sl);
	
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPrint(&sl);
	
	SeqListPopFront(&sl);
	SeqListPrint(&sl);
	SeqListDestory(&sl);
	
	
}
void TestSeqList3()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 5);
	SeqListPrint(&sl);
	
	
	//���±�Ϊ1��λ�ò���20
	SeqListInsert(&sl, 1, 20);
	SeqListPrint(&sl);
	
	SeqListErase(&sl, 1);
	SeqListPrint(&sl);
	
	SeqListDestory(&sl);
	
	
	
}
void menu()
{
	printf("**********************************************************\n");
	printf("1.β�����ݣ� 2.ͷ������\n");
	printf("3.βɾ��     4.ͷɾ\n");
	printf("5.��ӡ��     6.�˳�\n");
	printf("���������ѡ�");
	printf("**********************************************************\n");
}

int main()
{
	//TestSeqList1();
	//TestSeqList2();
	//TestSeqList3();
	SL s;
	SeqListInit(&s);
	int option = 0;
	int x = 0;
	while (option != -1)
	{
		menu();
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			printf("��������Ҫ��������ݣ���-1����\n");
			do{
				scanf("%d", &x);
				if (x != -1)
				{
					SeqListPushBack(&s, x);
				}
			} while (x != -1);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			SeqListPrint(&s);
			break;
			default:
				break;
				
		}
	}
	
	return 0;
}
