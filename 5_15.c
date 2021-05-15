#include<stdio.h> 
#include<string.h>
int main()
{
	char chars[80], letterChars[80];
	char digitChars[80], otherChars[80];
	int letters = 0, digits = 0, others = 0, i;
	printf("ÇëÊäÈëÒ»´®×Ö·û£º\n");
	gets(chars);
	for (i = 0; chars[i] != '\0';i++)
	{
		if (chars[i] >= '0'&&chars[i] <= '9')
			digitChars[digits++] = chars[i];
		else if (chars[i] >= 'a'&&chars[i] <= 'z' || chars[i] >= 'A'&&chars[i] <= 'Z')
			letterChars[letters++] = chars[i];
		else
			otherChars[others++] = chars[i];
	}
	digitChars[digits] = chars[i];
	letterChars[letters] = chars[i];
	otherChars[others] = chars[i];
	printf("Êý×Ö×Ö·ûÓÐ£º¡¾%s¡¿\n", digitChars);
	printf("×ÖÄ¸×Ö·ûÓÐ£º¡¾%s¡¿\n", letterChars);
	printf("ÆäËü×Ö·ûÓÐ£º¡¾%s¡¿\n", otherChars);

	return 0;
}
