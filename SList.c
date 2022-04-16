
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
//尾插
void SListPushBack(SLTNode** pphead, SLTDataType x);
//头插
void SListPushFront(SLTNode** phead, SLTDataType x);
//头删
void SListPopFront(SLTNode** phead);
//尾删
void SListPopBack(SLTNode** phead);

SLTNode* SListFind(SLTNode* phead,SLTDataType x);
//在pos的前面插入x
void SListInsert(SLTNode** phead, SLTNode* pos,SLTDataType x);
//删除pos位置的值
void SListErase(SLTNode** phead,SLTNode* pos);

//打印
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
//创建空间、初始化
SLTNode* BuySListNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
//尾插
void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	
	SLTNode* newnode = BuySListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//找尾节点的指针
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		//尾节点，链接新节点
		tail->next = newnode;
	}
}
//头插
void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
	
}
//头删
void SListPopFront(SLTNode** pphead)
{
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}
//尾删
void SListPopBack(SLTNode** pphead)
{
	//1.空
	//2.一个节点
	//3.一个以上的节点
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
//查找
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
//在pos的前面插入x
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

//删除pos位置的值
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
	//在3的前面插入一个30
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
