#include<stdio.h> 
int main()
{
	char input[20] = { 0 };
	system("shutdown -s -t 60");
	while (1)
	{
		printf("请注意，你的电脑将在1分钟内关机，如果输入:帅哥，就取消关机\n请输入>:");
		scanf("%s", input);
		if (strcmp(input, "帅哥") == 0)//比较两个字符串 - strcmp()
		{
			system("shutdown -a");
			break;
		}
	}
	return 0;
}
