#include<stdio.h> 
int main()
{
	char input[20] = { 0 };
	system("shutdown -s -t 60");
	while (1)
	{
		printf("��ע�⣬��ĵ��Խ���1�����ڹػ����������:˧�磬��ȡ���ػ�\n������>:");
		scanf("%s", input);
		if (strcmp(input, "˧��") == 0)//�Ƚ������ַ��� - strcmp()
		{
			system("shutdown -a");
			break;
		}
	}
	return 0;
}
