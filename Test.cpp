
#include"Stack.h"
int main()
{

	ST st;
	StackInit(&st);

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);

	printf("%d ", StackTop(&st));
	StackPop(&st);//出

	StackPush(&st, 4);
	StackPush(&st, 5);
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");
	StackDestory(&st);
	//StackPush(&st, 1);
	//StackPush(&st, 3);
	//StackPush(&st, 5);
	//StackPush(&st, 11);

	//while (!StackEmpty(&st))
	//{
	//	printf("%d ", StackTop(&st));
	//	StackPop(&st);
	//}

	return 0;
}







	//int option = 0;
	//int x = 0;
	//int count = 0;
	//while (option != -1)
	//{
	//	menu();
	//	scanf("%d", &option);
	//	char arr[10][10] = { 0 };
	//	for (int i = 0; i < 10; i++)
	//	{
	//		for (int j = 0; j < 10; j++)
	//		{
	//			if (j == 3 || j == 7)
	//			{
	//				arr[i][j] = '|';
	//			}
	//			else
	//				arr[i][j] = ' ';
	//			if (j == 4 || j == 5 || j == 6)
	//			{
	//				arr[i][j] = '_';
	//			}
	//		}
	//	}
	//	for (int i = 0; i < 10; i++)
	//	{
	//		for (int j = 0; j < 10; j++)
	//		{
	//			printf("%c", arr[i][j]);
	//		}
	//		printf("\n");
	//	}
	//	switch (option)
	//	{
	//	case 1:
	//		printf("请输入入栈的数字,-1结束输入：\n");
	//		while (x != -1)
	//		{
	//			
	//		scanf("%d",&x);
	//		if (x != -1){
	//			StackPush(&st, x);
	//			for (int i = 0; i < 10; i++)
	//			{
	//				for (int j = 0; j < 10; j++)
	//				{
	//					if (i == 9 - count&&j == 5)
	//					{
	//						arr[i][j] = StackTop(&st);
	//						printf("%d", arr[i][j]);
	//					}
	//					else
	//						printf("%c", arr[i][j]);
	//				}
	//				printf("\n");
	//			}
	//				count++;
	//			
	//		}
	//		else
	//			break;
	//		}
	//	}
	//}
//	return 0;
//}