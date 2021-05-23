//输入某年某月，输出该月月历
#include<stdio.h>
int main()
{
	int i, j, year, month, daysfrom111, week, day;
	int day1 = 1;
	int moondays[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	char weekcn[][3] = { "", "一", "二", "三", "四", "五", "六", "日" };
	int calendar[6][7] = { 0 };
	printf("输入年月历年月（如：1900 1）:");
	scanf("%d%d", &year, &month);
	printf("======== %d%年%d月 ========\n", year, month);
	printf("---------------------------\n");
	daysfrom111 = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
	for (i = 1; i < month; i++)
		daysfrom111 += moondays[i];
	daysfrom111 += 1;
	if (month>2 && ((year % 4 == 0) && year % 100 != 0 || year % 400 == 0))
		daysfrom111++;
	week = daysfrom111 % 7;
	week = week == 0 ? 7 : week;
	day = moondays[month];
	for (i = 0; i < 6; i++)
	{
		for (j =0; j < 7; j++)
		{
			if (i==0&&j < week-1)
			{
				printf("    ");
			}
			else
			{
				if (day1 <= day)
				{
				calendar[i][j] = day1++;
				printf("%3d ", calendar[i][j]);
				}
				else
					break;
			}
		}
		printf("\n");
	}
	return 0;
}
