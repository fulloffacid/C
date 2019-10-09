
#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>


int menu();
void vvod(int **a, int n1);
int vivod(int **a , int n1);
void find(int **a, int n1);
void stroka(char *s);

int main()
{
	int  n = 0, **a = NULL;
	char s1[20];
	char sym1;
	while (1)
	{
		switch (menu())
		{
		case 1:
			printf_s("Vvedite kol-vo strok i stolbcov kvadratnoi matrici\n");
			scanf_s("%d", &n);
			a = new int*[n];
			for (int i = 0;i < n;i++) {
				a[i] = new int[n];
			}
			vvod(a, n);
			break;

		case 2:
			find(a, n);
			break;
		case 3:
			vivod(a, n);
			break;
		case 4:
			printf("vvedite stroku: \n");
			gets_s(s1);
			stroka(s1);
			break;
		case 5: return 0;
		case 6: for (int i = 0;i < n;i++)
			delete[]a[i];
			delete[]a;
			break;
		}

	}
}

int menu()
{
	int c;
	do {
		printf_s("\n Menu\n");
		printf_s("1 Vvod massiva \n");
		printf_s("2 Zad 1\n");
		printf_s("3 Vivod massiva\n");
		printf_s("4 Zad 2\n");
		printf_s("5 Exit\n");
		printf_s("6 Pamiat'\n");
		printf_s("\t Vash vibor ");
		scanf_s("%d", &c);
	} while (c > 5);
	return c;
}

void vvod(int **a, int n1) {
	int i = 0, j = 0;
	
	/*if (a == NULL) {
		printf_s("Error");
		return;
	}*/
	for (i = 0;i < n1;i++)
		for (j = 0;j < n1;j++) {
			printf_s("Element [%d%d]\n", i + 1, j + 1);
			scanf_s("%d", (*(a + i) + j));
		}
	
}
int vivod(int **a, int n1)
{
	int i, j;
	printf_s("Matrica \n");

	for (i = 0;i < n1;i++) {
		for (j = 0;j < n1;j++)
			printf_s("%d ", *(*(a + i) + j));
		printf_s("\n");
	}
	return 0;
}
void find(int **a, int n1)
{
	int k = 0, i = 0, j = 0, p = -1;
	for (i = 0;i < n1;i++) {
		k = 0;
		for (j = 0;j < n1;j++) {
			if (*(*(a + i) + j) == 0) k++;
		}
		if (k == n1) { p = i;break; }
		k = 0;
	}
	for (j = 0;j < n1;j++) {
		a[j][p] /= 2;
	}
}
void stroka(char *s) {
	char s1[20];
	char sym1=0;
	int count = 0;
	fgets(s1, sizeof(s1) / sizeof(s1[0]), stdin);
	sym1 = fgetc(stdin);
	for (char *str = s1;*str;str++)
	{
		str = strchr(str, sym1);
		if (str && str != 0) { count++; }
		if (str == NULL) { break; }
	}
	printf("Kol-vo of '%c' = %d\n", sym1, count);
}


