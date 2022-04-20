#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;

//前序
void PreOrder(BTNode* root)
{
	if(root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ",root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}
//中序
void InfixOrder (BTNode* root)
{
	if(root == NULL)
	{
		printf("NULL ");
		return;
	}
	PreOrder(root->left);
	printf("%c ",root->data);
	PreOrder(root->right);
}
//后序
void PostOrder(BTNode* root)
{
	if(root == NULL)
	{
		printf("NULL ");
		return;
	}
	PreOrder(root->left);
	PreOrder(root->right);
	printf("%c ",root->data);
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
	PreOrder(A);
	printf("\n");
	
	return 0;
}
