//�ж�ĳ��ĳ�����ܼ�����׼�㣺��Ԫ1��1��1������һ��
#include<stdio.h>
int main()
{
	int i, j, year, month, day, daysfrom111, week, leap = 0;
	int moondays[] = { 0, 31, 28, 31, 30,31,30,31,31,30,31,30,31 };
	char weekcn[][3] = {"", "һ", "��", "��", "��", "��", "��", "��" };
	printf("�����������գ��磺2021 5 21����");
	scanf("%d%d%d", &year, &month, &day);
	daysfrom111 = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
	for (i = 1; i < month; i++)
		daysfrom111 += moondays[i];
	daysfrom111 += day;
	if (month>2 && ((year % 4 == 0) && year % 100 != 0 || year % 400 == 0))
		daysfrom111++;
	week = daysfrom111 % 7;
	week = week == 0 ? 7 : week;
	printf("%d��%d��%d�վ๫Ԫ1��1��1��%d�죬����%s\n", year, month, day, daysfrom111, weekcn[week]);

	return 0;
}

