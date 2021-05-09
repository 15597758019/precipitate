#include<stdio.h> 
int main()
{
	int a[3][4], i, j, s = 0;
	char c;
	printf("输入 学号 数学成绩 英语成绩 物理成绩\n");
	for (i = 0; i < 3; i++)
	for (j = 0; j <= 3; j++)
		scanf("%d", &a[i][j]);
	printf("学号 数学 英语 物理 总分 优秀\n");
	for (i = 0; i < 3; i++)
	{
		printf("%d", a[i][0]);  //输出学号
		for (s = 0, j = 1; j <= 3; j++)
		{
			s += a[i][j];    //计算三门课程总分
			printf("%6d", a[i][j]); //输出三门课程成绩
		}
		if (s >= 270)
			c = 'Y';
		else
			c = 'N';
		printf("%6d%4c\n", s, c);//输出总分和优秀判定
	}
	return 0;
}
