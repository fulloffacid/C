#include "pch.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int menu();
int sum(int aa, int bb);
void kol(char *s);

int main()
{
	int a, b, c = 0, k1 = 0;
	char s1[20];
	while (1)
	{
		switch (menu())
		{
		case 1:
			printf_s("vvedite a i b: ");
			scanf_s("%d%d", &a, &b);
			c = sum(a, b);
			printf("\nSum= %d\n", c);
			break;
		case 2:
			fflush(stdin);
			printf("vvedite ctroku: \n");
			gets_s(s1);
			kol(s1);
			break;
		case 3: return 0;
		}
	}
}

int menu()
{
	int ch;
	do {
		printf("\n   Menu: \n");
		printf("1. Podschitat' summu chisel:  \n");
		printf("2. Podschitat' kolichestvo simvolov v stroke:  \n");
		printf("3. Exit\n");
		printf("\t Vash vibor: ");
		scanf_s("%d", &ch);
	} while (ch > 3);
	return ch;
}
int sum(int aa, int bb) 
{
	return aa + bb;
}
void kol(char *s) 
{
	printf("Dlina=%d", strlen(s));

}
