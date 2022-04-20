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

//Ç°Ðò
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
