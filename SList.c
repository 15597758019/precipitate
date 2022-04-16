
#include<stdio.h>
#include<stdlib.h>

typedef int SLTDataType;
struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
};

typedef struct SListNode SLTNode;

void SListPrint(SLTNode* phead);
//β��
void SListPushBack(SLTNode** pphead, SLTDataType x);
//ͷ��
void SListPushFront(SLTNode** phead, SLTDataType x);
//ͷɾ
void SListPopFront(SLTNode** phead);
//βɾ
void SListPopBack(SLTNode** phead);

SLTNode* SListFind(SLTNode* phead,SLTDataType x);
//��pos��ǰ�����x
void SListInsert(SLTNode** phead, SLTNode* pos,SLTDataType x);
//ɾ��posλ�õ�ֵ
void SListErase(SLTNode** phead,SLTNode* pos);

//��ӡ
void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
//�����ռ䡢��ʼ��
SLTNode* BuySListNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
//β��
void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	
	SLTNode* newnode = BuySListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//��β�ڵ��ָ��
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		//β�ڵ㣬�����½ڵ�
		tail->next = newnode;
	}
}
//ͷ��
void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
	
}
//ͷɾ
void SListPopFront(SLTNode** pphead)
{
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}
//βɾ
void SListPopBack(SLTNode** pphead)
{
	//1.��
	//2.һ���ڵ�
	//3.һ�����ϵĽڵ�
	if (*pphead == NULL)
	{
		return;
	}
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}
//����
SLTNode* SListFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
	//while (cur != NULL)
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
//��pos��ǰ�����x
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	if (pos == *pphead)
	{
		SListPushFront(pphead, x);
	}
	else
	{
		SLTNode* newnode = BuySListNode(x);
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = newnode;
		newnode->next = pos;
	}
}

//ɾ��posλ�õ�ֵ
void SListErase(SLTNode** pphead, SLTNode* pos)
{
	if (pos == *pphead)
	{
		SListPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}
}
void TestSList1()
{
	SLTNode** plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushFront(&plist,0);
	SListPrint(plist);
	
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(plist);
	
	SListPopFront(&plist);
	SListPrint(plist);
	
}

void TestSList2()
{
	SLTNode** plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	
	SListPrint(plist);
	
}
void TestSList3()
{
	SLTNode** plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	//��3��ǰ�����һ��30
	SLTNode* pos = SListFind(plist, 3);
	if (pos)
	{
		SListInsert(&plist, pos, 30);
	}
	SListPrint(plist);
	
	pos = SListFind(plist, 1);
	if (pos)
	{
		SListInsert(&plist, pos, 10);
	}
	
	SListPrint(plist);
	
}

void TestSList4()
{
	SLTNode** plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);
	SLTNode* pos = SListFind(plist, 1);
	if (pos)
	{
		SListErase(&plist, pos);
	}
	SListPrint(plist);
	pos = SListFind(plist, 4);
	if (pos)
	{
		SListErase(&plist, pos);
	}
	SListPrint(plist);
	
}

int main()
{
	TestSList1();
	printf("*************\n");
	TestSList2();
	printf("*************\n");
	TestSList3();
	printf("*************\n");
	TestSList4();
	return 0;
}
