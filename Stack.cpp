#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
//初始化
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
//释放
void StackDestory(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}
//入
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
//出
void StackPop(ST* ps)
{
	assert(ps);
	//减到栈空了直接终止程序报错。
	assert(ps->top > 0);
	ps->top--;
}
//取栈顶元素
STDataType StackTop(ST* ps)
{
	assert(ps);
	//栈为空，终止报错
	assert(ps->top > 0);
	return ps->a[ps->top - 1];
}
//元素个数
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}
//判栈空
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}