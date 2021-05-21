//判断某年某月是周几（基准点：公元1年1月1日是周一）
#include<stdio.h>
int main()
{
	int i, j, year, month, day, daysfrom111, week, leap = 0;
	int moondays[] = { 0, 31, 28, 31, 30,31,30,31,31,30,31,30,31 };
	char weekcn[][3] = {"", "一", "二", "三", "四", "五", "六", "日" };
	printf("请输入年月日（如：2021 5 21）：");
	scanf("%d%d%d", &year, &month, &day);
	daysfrom111 = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
	for (i = 1; i < month; i++)
		daysfrom111 += moondays[i];
	daysfrom111 += day;
	if (month>2 && ((year % 4 == 0) && year % 100 != 0 || year % 400 == 0))
		daysfrom111++;
	week = daysfrom111 % 7;
	week = week == 0 ? 7 : week;
	printf("%d年%d月%d日距公元1年1月1日%d天，是周%s\n", year, month, day, daysfrom111, weekcn[week]);

	return 0;
}

