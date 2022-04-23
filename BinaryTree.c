#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;

//前序
//void PrevOrder(BTNode* root)
//{
//	if (root == NULL)
//	{
//		printf("NULL ");
//		return;
//	}
//		
//	printf("%c ", root->data);
//	PrevOrder(root->left);
//	PrevOrder(root->right);
//
//}
//静态
int size = 0;
void TreeSize1(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		size++;
	}
	TreeSize1(root->left);
	TreeSize1(root->right);
}
//可并发，多线程
void TreeSize2(BTNode* root,int* psize)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		(*psize)++;
	}
	TreeSize2(root->left,psize);
	TreeSize2(root->right,psize);
}
//分治
int TreeSize3(BTNode* root)
{
	return root == NULL ? 0 : TreeSize3(root->left) + TreeSize3(root->right) + 1;
}
int main()
{
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	A->data = 'A';
	A->left = NULL;
	A->right = NULL;

	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	B->data = 'B';
	B->left = NULL;
	B->right = NULL;

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->data = 'C';
	C->left = NULL;
	C->right = NULL;

	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->data = 'D';
	D->left = NULL;
	D->right = NULL;

	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->data = 'E';
	E->left = NULL;
	E->right = NULL;

	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;
	//PrevOrder(A);
	//printf("\n");

	TreeSize1(A);
	printf("TreeSize1:%d\n", size);
	size = 0;
	TreeSize1(B);
	printf("TreeSize1:%d\n", size);

	int Asize = 0;
	TreeSize2(A,&Asize);
	printf("TreeSize2:%d\n", Asize);

	int Bsize = 0;
	TreeSize2(B,&Bsize);
	printf("TreeSize2:%d\n", Bsize);

	printf("TreeSize3:%d\n", TreeSize3(A));
	printf("TreeSize3:%d\n", TreeSize3(B));

	return 0;
}