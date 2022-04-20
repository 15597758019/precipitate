#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
//��ʼ��
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = (STDataType*)malloc(sizeof(STDataType)* 4);
	if (ps->a == NULL)
	{
		printf("realloc fail\n");
		exit(-1);
	}
	ps->capacity = 4;
	ps->top = 0;
}
//�ͷ�
void StackDestory(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}
//��
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(ps->a, ps->capacity * 2 * sizeof(STDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			ps->a = tmp;
			ps->capacity *= 2;
		}
	}
	ps->a[ps->top] = x;
	ps->top++;
}
//��
void StackPop(ST* ps)
{
	assert(ps);
	//����ջ����ֱ����ֹ���򱨴���
	assert(ps->top > 0);
	ps->top--;
}
//ȡջ��Ԫ��
STDataType StackTop(ST* ps)
{
	assert(ps);
	//ջΪ�գ���ֹ����
	assert(ps->top > 0);
	return ps->a[ps->top - 1];
}
//Ԫ�ظ���
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}
//��ջ��
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}